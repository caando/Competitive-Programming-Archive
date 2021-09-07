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
const int MAXN = 200005;

ll n, k;
vector<vector<pair<ll, ll>>> dp;
vector<vector<int>> adjlist;
vector<ll> gold;

void dfs(int p, int node){
    for(int c : adjlist[node]){
        if (c != p) dfs(node, c);
    }

    pair<ll, ll> dp1[2*k+1], prev[2*k+1];
    dp1[0].fi = 0, dp1[0].se = 0, prev[0].fi = 0, prev[0].se = 0;
    forn(i, 1, 2*k+1) dp1[i].fi = 0, dp1[i].se = gold[node];
    forn(i, 1, 2*k+1) prev[i].fi = 0, prev[i].se = gold[node];
    ll max_out = 2*k+1;
    if (node == 0) max_out = 2*k; // must include root
    forn(i, 0, adjlist[node].size()){
        if(adjlist[node][i] == p) continue;
        forn(j, 1, max_out) {
            forn(l, j, 2*k+1){
                if (j & 1){
                    dp1[l].fi = max(dp1[l].fi, prev[l-j].fi + dp[adjlist[node][i]][j/2].se);
                    dp1[l].se = max(dp1[l].se, prev[l-j].fi + dp[adjlist[node][i]][j/2].se + gold[node]);
                    dp1[l].se = max(dp1[l].se, prev[l-j].se + dp[adjlist[node][i]][j/2].se);
                } else {
                    dp1[l].fi = max(dp1[l].fi, prev[l-j].fi + dp[adjlist[node][i]][j/2].fi);
                    dp1[l].se = max(dp1[l].se, prev[l-j].se + dp[adjlist[node][i]][j/2].fi);
                }
            }
        }
        forn(j, 0, 2*k+1) prev[j] = dp1[j];
    }
    ll h1=0, h2=0;
    forn(i, 0, 2*k+1) {
        if (dp1[i].fi > h1) h1 = dp1[i].fi;
        if (dp1[i].se > h2) h2 = dp1[i].se;
        if (i & 1) dp[node][i/2].se = max(h1, h2);
        else dp[node][i/2].fi = max(h1, h2);
    }

}

void solve(int T){
    cout << "Case #" << T + 1 << ": ";
    cin >> n >> k;
    adjlist = vector<vector<int>>(n, vector<int>(0));
    gold = vector<ll>(n);
    dp = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(k+1, mp(0, 0)));
    forn(i, 0, n) cin >> gold[i];
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adjlist[a-1].pb(b-1);
        adjlist[b-1].pb(a-1);
    }
    dfs(-1, 0);
    cout << max(dp[0][k].fi, gold[0]) << endl; // no path == only root
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}