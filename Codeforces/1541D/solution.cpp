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

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<int> sieve;
void calc_sieve(int n){
    sieve.reserve(n+1);
    forn(i, 0, n+1) sieve[i] = i;
    forn(i, 2, n+1){
        if (sieve[i] == i){
            forn(j, 2, n/i+1){
                if (sieve[i*j] == i*j) sieve[i*j] = i;
            }
        }
    }
}

ll norm(ll a, ll P) {
    while (a >= P) a -= P;
    while (a < 0) a += P;
    return a;
}

ll mul_mod(ll a, ll b, ll P) {
    return a * b % P;
}

ll pow_mod(ll a, ll b, ll P){
    ll curr = a, ans = 1;
    while(b != 0){
        if (b&1) {
            ans *= curr;
            ans%=P;
        }
        curr *= curr;
        curr %= P;
        b >>= 1;
    }
    return ans;
}

ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}

ll div_mod(ll a, ll b, ll P) {
    return a * inv_mod(b, P) % P;
}

int msb(ll a){ 
    for(int i = 62; i >= 0; i--){
        if (a & ((ll)1 << i)) return i + 1;
    }
    return 0;
}

vector<ll> fact;
void calc_fact(int n, ll P){
    if (fact.size() < 1) fact.pb(1);
    forn(i, fact.size(), n+1) fact.pb(fact[i-1] * i  % P);
}

vector<ll> fact_inv;
void calc_fact_inv(int n, ll P){
    if (fact_inv.size() < 1) fact_inv.pb(1);
    forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * inv_mod(i, P) % P);
}

ll nCr(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact[n] * fact_inv[r] % P) * fact_inv[n-r] % P;
}

ll nCr_inv(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact_inv[n] * fact[r] % P) * fact[n-r] % P;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mod = 1000000007;

vector<vector<ll>> adj, lca;
vector<ll> dist;
ll n;

void dfs(int curr, int p){
    if (p != -1){
        forn(j, 0, n){
            if (lca[curr][j] == -1){
                lca[curr][j] = lca[p][j];
                lca[j][curr] = lca[j][p];
            }
        }
    }
    for (int i : adj[curr]) {
        for(int j : adj[curr]) {
            if (i != p && j != i && j != p) {
                lca[i][j] = curr;
                lca[j][i] = curr;
            }
        }
    }
    for (int i : adj[curr]) if (i != p) {
        dfs(i, curr);
    }
}

void dfs1(int curr, int p, int depth){
    dist[curr] = depth;
    for(int i : adj[curr]){
        if (i != p){
            dfs1(i, curr, depth+1);
        }
    }
}

void solve(){
    cin >> n;
    ll dp[n+1][n+1];
    dp[0][0]=1;
    for (int i=1; i<=n; i++){
        dp[i][0]=1;
        dp[0][i]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])*((mod+1)/2)%mod;
    }
    adj = vector<vector<ll>>(n);
    lca = vector<vector<ll>>(n, vector<ll>(n));
    dist = vector<ll>(n);
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    
    ll ans = 0;
    forn(i, 0, n){
        forn(j, 0, n) forn(k, 0, n) lca[j][k] = -1;
        forn(j, 0, n) lca[j][j] = j, dist[j] = 0;
        dfs(i, -1);
        dfs1(i, -1, 0);
        forn(j, 0, n){
            forn(k, 0, n){
                if (j > k){
                    if (lca[j][k] == j) ans++;
                    else if (lca[j][k] != k){
                        int a = dist[k] - dist[lca[k][j]], b = dist[j] - dist[lca[j][k]];
                        ans += dp[a][b] % mod;
                        ans %= mod;
                    }
                }
            }
        }
    }
    cout << ans* inv_mod(n, mod) % mod << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}