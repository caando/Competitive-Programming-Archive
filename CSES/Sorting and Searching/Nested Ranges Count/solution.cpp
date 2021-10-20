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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree< pair<ll, pair<ll, ll>>,null_type,less< pair<ll, pair<ll, ll>>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int bit[MAXN], n;

void add(int idx, int val) {
    for (++idx; idx < 2*n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void solve(){
    cin >> n;
    int m[n], b[n], m1[n];
    memset(b, 0, sizeof b);
    memset(bit, 0, sizeof bit);
    auto cmp = [](pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) { 
        if (a.fi == b.fi){
            return a.se > b.se;
        }
        return a.fi < b.fi;
    };
    auto cmp1 = [](pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) { 
        if (a.se.fi == b.se.fi){
            return a.fi > b.fi;
        }
        return a.se.fi > b.se.fi;
    };
    pair<ll, pair<ll, ll>> arr[n];
    forn(i, 0, n) cin >> arr[i].fi >> arr[i].se.fi, arr[i].se.se = i;
    sort(arr, arr+n, cmp1);
    forn(i, 0, n) m1[arr[i].se.se] = i;
    sort(arr, arr+n, cmp);
    forn(i, 0, n) m[arr[i].se.se] = i;
    ordered_set s;
    forn(i, 0, n){
        auto it = s.lower_bound(mp(arr[i].se.fi, mp(INT64_MIN, INT64_MIN)));
        if (it != s.end()){
            range_add(0, m1[(*it).se.se], 1);
            b[i] = s.size() - s.order_of_key(*it);
        }
        s.insert(mp(arr[i].se.fi, mp(arr[i].fi, arr[i].se.se)));
        range_add(m1[arr[i].se.se], m1[arr[i].se.se], -1*point_query(m1[arr[i].se.se]));
    }
    forn(i, 0, n) {
        cout << point_query(m1[i]) << ' ';
    }
    cout << '\n';
    forn(i, 0, n) cout << b[m[i]] << ' ';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}