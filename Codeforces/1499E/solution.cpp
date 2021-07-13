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

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<int> sieve;
void calc_sieve(int n){
    sieve.reserve(n+1);
    forn(i, 0, n+1) sieve[i] = i;
    forn(i, 2, n+1){
        if (sieve[i] == i){
            for(ll j = i * i; j <= n; j += i){
                if (sieve[j] == j) sieve[j] = i;
            }
        }
    }
}

ll norm(ll a, ll P) {
    while (a >= P) a -= P;
    while (a < 0) a += P;
    return a;
}

ll mul_mod(ll a, ll b, ll P) {
    return a * b % P;
}

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

ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}

ll div_mod(ll a, ll b, ll P) {
    return a * inv_mod(b, P) % P;
}

int msb(ll a){ 
    for(int i = 62; i >= 0; i--){
        if (a & ((ll)1 << i)) return i + 1;
    }
    return 0;
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

ll nCr_inv(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact_inv[n] * fact[r] % P) * fact[n-r] % P;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 1000000;

void solve(){
    string a, b;
    cin >> a >> b;
    ll dp[a.size()+1][b.size()+1][26];
    memset(dp, 0, sizeof dp);
    ll curr = 1;
    forn(i, 1, a.size()+1){
        dp[i][0][a[i-1]-'a'] = curr;
        curr++;
        if (i != a.size()) if (a[i-1] == a[i]) curr=1;
    }
    curr = 1;
    forn(j, 1, b.size()+1){
        dp[0][j][b[j-1]-'a'] = curr;
        curr++;
        if (j != b.size()) if (b[j-1] == b[j]) curr=1;
    }
    forn(i, 1, a.size()+1){
        forn(j, 1, b.size()+1){
            dp[i][j][a[i-1]-'a']++;
            dp[i][j][b[j-1]-'a']++;
            forn(k, 0, 26) {
                if(a[i-1]-'a'!= k) dp[i][j][a[i-1]-'a'] += dp[i-1][j][k];
            }
            forn(k, 0, 26) {
                if(b[j-1]-'a'!= k) dp[i][j][b[j-1]-'a'] += dp[i][j-1][k];
            }
            forn(k, 0, 26) dp[i][j][k] %= mod;
        }
    }
    ll t = 0;
    forn(i, 1, a.size()+1){
        forn(j, 1, b.size()+1) {
            t -= dp[i][0][a[i-1]-'a'], t -= dp[0][j][b[j-1]-'a'];
            forn(k, 0, 26) t += dp[i][j][k];
            t %= mod;
        }
    }
    cout << t << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}
