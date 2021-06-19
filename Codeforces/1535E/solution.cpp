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
ll mod = 1000000007;
vl a, c;
vector<vl> p, ch;

pair<ll, ll> dfs(ll v, ll w){
	ll t = 0;
	if (v != 0){
		for (int i = 19; i >= 0; i--){
			if (a[p[v][i]] > 0) {
				pair<ll, ll> res = dfs(p[v][i], w);
				t += res.fi, w = res.se;
			}
			if (w <= 0) break;
		}
	}
	ll re = min(a[v], w);
	a[v] -= re, w -= re, t += re * c[v];
	return mp(t, w);
}

void solve(){
	ll q, A, C;
	cin >> q >> A >> C;
	a.pb(A), c.pb(C), p.pb(vl(20, 0)), ch.pb(vl());
	map<ll, ll> m;
	forn(i, 0, q){
		int t;
		cin >> t;
		if (t == 1){
			ll A, C, P, v = a.size();
			cin >> P >> A >> C;
			a.pb(A), c.pb(C), ch[m[P]].pb(v), ch.pb(vl()), p.pb(vl(20, m[P])), m[i+1] = v;
			forn(i, 1, 20) p[v][i] = p[p[v][i-1]][i-1];
		} else {
			ll temp, w;
			cin >> temp >> w;
			pair<ll, ll> res = dfs(m[temp], w);
			cout << w - res.se << ' ' << res.fi << endl;
			cout.flush();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(12) << fixed;
	solve();
}