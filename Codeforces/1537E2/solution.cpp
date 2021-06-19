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

// greatest common divisor
ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

// lowest common multiple
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// sieve of eratosthenes with smallest prime factor
vector<int> sieve;
void prime_sieve(int n){
    sieve.reserve(n+1);
    forn(i, 0, n+1) sieve[i] = i;
    forn(i, 2, n+1){
        if (sieve[i] == i){
            forn(j, 2, n/i+1){
                if (sieve[i*j] == i*j) sieve[i*j] = i;
            }
        }
    }
}

// normalise input to be in range of modulo
// faster than % when close to P
ll norm(ll a, ll P) {
    while (a >= P) a -= P;
    while (a < 0) a += P;
    return a;
}

// multiply and modulo
ll mul_mod(ll a, ll b, ll P) {
    return a * b % P;
}

// power and modulo (log n)
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

// calculate modulo inverse (log n)
ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}

// calculate modulo inverse (log n)
ll div_mod(ll a, ll b, ll P) {
    return a * inv_mod(b, P) % P;
}

// most significant bit (log n)
int msb(ll a){ 
    for(int i = 62; i >= 0; i--){
        if (a & ((ll)1 << i)) return i + 1;
    }
    return 0;
}

// Factorial
vector<ll> fact;
void Fact(int n, ll P){
    if (fact.size() < 1) fact.pb(1);
    forn(i, fact.size(), n+1) fact.pb(fact[i-1] * i  % P);
}

vector<ll> fact_inv;
void Fact_inv(int n, ll P){
    if (fact_inv.size() < 1) fact_inv.pb(1);
    forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * inv_mod(i, P) % P);
}

// Combinations
ll nCr(int n, int r, ll P){
    if (r > n) return 0;
    Fact(n, P);
    Fact_inv(n, P);
    return (fact[n] * fact_inv[r] % P) * fact_inv[n-r] % P;
}

ll nCr_inv(int n, int r, ll P){
    if (r > n) return 0;
    Fact(n, P);
    Fact_inv(n, P);
    return (fact_inv[n] * fact[r] % P) * fact[n-r] % P;
}

// RNG
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Mod
const ll mod = 1000000007;

string ans,curr;

int comp(int index){
    
    forn(i, index, min(ans.size(), curr.size())){
        if (ans[i] < curr[i]) return -1;
        else if (ans[i] > curr[i]) return 1;
    }
    if (curr.size() < ans.size()) return 0;
    else return 1;
}

void solve(){
	int n, k;
    cin >> n >> k;
    string s, trim;
    cin >> s;
    char starting = s[0];
    forn(i, 0, n) {
        if (s[i] <= s[0]) trim += s[i];
        else break;
    }
    vector<string> segs;
    forn(i, 0, trim.size()){
        if (trim[i] == starting){
            if (curr != "") segs.pb(curr);
            curr = "";
        }
        curr += trim[i];
    }
    if (curr != "") segs.pb(curr);
    curr = "";
    int index = 0;
    forn(i, 0, segs.size()) {
        curr += segs[i];
        if (comp(index) == 1) {
            ans += curr;
            curr = "";
        } else if (comp(index) == -1) break;
        index = curr.size();
    }
    forn(i, 0, k) cout << ans[i % ans.size()];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}