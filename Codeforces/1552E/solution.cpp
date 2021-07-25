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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 100000;

void solve(){
    int n, k;
    cin >> n >> k;
    int g = n/(k-1) + (int)(n%(k-1)>0);
    int arr[k*n];
    forn(i, 0, k*n) cin >> arr[i], arr[i]--;
    pair<int, int> next[k*n];
    int dp[n];
    forn(i, 0, n) dp[i] = k*n;
    for(int i = k*n-1; i >= 0; i--){
        next[i].fi = dp[arr[i]];
        next[i].se = i;
        dp[arr[i]] = i;
    }
    sort(next, next + k*n);
    vector<pair<int, pair<int, int>>> ans;
    set<int> curr;
    bool color[n];
    memset(color, 0, sizeof color);
    forn(i, 0, k*n){
        int count = 0;
        for(auto it = curr.lower_bound(next[i].se); it != curr.end(); ++it) count++;
        if (count < g && curr.find(next[i].se) == curr.end() && !color[arr[next[i].se]] && next[i].fi != n*k) {
            curr.insert(next[i].fi);
            color[arr[next[i].se]] = true;
            ans.pb(mp(arr[next[i].se], mp(next[i].fi + 1, next[i].se + 1)));
        }
    }
    sort(all(ans));
    forn(i, 0, n) cout << ans[i].se.se << ' ' << ans[i].se.fi << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}
