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

vector<vector<int>> adj;
vector<int> parent;
vector<pair<int, int>> b; 
int cnt;

void dfs(int v, int p){
    b[v].fi = cnt;
    cnt++;
    for(int c : adj[v]){
        if (c != p){
            parent[c] = v;
            dfs(c, v);
        }
    }
    cnt++;
    b[v].se = cnt;
}

void solve(int T){
    cout << "Case #" << T+1 << ": ";
    ll n;
    cin >> n;
    cnt = 0;
    adj = vector<vector<int>> (n);
    vector<int> f = vector<int> (n), ufds = vector<int> (n), rank = vector<int> (n), sub = vector<int> (n);
    parent = vector<int> (n);
    parent[0] = 0;
    b = vector<pair<int, int>> (n);
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    forn(i, 0, n) cin >> f[i], ufds[i] = i, rank[i] = 0, sub[i] = i;
    dfs(0, -1);
    vector<pair<int, int>> M(n+1, mp(INT_MAX, INT_MIN));
    forn(i, 0, n) {
        if (b[i].fi < M[f[i]].fi) M[f[i]].fi = b[i].fi;
        if (b[i].se > M[f[i]].se) M[f[i]].se = b[i].se;
    }
    forn(i, 0, n){
        int curr = i;
        while(ufds[curr] != curr) curr = ufds[curr];
        while(b[sub[curr]].fi > M[f[i]].fi || b[sub[curr]].se < M[f[i]].se){
            int p = parent[sub[curr]];
            while (ufds[p] != p) p = ufds[p];
            if (rank[p] >= rank[curr]) {
                ufds[curr] = p;
                if (rank[curr] == rank[p]) rank[p]++;
                curr = p;
            } else {
                ufds[p] = curr;
                sub[curr] = sub[p];
            }
        }
    }
    int count = 0;
    forn(i, 0, n) if (ufds[i] == i) count++;
    cout << count - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}