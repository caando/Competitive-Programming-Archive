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
const int MAXN = 1003;

void solve(){
    int n, m;
    cin >> n >> m;
    char dp[n+2][m+2], g[n+2][m+2];
    forn(i, 0, n+2) forn(j, 0, m+2) g[i][j] = '#';
    memset(dp, 0, sizeof dp);
    int x, y;
    queue<pair<int, int>> q;
    forn(i, 1, n+1) forn(j, 1, m+1) {
        cin >> g[i][j];
        if (g[i][j] == 'A') q.push(mp(i, j)), dp[i][j] = 1;
        if (g[i][j] == 'B') x = i, y = j;
    }
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if (g[x-1][y] != '#' && dp[x-1][y] == 0){
            dp[x-1][y] = 'U';
            q.push(mp(x-1, y));
        }
        if (g[x+1][y] != '#' && dp[x+1][y] == 0){
            dp[x+1][y] = 'D';
            q.push(mp(x+1, y));
        }
        if (g[x][y-1] != '#' && dp[x][y-1] == 0){
            dp[x][y-1] = 'L';
            q.push(mp(x, y-1));
        }
        if (g[x][y+1] != '#' && dp[x][y+1] == 0){
            dp[x][y+1] = 'R';
            q.push(mp(x, y+1));
        }
    }
    
    if (dp[x][y] == 0) cout << "NO";
    else {
        cout << "YES\n";
        vector<char> b;
        while(g[x][y] != 'A'){
            b.pb(dp[x][y]);
            if (dp[x][y] == 'U') x++;
            else if (dp[x][y] == 'D') x--;
            else if (dp[x][y] == 'L') y++;
            else if (dp[x][y] == 'R') y--;
        }
        cout << sz(b) << '\n';
        for(auto c = b.rbegin(); c != b.rend(); ++c){
            cout << (*c);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}