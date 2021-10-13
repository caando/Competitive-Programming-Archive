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
const int MAXN = 100005;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    bool dp[n+1][a][b][n+1];
    pair<pair<int, int>, int> backtrack[n+1][a][b][n+1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = true;
    forn(i, 0, n) {
        int num = s[i] - '0';
        forn(j, 0, a){
            forn(k, 0, b){
                forn(l, 0, n+1){
                    if (dp[i][j][k][l]){
                        dp[i+1][(j*10+num)%a][k][l+1] = true;
                        dp[i+1][j][(k*10+num)%b][l] = true;
                        backtrack[i+1][(j*10+num)%a][k][l+1] = mp(mp(j, k), l);
                        backtrack[i+1][j][(k*10+num)%b][l] = mp(mp(j, k), l);
                    }
                }
            }
        }
    }
    int cur = -1, low = INT_MAX;
    forn(i, 1, n){
        if (dp[n][0][0][i]) {
            if (abs(i - n/2) < low) cur = i, low = abs(i - n/2);
            if (abs(i - n/2-(n&1)) < low) cur = i, low = abs(i - n/2-(n&1));
        }
    }
    string ans = s;
    if (cur == -1) cout << -1 << '\n';
    else {
        int A = 0, B = 0;
        for(int i = n-1; i >= 0; i--){
            int ca = A, cb = B;
            if (cur != backtrack[i+1][ca][cb][cur].se) ans[i]='R';
            else ans[i] = 'B';
            A = backtrack[i+1][ca][cb][cur].fi.fi;
            B = backtrack[i+1][ca][cb][cur].fi.se;
            cur = backtrack[i+1][ca][cb][cur].se;
        }
        cout << ans << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}