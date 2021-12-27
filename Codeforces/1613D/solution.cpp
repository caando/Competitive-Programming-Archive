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
const int MAXN = 500000;

void solve(){
    ll n;
    cin >> n;
    ll dp[n+10][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    ll ans = 0;
    forn(i, 0, n){
        int temp;
        cin >> temp;
        if (temp > 0) {
            ans += dp[temp-1][0] + dp[temp-1][1], dp[temp-1][1] += dp[temp-1][0] + dp[temp-1][1];
        }
        ans += dp[temp+1][0] + dp[temp][0] + dp[temp+1][1];
        dp[temp+1][0] += dp[temp+1][0];
        dp[temp+1][0] += dp[temp][0];
        dp[temp+1][1] += dp[temp+1][1];
        dp[temp-1][0] %= mod;
        dp[temp-1][1] %= mod;
        dp[temp][0] %= mod;
        dp[temp][1] %= mod;
        dp[temp+1][0] %= mod;
        dp[temp+1][1] %= mod;
        ans %= mod;
    }
    cout << ans << '\n';


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--)solve();
}