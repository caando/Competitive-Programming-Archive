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
ll GCD(ll a, ll b) {
	return b ? GCD (b, a % b) : a;
}

// lowest common multiple
ll lcm(ll a, ll b) {
	return a / GCD(a, b) * b;
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

// power and modulo in (log n)
ll pow_mod(ll a, ll b, ll P){
	ll b_expo[63], ans = 1;
	b_expo[0] = a;
	for(int i = 1; i < 63; i++) {
		b_expo[i] = b_expo[i-1] * b_expo[i-1] % P;
	}
	for(ll i = 62; i >= 0; i--){
		if (b >= ((ll)1 << i)){
			ans = ans * b_expo[i] % P;
			b-= ((ll)1 << i);
		}
	}
	return ans;
}

// calculate modulo inverse (log n)
ll mod_inv(ll a, ll P) {
	return pow_mod(a, P - 2ll, P);
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
	forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * mod_inv(i, P) % P);
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
ll mod = 998244353;

void solve(){
	ll c, h1, h2, w1, w2, high = 0;
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (w1*w1 >= c){
		for(int i = 0; i*w1 <= c; i++){
			if (i * h1 + (c-i*w1)/w2*h2 > high) high = i * h1 + (c-i*w1)/w2*h2;
		}
	} else if (w2 * w2 >= c){
		for(int i = 0; i*w2 <= c; i++){
			if (i * h2 + (c-i*w2)/w1*h1 > high) high = i * h2 + (c-i*w2)/w1*h1;
		}
	} else {
		ll a;
		if (h1*w2 > h2*w1) a = c / (w2*w2*w1*w1) * h1*w2*w2*w1;
		else a = c / (w2*w2*w1*w1) * h2*w1*w1*w2;
		c %= w2*w1*w1*w2;
		for(int i = 0; i*w1 <= c; i++){
			if (i * h1 + (c-i*w1)/w2*h2 + a > high) high = i * h1 + (c-i*w1)/w2*h2 + a;
		}
	}
	cout << high;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
