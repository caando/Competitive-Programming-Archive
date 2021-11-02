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
const long long mod = 998244353;
const int MAXN = 200000;

void solve(){
    int n;
    cin >> n;
    int a[n], b[n], m[n], bal[n], diff[n], c[n], d[n];
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    map<int, vector<pair<int, pair<int, int>>>> ma;
    forn(i, 0, n) {
        cin >> a[i] >> b[i] >> m[i];
        if (m[i] > b[i]) {
            c[i] += m[i]-b[i];
            a[i] -= m[i]-b[i];
            m[i] = b[i];
        }
        bal[i] = a[i]+b[i]-m[i], diff[i] = a[i] - b[i];
        ma[bal[i]].pb(mp(diff[i]+m[i], mp(m[i], i)));
    }
    int count=0;
    int res[n];
    for(auto it : ma){
        auto v = it.se;
        sort(all(v));
        int cur = INT_MIN;
        for(auto it1 : v){
            if (it1.fi - it1.se.fi * 2 > cur) {
                count++;
                cur = it1.fi;
            }
            res[it1.se.se] = cur;
        }
    }
    cout << count << '\n';
    forn(i, 0, n) {
        int temp = m[i]-res[i];
        int A = a[i], B = b[i];
        int t1 = max(0, a[i]-b[i] - res[i]), t2 = max(0, b[i]-a[i] + res[i]), rem = m[i]-t1-t2;
        A -= t1;
        B -= t2;
        A -= rem/2;
        B -= rem/2;
        cout << a[i]-A +c[i]<< ' ' << b[i]-B << '\n';
    }
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}