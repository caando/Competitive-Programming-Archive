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

ll dp[100000][450];
 
void solve(){
    ll n;
    cin >> n;
    ll pre[n+1];
    pre[0] = 0;
    forn(i, 0, n) {
        ll temp;
        cin >> temp;
        pre[i+1] = pre[i] + temp;
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < 450; j++) dp[i][j] = INT_MIN;
    }
    for(ll i = n-1; i >= 0; i--){
        if (i!= n-1) forn(j, 1, 450) dp[i][j] = dp[i+1][j];
        if (pre[i+1]-pre[i] > dp[i][1]) dp[i][1] = pre[i+1]-pre[i];
        for(ll j = 2; j < 450; j++){
            if (i+j < n){
                if (dp[i+j][j-1] != INT_MIN){
                    if (pre[i+j] - pre[i] < dp[i+j][j-1]) {
                        if (pre[i+j] - pre[i] > dp[i][j]) dp[i][j] = pre[i+j] - pre[i];
                    }
                }
            }
        }
    }
    int high = 0;
    forn(i, 1, 450){
        if (dp[0][i] != INT_MIN) {
            high = i;
        } else break;
    }
    cout << high << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}