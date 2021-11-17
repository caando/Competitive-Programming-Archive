#include<bits/stdc++.h>
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
const long long mod = 998244353;
const int MAXN = 200000;


void solve(int t){
    cout << "Case #" << t + 1 << ": ";
    int n;
    cin >> n;
    char arr[n];
    int counter = 0;
    bool r=false, b=false, y=false;
    forn(i, 0, n) {
        cin >> arr[i];
        if (arr[i] == 'U'){
            r = false, b = false, y = false;
        }
        if(arr[i] == 'Y'){
            if (y == false) y = true, counter++;
            r = false, b = false;
        }
        if(arr[i] == 'R'){
            if (r == false) r = true, counter++;
            y = false, b = false;
        }
        if(arr[i] == 'B'){
            if (b == false) b = true, counter++;
            r = false, y = false;
        }
        if(arr[i] == 'O'){
            if (r == false) r = true, counter++;
            if (y == false) y = true, counter++;
            b= false;
        }
        if(arr[i] == 'P'){
            if (b == false) b = true, counter++;
            if (r == false) r = true, counter++;
            y = false;
        }
        if(arr[i] == 'G'){
            if (b == false) b = true, counter++;
            if (y == false) y = true, counter++;
            r = false;
        }
        if(arr[i] == 'A'){
            if (b == false) b = true, counter++;
            if (r == false) r = true, counter++;
            if (y == false) y = true, counter++;
        }
    }
    cout << counter << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}