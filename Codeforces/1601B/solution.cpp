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

void solve(){
    ll n;
    cin >> n;
    ll dp[n+1];
    int a[n+1], b[n+1];
    forn(i, 0, n) cin >> a[i+1];
    forn(i, 0, n) cin >> b[i+1];
    forn(i, 0, n) dp[i]=INT_MAX;
    queue<pair<int, pair<int, int>>> q;
    int backtrack[n+1];
    q.push(mp(n, mp(0, n)));
    while(!q.empty()){
        int v = q.front().fi, c = q.front().se.fi, o = q.front().se.se;
        q.pop();
        backtrack[v] = o;
        if (v == 0) break;
        int p = v;
        v += b[v];
        for(int i = min(a[v], v); i > 0; i--){
            if (dp[v-i] == INT_MAX){
                dp[v-i] = c+1;
                q.push(mp(v-i, mp(c+1, p)));
            } else break;
        }
    }
    if (dp[0] == INT_MAX) cout << -1;
    else {
        cout << dp[0] << '\n';
        vector<int> v;
        int cur = 0;
        while(backtrack[cur] != cur){
            v.pb(cur);
            cur = backtrack[cur];
        }
        for(int i = v.size()-1; i >= 0; i--) cout << v[i] << ' ';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}