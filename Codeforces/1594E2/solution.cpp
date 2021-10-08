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
const int MAXN = 100005;

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

void solve(){
    ll n, m;
    cin >> n >> m;
    map<string, ll> con;
    map<ll, ll> illegal;
    con["white"] = 0; 
    con["yellow"] = 1; 
    con["green"] = 2; 
    con["blue"] = 3; 
    con["red"] = 4; 
    con["orange"] = 5; 
    illegal[0] = 1;
    illegal[1] = 0;
    illegal[2] = 3;
    illegal[3] = 2;
    illegal[4] = 5;
    illegal[5] = 4;
    map<pair<ll, ll>, ll> dp;
    pair<ll, ll> arr[m];
    forn(i, 0, m) {
        string s;
        cin >> arr[i].fi >> s;
        arr[i].se = con[s];
    }
    sort(arr, arr+m);
    
    for(int i = m-1; i >= 0; i--){
        ll v = arr[i].fi, c = arr[i].se;
        forn(j, 0, 6){
            if (c != j) dp[mp(v,j)] = 0;
            else if (dp.find(mp(v, j)) == dp.end()) dp[mp(v,j)] = 1;
        }
        while(v > 1) {
            v >>= 1;
            forn(j, 0, 6){
                if (dp.find(mp(v*2,j))==dp.end()) dp[mp(v*2,j)] = 1;
                if (dp.find(mp(v*2+1,j))==dp.end()) dp[mp(v*2+1,j)] = 1;
            }
            forn(j, 0, 6){
                dp[mp(v, j)] = 0;
                forn(k, 0, 6){
                    forn(l, 0, 6){
                        if (k != illegal[j] && k != j && l != illegal[j] && l != j){
                            dp[mp(v, j)] += dp[mp(v*2,k)] * dp[mp(v*2+1,l)] % mod;
                        }
                    }
                }
                dp[mp(v, j)] %= mod;
            }
        }
    }
    ll t = 0;
    forn(i, 0, 6) t += dp[mp(1, i)];
    t %= mod;
    cout << t * pow_mod(4, pow(2, n) - dp.size()/6 - 1, mod) % mod;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}