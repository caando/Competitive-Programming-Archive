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

ll pow_mod(ll a, ll b, ll P){
    ll curr = a, ans = 1;
    while(b != 0){
        if (b&1) {
            ans *= curr;
            ans%=P;
        }
        curr *= curr;
        curr %= P;
        b >>= 1;
    }
    return ans;
}

ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

void solve(int T){
    int n, m;
    cin >> n >> m;
    ll p[n];
    forn(i, 0, n) cin >> p[i];
    pair<ll, ll> s[m];
    forn(i, 0, m) cin >> s[i].fi >> s[i].se;
    sort(s, s+m);
    sort(p, p+n);
    set<pair<ll, ll>> f;
    forn(i, 0, m){
        auto it = f.lower_bound(mp(s[i].se, INT64_MIN));
        while (it != f.end()){
            auto temp = it;
            ++it;
            f.erase(temp);
        }
        f.insert(mp(s[i].se, s[i].fi));
    }
    set<pair<ll, ll>> f1;
    for(auto it = f.begin(); it != f.end(); ++it){
        f1.insert(mp((*it).se, (*it).fi));
    }
    f.clear();
    forn(i, 0, n){
        auto it = f1.upper_bound(mp(p[i], INT64_MAX));
        if (it != f1.begin()){
            --it;
            while((*it).fi <= p[i] && (*it).se >= p[i]){
                auto temp = it;
                --it;
                if (temp == f1.begin()){
                    f1.erase(temp);
                    break;
                } else {
                    f1.erase(temp);
                }
            }
        }
    }
    vector<pair<ll, ll>> seg[n+1];
    auto cur = f1.begin();
    for(int i = 0; i < n+1 && cur != f1.end(); i++){
        if (i == n){
            while (cur != f1.end()) {
                seg[i].pb(*cur);
                ++cur;
            }
        } else {
            while ((*cur).se < p[i]) {
                seg[i].pb(*cur);
                ++cur;
                if (cur == f1.end()) break;
            }
        }
    }
    ll dp[n+1][2];
    forn(i, 0, n+1){
        dp[i][0] = INT64_MAX;
        dp[i][1] = INT64_MAX;
        if (i == 0){
            if (sz(seg[i]) == 0) {
                dp[i][0] = 0;
                dp[i][1] = 0;
            } else {
                dp[i][0] = p[0] - seg[i][0].se;
                dp[i][1] = 2*(p[0] - seg[i][0].se);
            }
        } else if (i == n){
            if (sz(seg[i]) == 0) {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            } else {
                dp[i][1] = dp[i-1][1] + seg[i][sz(seg[i])-1].fi - p[n-1];
                dp[i][0] = dp[i-1][0] + 2*(seg[i][sz(seg[i])-1].fi - p[n-1]);
            }
        } else {
            if (sz(seg[i]) == 0){
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            } else {
                forn(j, 0, sz(seg[i])+1){
                    if (j == 0){
                        dp[i][0] = min(dp[i][0], min(dp[i-1][0], dp[i-1][1]) + p[i] - seg[i][j].se);
                        dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][1]) + 2*(p[i] - seg[i][j].se));
                    } else if (j == sz(seg[i])){
                        dp[i][0] = min(dp[i][0], dp[i-1][0] + 2*(seg[i][j-1].fi - p[i-1]));
                        dp[i][0] = min(dp[i][0], dp[i-1][1] + seg[i][j-1].fi - p[i-1]);
                        dp[i][1] = min(dp[i][1], dp[i-1][1] + seg[i][j-1].fi - p[i-1]);
                        dp[i][1] = min(dp[i][1], dp[i-1][0] + 2*(seg[i][j-1].fi - p[i-1]));
                    } else {
                        dp[i][0] = min(dp[i][0], dp[i-1][0] + 2*(seg[i][j-1].fi - p[i-1]) + p[i] - seg[i][j].se);
                        dp[i][0] = min(dp[i][0], dp[i-1][1] + seg[i][j-1].fi - p[i-1] + p[i] - seg[i][j].se);
                        dp[i][1] = min(dp[i][1], dp[i-1][1] + seg[i][j-1].fi - p[i-1] + 2*(p[i] - seg[i][j].se));
                        dp[i][1] = min(dp[i][1], dp[i-1][0] + 2*(seg[i][j-1].fi - p[i-1]) + 2*(p[i] - seg[i][j].se));
                    }
                }
            }
        }
    }
    cout << min(dp[n][1], dp[n][0]) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}