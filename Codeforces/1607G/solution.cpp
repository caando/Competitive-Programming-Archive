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
    ll n, m;
    cin >> n >> m;
    ll a[n], b[n], e[n], c[n], d[n];
    ll A = 0, B = 0;
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    ll rema[n], remb[n];
    memset(rema, 0, sizeof rema);
    memset(remb, 0, sizeof remb);
    forn(i, 0, n) {
        cin >> a[i] >> b[i];
        e[i] = m;
        if (e[i] > a[i]){
            d[i] += e[i]-a[i];
            b[i] -= e[i]-a[i];
            e[i] = a[i];
        }
        if (e[i] > b[i]) {
            c[i] += e[i]-b[i];
            a[i] -= e[i]-b[i];
            e[i] = b[i];
        }
        A += a[i], B += b[i];
    }
    for(int i = n-1; i >= 0; i--){
        rema[i] += a[i], rema[i] += b[i];
        if (i < n-1) rema[i] += rema[i+1], remb[i] += remb[i+1];
    }
    forn(i, 0, n){
        ll diff = A-B;
        A -= a[i];
        ll C = max(0ll, min(e[i], diff));
        a[i] -= C;
        c[i] += C;
        e[i] -= C;
        A += a[i];
        diff = A-B;
        B -= b[i];
        ll D = max(0ll, min(e[i], -diff));
        b[i] -= D;
        d[i] += D;
        e[i] -= D;
        B += b[i];
        A -= a[i], B -= b[i];
        if (e[i] > 0){
            a[i] -= e[i]/2;
            c[i] += e[i]/2;
            b[i] -= e[i]/2;
            d[i] += e[i]/2;
            if (remb[i]){
                a[i] -= e[i]&1;
                c[i] += e[i]&1;
            } else {
                b[i] -= e[i]&1;
                d[i] += e[i]&1;

            }
        }
        A += a[i], B += b[i];
    }
    cout << abs(A - B) << '\n';
    forn(i, 0, n) {
        cout << c[i] << ' ' << d[i] << '\n';
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