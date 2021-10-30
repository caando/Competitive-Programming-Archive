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
    ll n, t = 0;
    cin >> n;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    vector<pair<int, ll>> cur, nxt, nxt1;
    for(int i = n-1; i >= 0; i--){
        nxt.clear();
        nxt1.clear();
        for(auto it : cur){
            t += (it.fi-1) * it.se * (i+1);
            if(i > 0) {
                int t1 = arr[i]/it.fi;
                int add = (arr[i-1]+t1-1)/t1;
                nxt.pb(mp(add, it.se));
            }
        }
        t %= mod;
        if(i > 0) {
            ll d = arr[i-1]/arr[i] + (int)(arr[i-1]%arr[i]>0);
            nxt.pb(mp(d, 1));
        }
        sort(all(nxt));
        for(auto it : nxt){
            if (nxt1.empty()) nxt1.pb(it);
            else if (it.fi == nxt1[sz(nxt1)-1].fi){
                nxt1[sz(nxt1)-1].se += it.se;
            } else nxt1.pb(it);
        }
        cur = nxt1;
    }
    cout << t << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}