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

ll mod = 1000000007;

ll calc(ll n){
    ll temp = abs(n), ans = 0;
    vector<ll> tmp, digits;
    while (temp > 0) tmp.pb(temp%10), temp /= 10;
    while(!tmp.empty()) digits.pb(tmp.back()), tmp.pop_back();
    bool check = true;
    for(int i = 1; i < digits.size(); i++) if (digits[i] == digits[i-1]) check = false;
    if (check && digits.size() > 0) ans++;
    ll dp[10];
    memset(dp, 0, sizeof dp);
    bool curr = true;
    for(ll i = 0; i < digits.size(); i++){
        ll nxt[10];
        memset(nxt, 0, sizeof nxt);
        for(ll d = 0; d < 10; d++) {
            for(ll pd = 0; pd < 10; pd++) if (d != pd) nxt[d] += dp[pd];
            if (i != 0 && d != 0) nxt[d]++;
        }
        if (curr){
            for(ll d = 0; d < digits[i]; d++){ 
                if (i == 0 && d == 0) continue;
                if (i > 0) if (d == digits[i-1]) continue;
                if (i > 1) if(digits[i-1] == digits[i-2]) curr = false;
                if (!curr) continue;
                nxt[d]++;
            }
        }
        for(ll d = 0; d < 10; d++) dp[d] = nxt[d];
    }
    for(ll d = 0; d < 10; d++) ans += dp[d];
    if (n < 0) ans *= -1;
    return ans;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}