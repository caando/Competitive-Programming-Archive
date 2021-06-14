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

void solve(){
	int n, k;
	cin >> n >> k;
    if (n&1 && !(k&1)){
        cout << -1 << endl;
        cout.flush();
    } else {
        int ans = 0, t = 0;
        if (n % k == 0) t = n/k;
        else {
            forn(i, 1, n) {
                if ((n-k*i) % 2 == 0 && (n-k*i) >= 0) t = i;
                if ((n-k*i) == k) t++;
                if ((n-k*t) < 2*k && k*t >= (n-k*t)/2) break;
            }
        }
        vector<int> free;
        forn(i, 0, t){
            cout << "? ";
            forn(j, 0, k) cout << n - i * k - j << ' ', free.pb(n - i * k - j-1);
            cout << endl;
            cout.flush();
            int res;
            cin >> res;
            ans ^= res;
        }
        int l = 0, r = n - t * k;
        while(l < r){
            int fi, se;
            cout << "? ";
            forn(i, 0, min((int)free.size(), k - (r-l)/2)) cout << free[i] + 1 << ' ';
            int cl, cr;
            forn(i, l, l+k - min((int)free.size(), k - (r-l)/2)) cout << i+1 << ' ', cl = i;
            cout << endl;
            cout.flush();
            cin >> fi;
            cout << "? ";
            forn(i, 0, min((int)free.size(), k - (r-l)/2)) cout << free[i] + 1 << ' ';
            for(int i = r-1; i >= r + min((int)free.size(), k - (r-l)/2) - k; i--) cout << i+1 << ' ', cr = i;
            cout << endl;
            cout.flush();
            cin >> se;
            ans ^= se;
            ans ^= fi;
            forn(i, l, min(cl, cr)) free.pb(i);
            l = min(cl+1, cr);
            for(int i = r; i > max(cl+1, cr); i--) free.pb(i-1);
            r = max(cr, cl+1);
        }
        cout << "! " << ans << endl;
        cout.flush();
    }

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}