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

vector<ll> fact;
void calc_fact(ll n, ll P){
    if (fact.size() < 1) fact.pb(1);
    forn(i, fact.size(), n+1) fact.pb(fact[i-1] * i  % P);
}

vector<ll> fact_inv;
void calc_fact_inv(ll n, ll P){
    if (fact_inv.size() < 1) fact_inv.pb(1);
    forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * inv_mod(i, P) % P);
}

ll nCr(ll n, ll r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact[n] * fact_inv[r] % P) * fact_inv[n-r] % P;
}

void solve(){
    ll n, x;
    cin >> n >> x;
    ll dp[n+1][x+1];
    memset(dp, 0, sizeof dp);
    ll p[501][501];
    memset(p, 0, sizeof p);
    forn(i, 1, 501){
        p[i][0] = 1;
        forn(j, 1, 501){
            p[i][j] = p[i][j-1] * i % mod;
        }
    }

    forn(i, 0, x+1) dp[0][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if (j < i) dp[i][j] = p[j][i];
            else {
                forn(k, 0, i+1){
                    dp[i][j] += p[i-1][k] * nCr(i, k, mod) % mod * dp[i-k][j+1-i] % mod;
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << dp[n][x] << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}