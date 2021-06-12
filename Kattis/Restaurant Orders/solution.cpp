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
const ll maxn = 30001;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
	vector<int> dp(maxn,-1);
    dp[0] = 0;
    forn(i, 0, n){
        forn(j, 0, maxn){
			if (j + arr[i] < maxn) {
				if (dp[j] >= 0){
					if (dp[j+arr[i]] == -1) dp[j+arr[i]] = i;
					else dp[j+arr[i]] = -2;
				} else if (dp[j] == -2) dp[j+arr[i]] = -2;
			}
		}
    }
    int t;
    cin >> t;
    while (t--){
        int c;
        cin >> c;
		if (dp[c] == -1) cout << "Impossible\n";
        else if (dp[c] == -2) cout << "Ambiguous\n";
        else {
			stack<int> st;
			while (c != 0) st.push(dp[c]), c -= arr[dp[c]];
			while(!st.empty()) cout << st.top()+1 << ' ', st.pop();
			cout << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}