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

void solve(){
    ll n, cnt = 0;
    cin >> n;
    pair<int, pair<int, int>> arr[n];
    forn(i, 0, n){
        cin >> arr[i].fi;
        if (arr[i].fi == 2) cin >> arr[i].se.fi >> arr[i].se.se;
        else cin >> arr[i].se.fi, cnt++;
    }
    unordered_map<int, int> m;
    forn(i, 0, 500001){
        m[i] = i;
    }
    int s = cnt;
    int ans[s];
    cnt--;
    for(int i = n-1; i>=0; i--){
        if (arr[i].fi == 1){
            int cur = arr[i].se.fi;
            ans[cnt] = m[cur];
            cnt--;
        } else {
            if (arr[i].se.fi != arr[i].se.se) {
                m[arr[i].se.fi] = m[arr[i].se.se];
            }
        }
    }
    forn(i, 0, s) cout << ans[i] << ' ';
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}