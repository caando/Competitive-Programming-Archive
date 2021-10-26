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

vector<int> a, b, pos;

void calc(int l, int r, int tl, int tr){
    int m = (l+r)/2;
    int val = b[m], res = 0, cnt = 0, tm=tl, tm2 = tl;

    forn(i, tl, tr) {
        if (a[i] < val) cnt++;
    }
    int low = cnt;
    forn(i, tl, tr){
        if (a[i] < val) cnt--;
        else if (a[i] > val) cnt++;
        if (cnt < low) tm = i+1, tm2=i+1,low = cnt;
        else if (cnt == low) tm2 = i+1;
    }
    pos[m] = tm;
    if (m+1 <= r){
        calc(m+1, r, tm2, tr);
    }
    if (m-1 >= l){
        calc(l, m-1, tl, tm);
    }
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,greater<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){
    ll n, m;
    cin >> n >> m;
    a = vector<int>(n);
    b = vector<int>(m);
    pos = vector<int>(m);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];
    sort(all(b));
    calc(0, m-1, 0, n);
    ll j = 0, ans = 0;
    ordered_set s;
    forn(i, 0, m){
        while (j < pos[i]) {
            ans += s.order_of_key(mp(a[j], j+i));
            s.insert(mp(a[j], j+i));
            j++;
        }
        ans += s.order_of_key(mp(b[i], j+i));
        s.insert(mp(b[i], j+i));
    }
    while (j < n) {
        ans += s.order_of_key(mp(a[j], j+m));
        s.insert(mp(a[j], j+m));
        j++;
    }
    cout << ans << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}