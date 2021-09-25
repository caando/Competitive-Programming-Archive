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
vector<int> f;

void solve(int T){
    cout << "Case #" << T+1 << ": ";
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n, vector<char>(m));
    forn(i, 0, n){
        forn(j, 0, m) cin >> g[i][j];
    }
    vector<vector<int>> uf(n, vector<int>(m, 0)), df(n, vector<int>(m, 0)), ut(n+1, vector<int>(m, 0)), dt(n+1, vector<int>(m, 0));
    forn(i, 0, n){
        forn(j, 0, m){
            if (i != 0) uf[i][j] = uf[i-1][j];
            if (g[i][j] == '.') uf[i][j]++;
        }
    }
    for(int i = n-1; i >= 0; i--){
        forn(j, 0, m){
            if (i != n-1) df[i][j] = df[i+1][j];
            if (g[i][j] == '.') df[i][j]++;
        }
    }
    forn(i, 0, n){
        forn(j, 0, m){
            if (i != 0) ut[i][j] = ut[i-1][j];
            if (g[i][j] == 'X') ut[i][j]++;
        }
    }
    for(int i = n-1; i >= 0; i--){
        forn(j, 0, m){
            if (i != n-1) dt[i][j] = dt[i+1][j];
            if (g[i][j] == 'X') dt[i][j]++;
        }
    }
    int ans = 0;
    forn(j, 0, m) if (g[k-1][j] == 'X') ans++;
    forn(i, 1, k){
        int count = 0;
        forn(j, 0, m){
            int d = 0, e = 0;
            if (k-2 >= 0) d = uf[k-2][j];
            if (k-1+i < n) e = dt[k-1+i][j];
            if (d < dt[k-1][j] - e) count++;
            else if (k+i <= n){
                if (g[k-1+i][j] == 'X') count++;
            }
        }
        if (count +i< ans) ans = count + i;
    }
    
    forn(i, 1, n-k+1){
        int count = 0;
        forn(j, 0, m){
            int d = 0, e = 0;
            if (k < n) d = df[k][j];
            if (k-1-i >= 0) e = ut[k-1-i][j];
            if (d < ut[k-1][j] - e) count++;
            else if (k-i > 0){
                if (g[k-1-i][j] == 'X') count++;
            }
        }
        if (count + i < ans) ans = count + i;
    }
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}