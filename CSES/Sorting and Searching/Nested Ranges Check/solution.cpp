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
const int MAXN = 1000000;

void solve(){
    ll n;
    cin >> n;
    bool a[n], b[n];
    auto cmp = [](pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) { 
        if (a.fi == b.fi){
            return a.se > b.se;
        }
        return a.fi < b.fi;
    };
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    pair<ll, pair<ll, ll>> arr[n];
    forn(i, 0, n) cin >> arr[i].fi >> arr[i].se.fi, arr[i].se.se = i;
    sort(arr, arr+n, cmp);
    set<pair<ll, pair<ll, ll>>> s, t;
    forn(i, 0, n){
        auto it = s.lower_bound(mp(arr[i].se.fi, mp(INT64_MIN, INT64_MIN)));
        while (it != s.end()){
            auto temp = *it;
            it++;
            a[temp.se.se] = true;
            t.insert(temp);
            s.erase(temp);
        }
        auto it1 = t.lower_bound(mp(arr[i].se.fi, mp(INT64_MIN, INT64_MIN)));
        if (it1 != t.end()) b[arr[i].se.se] = true;
        s.insert(mp(arr[i].se.fi, mp(arr[i].fi, arr[i].se.se)));
    }
    forn(i, 0, n) cout << a[i] << ' ';
    cout << '\n';
    forn(i, 0, n) cout << b[i] << ' ';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}