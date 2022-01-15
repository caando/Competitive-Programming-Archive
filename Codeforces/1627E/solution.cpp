ECHO is on.
a#include<bits/stdc++.h>
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
const int MAXN = 1000000;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll cost[n];
    vector<vector<ll>> ladders[n];
    forn(i, 0, n) cin >> cost[i];
    forn(i, 0, k) {
        ll a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        a--, c--;
        ladders[a].pb({b, c, d, h});
    }
    vector<pair<ll, ll>> pos[n];
    pos[0].pb({1, 0});
    ll ans = INT64_MAX;
    
    forn(i, 0, n-1){

        if (pos[i].size() && ladders[i].size()){

            sort(pos[i].begin(), pos[i].end());
            sort(ladders[i].begin(), ladders[i].end());

            /*
            cout << i << ' ' << pos[i].size() << ' ' << ladders[i].size() << '\n';
            forn(j, 0, pos[i].size()){
                cout << pos[i][j].fi << ' ' << pos[i][j].se << '\n';
            }
            cout << '\n';
            */

            ll low[ladders[i].size()];
            forn(k, 0, ladders[i].size()) low[k] = INT64_MAX;
            ll j = 0, k = 0, cur, last = -1;

            while(k < ladders[i].size()) {
                if (j == pos[i].size()){
                    if (last != -1) {
                        cur += abs(last - ladders[i][k][0]) * cost[i];
                        last = ladders[i][k][0];
                        low[k] = min(low[k], cur);
                    }
                    k++;
                } else if (pos[i][j].fi <= ladders[i][k][0]){
                    if (last != -1) {
                        cur += abs(last - pos[i][j].fi) * cost[i];
                    } else cur = pos[i][j].se;
                    if (pos[i][j].se < cur) cur = pos[i][j].se;
                    last = pos[i][j].fi; 
                    j++;
                } else {
                    if (last != -1) {
                        cur += abs(last - ladders[i][k][0]) * cost[i];
                        last = ladders[i][k][0];
                        low[k] = min(low[k], cur);
                    }
                    k++;
                }
            }

            j = pos[i].size()-1, k = ladders[i].size()-1, last = -1;
            while(k >= 0) {
                if (j < 0){
                    if (last != -1) {
                        cur += abs(last - ladders[i][k][0]) * cost[i];
                        last = ladders[i][k][0];
                        low[k] = min(low[k], cur);
                    }
                    k--;
                } else if (pos[i][j].fi >= ladders[i][k][0]){
                    if (last != -1) {
                        cur += abs(last - pos[i][j].fi) * cost[i];
                    } else cur = pos[i][j].se;
                    if (pos[i][j].se < cur) cur = pos[i][j].se;
                    last = pos[i][j].fi; 
                    j--;
                } else {
                    if (last != -1) {
                        cur += abs(last - ladders[i][k][0]) * cost[i];
                        last = ladders[i][k][0];
                        low[k] = min(low[k], cur);
                    }
                    k--;
                }
            }

            forn(k, 0, ladders[i].size()) {
                pos[ladders[i][k][1]].pb(mp(ladders[i][k][2], low[k] - ladders[i][k][3]));
            }
        }
    }

    for(auto it : pos[n-1]) ans = min(ans, it.se + abs(m-it.fi) * cost[n-1]);
    if (ans == INT64_MAX) cout << "NO ESCAPE\n";
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}