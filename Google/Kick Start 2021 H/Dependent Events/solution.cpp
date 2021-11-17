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
const long long mod = 1e9+7;
const int MAXN = 200000;

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

vector<vector<int>> adj;
vector<vector<pair<int, pair<ll, ll>>>> p;
vector<ll> c;
vector<pair<int, int>> t;
int cnt = 0;

void dfs(int v){
    t[v].fi = cnt++;
    if (v != 0){
        c[v] = c[p[v][0].fi] * p[v][0].se.fi % mod + (1 - c[p[v][0].fi] + mod) * p[v][0].se.se % mod;
        c[v] %= mod;
    }
    forn(i, 1, 25){
        p[v][i].se.fi = p[p[v][i-1].fi][i-1].se.fi * p[v][i-1].se.fi % mod;
        p[v][i].se.fi += (1 - p[p[v][i-1].fi][i-1].se.fi + mod) * p[v][i-1].se.se % mod;
        p[v][i].se.fi %= mod;
        p[v][i].se.se = p[p[v][i-1].fi][i-1].se.se * p[v][i-1].se.fi % mod;
        p[v][i].se.se += (1 - p[p[v][i-1].fi][i-1].se.se + mod) * p[v][i-1].se.se % mod;
        p[v][i].se.se %= mod;
        p[v][i].fi = p[p[v][i-1].fi][i-1].fi;
    }
    for(int c : adj[v]){
        dfs(c);
    }
    t[v].se = cnt++;
}

bool is_ancestor(int u, int v) {
    return t[u].fi <= t[v].fi && t[u].se >= t[v].se;
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = 24; i >= 0; --i) {
        if (!is_ancestor(p[u][i].fi, v))
            u = p[u][i].fi;
    }
    return p[u][0].fi;
}

pair<ll, ll> tv(int u, int v){
    ll a = 1, b = 0;
    for (int i = 24; i >= 0; --i) {
        if (is_ancestor(u, p[v][i].fi) && p[v][i].fi != v){
            int c = a * p[v][i].se.fi % mod;
            c += b * (1 - p[v][i].se.fi + mod) % mod;
            c %= mod;
            int d = a * p[v][i].se.se % mod;
            d += b * (1 - p[v][i].se.se + mod) % mod;
            d %= mod;
            a = c, b = d;
            v = p[v][i].fi;
        }
    }
    return mp(a, b);
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    adj = vector<vector<int>>(n);
    p = vector<vector<pair<int, pair<ll, ll>>>>(n, vector<pair<int, pair<ll, ll>>>(25));
    forn(i, 0, n){
        forn(j, 0, 25){
            p[i][j].fi = i;
            p[i][j].se = mp(1, 0);
        }
    }
    c = vector<ll>(n);
    t = vector<pair<int, int>>(n);
    cin >> c[0];
    c[0] = c[0] * inv_mod(1000000, mod) % mod;
    forn(i, 1, n){
        cin >> p[i][0].fi >> p[i][0].se.fi >> p[i][0].se.se;
        p[i][0].fi--;
        p[i][0].se.fi = p[i][0].se.fi * inv_mod(1000000, mod) % mod;
        p[i][0].se.se = p[i][0].se.se * inv_mod(1000000, mod) % mod;
        adj[p[i][0].fi].pb(i);
    }
    dfs(0);
    cout << "Case #" << T << ": ";
    forn(i, 0, q){
        int x, y, LCA;
        cin >> x >> y;
        x--, y--;
        LCA = lca(x, y);
        ll t = tv(LCA, x).fi * tv(LCA, y).fi % mod * c[LCA] % mod;
        ll f = tv(LCA, x).se * tv(LCA, y).se % mod * (1 - c[LCA] + mod) % mod;
        cout << (t + f) % mod << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T+1);
}
