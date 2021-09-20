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
const long long mod = 998244353;
const int MAXN = 1000005;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> digits, rev;
    ll add = 0;
    while(n != 0) digits.pb(n%10), n/=10;
    forn(i, 0, digits.size()) rev.pb(digits[digits.size() - i - 1]), add += digits[digits.size() - i - 1];
    for(int i = digits.size()-2; i >= 0; i--) {
        if (add < k && rev[i] && i < (int)digits.size()-1) {
            add += 9;
            rev[i+1] += 10;
            rev[i]--;
            i+=2;
        }
    }
    ll res[k];
    memset(res, 0, sizeof res);
    ll curr = 0;
    forn(i, 0, rev.size()){
        forn(j, curr, k){
            if (j == k-1){
                res[j] += rev[i] * pow(10, digits.size() - i - 1);
            } else if (rev[i] > 0){
                rev[i]--;
                res[j] += pow(10, digits.size() - i - 1);
                curr = j+1;
            } 
        }
    }
    forn(i, 0, k) cout << res[i] << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}