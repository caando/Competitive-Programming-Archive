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

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<int> adj[n];
    int f[k];
    forn(i, 0, k) cin >> f[i], f[i]--;
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }


    int dp[n], dp1[n];
    memset(dp, 0, sizeof dp);
    memset(dp1, 0, sizeof dp1);
    queue<pair<int, int>> q;
    forn(i, 0, k) q.push(mp(f[i], 1));
    while(!q.empty()){
        int x = q.front().fi, c = q.front().se;
        q.pop();
        if (!dp1[x]){
            dp1[x] = c;
            for(int v : adj[x]){
                if (!dp1[v]){
                    q.push(mp(v, c+1));
                }
            }
        }
    }
    q.push(mp(0, 1));
    int cnt = 0;
    bool pos = true;
    while(!q.empty()){
        int x = q.front().fi, c = q.front().se;
        q.pop();
        if (!dp[x]){
            if (dp1[x] <= c){
                cnt++;
            } else {
                dp[x] = c;
                if (sz(adj[x]) == 1 && x != 0) pos = false;
                for(int v : adj[x]){
                    if (!dp[v]){
                        q.push(mp(v, c+1));
                    }
                }
            }
        }
    }
    if(pos) cout << cnt << '\n';
    else cout << -1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--)solve();
}