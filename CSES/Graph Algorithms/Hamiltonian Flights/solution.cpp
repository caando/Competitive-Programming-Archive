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
    int n, m;
    cin >> n >> m;
    int e[n][n];
    memset(e, 0, sizeof e);
    forn(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a][b]++;
    }
    ll dp[1<<n][n];
    memset(dp, 0, sizeof dp);
    dp[1][0] = 1;
    int i, w, j, v, k;
    for(i = 1; i < (1<<n); i = ((i+1) | 1)){
        for(w=i;w;w&=(w-1)){
            j = ffs(w)-1;
            for(v=((1<<n)-1)^i;v;v&=(v-1)){
                k = ffs(v)-1;
                dp[i|(1<<k)][k] += dp[i][j] * e[j][k];
                dp[i|(1<<k)][k] %= mod;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1];
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}