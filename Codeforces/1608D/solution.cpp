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


ll pow_mod(ll a, ll b, ll P){
    ll ans = 1;
    while(b){
        if (b&1) ans = ans*a%P;
        a = a*a%P;
        b >>= 1;
    }
    return ans;
}

ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}

vector<ll> fact;
void calc_fact(int n, ll P){
    if (fact.size() < 1) fact.pb(1);
    forn(i, fact.size(), n+1) fact.pb(fact[i-1] * i  % P);
}

vector<ll> fact_inv;
void calc_fact_inv(int n, ll P){
    if (fact_inv.size() < 1) fact_inv.pb(1);
    forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * inv_mod(i, P) % P);
}

ll nCr(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact[n] * fact_inv[r] % P) * fact_inv[n-r] % P;
}

void solve(){
    int n, a=0, b=0, c=0, d=0, e=0, f=0;
    ll ans = 0;
    cin >> n;
    bool yes = false;
    for(int i = 0; i < n; i++){
        char l, r;
        cin >> l >> r;
        if (l == r && l != '?') yes = true;
        if (l == 'B' && r == 'W') e++;
        if (l == 'W' && r == 'B') f++;
        if(l == 'B') a++;
        if(l == 'W') b++;
        if(r == 'B') c++;
        if(r == 'W') d++;
    }
    int g = max(a, d), h = n - max(b, c);
    forn(i, g, h+1){
        ans += nCr(n - a - b, i-a, mod) * nCr(n - c - d, i-d, mod) % mod;
        if (!yes && i > 0 && i < n){
            if (i >= n-i){
                // BW
                ans -= nCr(n - a - b - c -d + e + f, min(n - a - b - c + f, i - a - d + e), mod);
            } else {
                // WB
                ans -= nCr(n - a - b - c - d + e + f, min(n - a - b - c - d + e + f, n - i - b - c + f), mod);
            }
        }
        ans %= mod;
    }
    cout << (ans+mod)  % mod << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}