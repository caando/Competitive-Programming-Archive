#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

void solve(int T){
    cout << "Case #" << T << ": ";
    int n;
    cin >> n;
    string s;
    cin >> s;
    char prev = 'F', first = 'F';
    ll index_prev= 0, l = 0, index_first = 0, x = 0, y = 0, count = 0, cnt = 0;
    forn(i, 0, n){
        if (s[i] == '.'){
            count *= 2;
            count %= mod;
            count += x * l;
            count %= mod;
            count += y * l;
            count %= mod;
            x *= 2;
            x %= mod;
            y *= 2;
            y %= mod;
            x += l * cnt;
            x %= mod;
            y += l * cnt;
            y %= mod;
            cnt *= 2;
            cnt %= mod;
            if ((first == 'O' && prev == 'X') || (first =='X' && prev == 'O')){
                x += index_prev+1;
                x %= mod;
                ll temp = l - index_first;
                if (temp < 0) temp += mod;
                y += temp;
                y %= mod;
                count += (index_prev+1) * (temp);
                count %= mod;
                cnt++;
                cnt %= mod;
            } 
            index_prev += l;
            l *= 2;
            l %= mod;
        } else {
            if (s[i] == 'X'){
                if (first == 'F') index_first = l, first = 'X';
                if (prev == 'O'){
                    x+=index_prev+1;
                    x %= mod;
                    cnt++;
                    cnt %= mod;
                }
                index_prev = l;
                prev = 'X';
            } else if (s[i] == 'O'){
                if (first == 'F') index_first = l, first = 'O';
                if (prev == 'X'){
                    x+=index_prev+1;
                    x %= mod;
                    cnt++;
                    cnt %= mod;
                }
                index_prev = l;
                prev = 'O';
            }
            l++;
            l %= mod;
            y += cnt;
            y %= mod;
            count += x;
            count %= mod;
        }
        count %= mod;
        l %= mod;
        x %= mod;
        y %= mod;
        index_prev %= mod;
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 1, t+1) solve(T);
}