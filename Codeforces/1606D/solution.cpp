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


void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cols[m], rows[n];
    forn(i, 0, n){
        forn(j, 0, m){
            int temp;
            cin >> temp;
            rows[i].pb(mp(temp, i));
        }
    }
    sort(rows, rows+n);
    int tl[n][m], tr[n][m], bl[n][m], br[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tl[i][j] = rows[i][j].fi;
            if (i > 0) tl[i][j] = max(tl[i][j], tl[i-1][j]);
            if (j > 0) tl[i][j] = max(tl[i][j], tl[i][j-1]);
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            br[i][j] = rows[i][j].fi;
            if (i < n-1) br[i][j] = max(br[i][j], br[i+1][j]);
            if (j < m-1) br[i][j] = max(br[i][j], br[i][j+1]);
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            bl[i][j] = rows[i][j].fi;
            if (i < n-1) bl[i][j] = min(bl[i][j], bl[i+1][j]);
            if (j > 0) bl[i][j] = min(bl[i][j], bl[i][j-1]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = m-1; j >= 0; j--){
            tr[i][j] = rows[i][j].fi;
            if (i > 0) tr[i][j] = min(tr[i][j], tr[i-1][j]);
            if (j < m-1) tr[i][j] = min(tr[i][j], tr[i][j+1]);
        }
    }
    int x = -1, y = -1;
    forn(i, 0, n-1){
        forn(j, 0, m-1){
            int TL = tl[i][j];
            int BL = bl[i+1][j];
            int TR = tr[i][j+1];
            int BR = br[i+1][j+1];
            if (TL < BL && TR > BR){
                x = i, y = j;
                break;
            }
        }
    }
    if (x >= 0 && y >= 0){
        cout << "YES\n";
        char c[n];
        forn(i, 0, x+1) c[rows[i][0].se] = 'B';
        forn(i, x+1, n) c[rows[i][0].se] = 'R';
        forn(i, 0, n) cout << c[i];
        cout << ' ';
        cout << y + 1 << '\n';
    } else cout <<"NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}