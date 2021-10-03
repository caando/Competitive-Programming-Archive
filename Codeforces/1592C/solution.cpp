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

vector<int> arr;
vector<vector<int>> adj;
int n, k, cnt, t;
bool pos;

vector<pair<int, int>> z, b;
set<pair<int, int>> store;

int dfs(int v, int p){
    b[v].fi = cnt;
    cnt++;
    int cur = arr[v];
    for(int c : adj[v]){
        if (c != p){
            cur ^= dfs(c, v);
        }
    }
    b[v].se = cnt;
    if (cur == 0) {
        store.insert(mp(b[v].se, b[v].fi));
        z.pb(b[v]);
    } else if (cur == t){
        z.pb(b[v]);
    }
    cnt++;
    return cur;
}

void solve(){
    cnt = 0;
    cin >> n >> k;
    t = 0;
    arr = vector<int>(n);
    store.clear();
    z.clear();
    adj = vector<vector<int>>(n);
    b = vector<pair<int, int>>(n);
    forn(i, 0, n) cin >> arr[i], t ^= arr[i];
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    pos = false;
    dfs(0, 0);
    if (t == 0) pos = true;
    else if (k > 2){
        forn(i, 0, sz(z)){
            auto it = store.lower_bound(z[i]);
            if (it != store.end()){
                if ((*it).se <= z[i].se) pos = true;
            }
        }
        auto curr = z[0];
        forn(i, 1, sz(z)){
            if (z[i].fi > curr.se) pos = true;
        }
    }
    cout << (pos ? "Yes\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--)solve();
}
