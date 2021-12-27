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
const long long mod = 1000000007;
const int MAXN = 200000;

int n, m;
vector<vector<array<int, 2>>> adj, adj1;
vector<int> val;
bool pos;


void dfs(int v, int p, int cur, vector<array<int, 3>> &go){
    if (val[v] == -1) {
        val[v] = cur;
        for(auto c : adj[v]){
            if (c[0] == p) continue;
            if (c[1] == -1) continue;
            dfs(c[0], v, cur ^ c[1], go);
        }
        for(auto c : adj1[v]){
            go.pb({v, c[0], c[1]});
        }
    } else if (val[v] != cur) {
        pos = false;
    }
}

void dfs1(int v, int cur){
    vector<array<int, 3>> go;
    dfs(v, v, cur, go);
    for(auto it : go){
        if (val[it[1]] != -1){
            int dif = val[it[0]] ^ val[it[1]], cnt = 0;
            forn(i, 0, 31){
                if (dif & (1<<i)) cnt++;
            }
            if ((cnt&1) != it[2]) {
                pos = false;
            }
        } else {
            dfs1(it[1], val[it[0]] ^ it[2]);
        } 
    }
}

void solve(){
    cin >> n >> m;
    pos = true;
    adj.clear();
    adj1.clear();
    val.clear();
    adj.resize(n);
    adj1.resize(n);
    val.resize(n, -1);
    forn(i, 0, n-1){
        int a, b, v;
        cin >> a >> b >> v;
        adj[a-1].pb({b-1, v});
        adj[b-1].pb({a-1, v});
    }
    forn(i, 0, m){
        int a, b, p;
        cin >> a >> b >> p;
        adj1[a-1].pb({b-1, p});
        adj1[b-1].pb({a-1, p});
    }
    forn(i, 0, n){
        if (val[i] == -1) dfs1(i, i);
    }
    if (pos) {
        cout << "YES\n";
        forn(i, 0, n){
            for(auto it : adj[i]){
                if (it[0] > i){
                    cout << i + 1 << ' ' << it[0] + 1 << ' ' << (val[i] ^ val[it[0]]) << '\n';
                }
            }
        }
    } else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while (t--) solve();
}