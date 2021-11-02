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
const long long mod = 998244353;
const int MAXN = 200000;

ll n, m;
vector<vector<char>> g;
vector<vector<int>> dp;
int c, x, y;
pair<int, int> dfs(){
    if (dp[x][y] < 0) {
        dp[x][y] = c - dp[x][y];
        return mp(x, y);
    } else if (dp[x][y]) return mp(-1,-1);
    dp[x][y] = c;
    c++;
    if (g[x][y] == 'U'){
        if (x == 0){
            dp[x][y] = 1;
            return mp(-1,-1);
        } else {
            x--;
            pair<int, int> res = dfs();
            x++;
            if (res != mp(-1, -1)){
                dp[x][y] = dp[x-1][y];
                if (x == res.fi && y == res.se) return mp(-1, -1);
                else return res;
            } else {
                dp[x][y] = dp[x-1][y]+1;
                return mp(-1,-1);
            }
        }
    } else if (g[x][y] == 'D'){
        if (x == n-1){
            dp[x][y] = 1;
            return mp(-1,-1);
        } else {
            x++;
            pair<int, int> res = dfs();
            x--;
            if (res != mp(-1, -1)){
                dp[x][y] = dp[x+1][y];
                if (x == res.fi && y == res.se) return mp(-1, -1);
                else return res;
            } else {
                dp[x][y] = dp[x+1][y]+1;
                return mp(-1,-1);
            }
        }
    } else if (g[x][y] == 'L'){
        if (y == 0){
            dp[x][y] = 1;
            return mp(-1,-1);
        } else {
            y--;
            pair<int, int> res = dfs();
            y++;
            if (res != mp(-1, -1)){
                dp[x][y] = dp[x][y-1];
                if (x == res.fi && y == res.se) return mp(-1, -1);
                else return res;
            } else {
                dp[x][y] = dp[x][y-1]+1;
                return mp(-1,-1);
            }
        }
    } else if (g[x][y] == 'R'){
        if (y == m-1){
            dp[x][y] = 1;
            return mp(-1,-1);
        } else {
            y++;
            pair<int, int> res = dfs();
            y--;
            if (res != mp(-1, -1)){
                dp[x][y] = dp[x][y+1];
                if (x == res.fi && y == res.se) return mp(-1, -1);
                else return res;
            } else {
                dp[x][y] = dp[x][y+1]+1;
                return mp(-1,-1);
            }
        }
    }
    c--;
    return mp(-1,-1);
}

void solve(){
    cin >> n >> m;
    g = vector<vector<char>>(n, vector<char>(m));
    dp = vector<vector<int>>(n, vector<int>(m, 0));
    forn(i, 0, n){
        forn(j, 0, m) cin >> g[i][j];
    }
    forn(i, 0, n){
        forn(j, 0, m) {
            c = INT_MIN, x= i, y=j;
            dfs();
        }
    }
    int high = 0, x = 0, y = 0;
    forn(i, 0, n){
        forn(j, 0, m) if (dp[i][j] > high) high = dp[i][j], x = i+1, y= j+1;
    }
    cout << x << ' ' << y << ' ' << high << '\n';
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}