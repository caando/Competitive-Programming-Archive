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
const long long mod = 998244353;
const int MAXN = 100000;

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    int state[n];
    forn(i, 0, n) {
        cin >> arr[i].fi >> arr[i].se;
        cin >> state[i];
    }
    ll cnt[n];
    ll dp[n];
    memset(cnt, 0, sizeof cnt);
    memset(dp, 0, sizeof dp);
    forn(i, 0, n){
        auto it = lower_bound(arr.begin(), arr.end(), mp(arr[i].se, 0ll));
        if ((*it) == arr[i]) {
            cnt[i] = arr[i].fi - arr[i].se;
        } else {
            cnt[i] = dp[i-1] - dp[it-arr.begin()] + arr[i].fi - arr[i].se + cnt[it-arr.begin()];
        }
        cnt[i] %= mod;
        dp[i] += cnt[i];
        if (i != 0) dp[i] += dp[i-1];
        dp[i] %= mod;
    }
    ll ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if (state[i]) {
            ans += cnt[i];
            ans %= mod;

        }
    }
    cout << (arr[n-1].fi + 1 + ans) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}