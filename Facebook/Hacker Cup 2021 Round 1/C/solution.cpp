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
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 800005;

vector<vector<pair<ll, ll>>> adj;
vector<vector<ll>> dp;
ll s, ans;

void dfs(int v, int p){
    dp[v][21] = 1;
    for(pair<ll, ll> e : adj[v]){
        if (e.fi != p){
            dfs(e.fi, v);
            for(ll i = 21; i >= 0; i--){
                for(ll j = 21; j >= 0; j--){
                    s += min(e.se, min(i, j)) * dp[v][j] * dp[e.fi][i];
                    s %= mod;
                }
            }
            forn(i, 0, 22){
                dp[v][min(e.se, (ll)i)] += dp[e.fi][(ll)i];
            }
        }
    }
}

void dfs1(int v, int p){
    for(pair<ll, ll> e : adj[v]){
        if (p != e.fi){
            vector<ll> temp = dp[v];
            for(ll i = 21; i >= 0; i--){
                temp[min(e.se, i)] -= dp[e.fi][i];
            }
            ll cur = 0;
            for(ll i = 21; i >= 0; i--){
                for(ll j = 21; j >= 0; j--){
                    cur += min(e.se, min(i, j)) * temp[j] * dp[e.fi][i];
                    cur %= mod;
                }
            }
            ans *= (s - cur + mod) % mod;
            ans %= mod;
            for(ll i = 21; i >= 0; i--){
                dp[e.fi][min(e.se, i)] += temp[i];
            }
        }
    }
    for(pair<ll, ll> e : adj[v]){
        if (p != e.fi){
            dfs1(e.fi, v);
        }
    }
}

void solve(int T){
    cout << "Case #" << T + 1 << ": ";
    int n;
    cin >> n;
    s = 0, ans = 1;
    adj = vector<vector<pair<ll, ll>>>(n); 
    dp = vector<vector<ll>>(n, vector<ll>(22, 0));
    forn(i, 0, n-1){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].pb(mp(b-1, c));
        adj[b-1].pb(mp(a-1, c));
    }
    dfs(0, -1);
    dfs1(0, -1);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}