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

void solve(){
    ll n, m;
    set<vector<ll>> ban;
    cin >> n;
    vector<vector<ll>> a = vector<vector<ll>>(n);
    forn(i, 0, n){
        int c;
        cin >> c;
        forn(j, 0, c){
            ll temp;
            cin >> temp;
            a[i].pb(temp);
        }
    }
    cin >> m;
    forn(i, 0, m){
        vector<ll> curr;
        forn(j, 0, n){
            ll temp;
            cin >> temp;
            curr.pb(temp);
        }
        ban.insert(curr);
    }
    vector<ll> ans;
    forn(i, 0, n) ans.pb(a[i].size());
    if (ban.find(ans) != ban.end()){
        ll highscore = 0;
        for(auto it = ban.begin(); it != ban.end(); ++it){
            ll score = 0;
            vector<ll> curr = *it;
            forn(i, 0, n) score += a[i][curr[i]-1];
            forn(i, 0, n){
                if (curr[i] > 1) {
                    score -= a[i][curr[i]-1];
                    curr[i]--;
                    score += a[i][curr[i]-1];
                    if (score > highscore && ban.find(curr) == ban.end()) highscore = score, ans = curr;
                    score -= a[i][curr[i]-1];
                    curr[i]++;
                    score += a[i][curr[i]-1];
                }
            }
        }
    }
    forn(i, 0, n) cout << ans[i] << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}