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

char g[8][8];

int dfs(int c){
    if (c == 8) return 1;
    int cnt = 0;
    forn(j, 0, 8){
        if (g[c][j] == '.'){
            bool p = true;
            forn(k, 0, 8) {
                if (g[k][j] == 'q') p = false;
            }
            forn(k, 0, 8) {
                if (k > c || k > j) break;
                if (g[c-k][j-k] == 'q') p = false;
            }
            forn(k, 0, 8) {
                if (k > c || k + j > 7) break;
                if (g[c-k][j+k] == 'q') p = false;
            }
            forn(k, 0, 8) {
                if (k + c > 7 || k + j > 7) break;
                if (g[c+k][j+k] == 'q') p = false;
            }
            forn(k, 0, 8) {
                if (k + c > 7 || k > j) break;
                if (g[c+k][j-k] == 'q') p = false;
            }
            if (p) {
                g[c][j] = 'q';
                cnt += dfs(c+1);
                g[c][j] = '.';
            }
        }
    }
    return cnt;
}

void solve(){
    forn(i, 0, 8){
        forn(j, 0, 8) cin >> g[i][j];
    }
    cout << dfs(0);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}