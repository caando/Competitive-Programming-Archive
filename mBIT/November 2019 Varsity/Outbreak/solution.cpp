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
const ll maxn = 15000;

ll tree[maxn*4], lazyin[maxn*4], lazyfl[maxn*4];
ll in[maxn+1], fl[maxn+1];

ll fl_range(int l, int r){
	return fl[r+1] * inv_mod(fl[l], mod) % mod;
}

ll in_range(int l, int r){
	return in[r+1] * inv_mod(in[l], mod) % mod * inv_mod(pow_mod(fl_range(l, r), l, mod), mod) % mod;
}

void build(int arr[], int v, int tl, int tr){
	if (tl == tr) tree[v] = arr[tl];
	else{
		int tm = (tl+tr)/2;
		build(arr, v*2, tl, tm);
		build(arr, v*2+1, tm+1, tr);
		tree[v] = tree[v*2] * tree[v*2+1] % mod;
	}
}

void push(int v, int tl, int tr){
	int tm = (tr+tl)/2;
	lazyin[v*2] += lazyin[v];
	lazyfl[v*2] += lazyfl[v];
	tree[v*2] *= pow_mod(in_range(tl, tm), lazyin[v], mod) * pow_mod(fl_range(tl, tm), lazyfl[v], mod) % mod;
	tree[v*2] %= mod;
	lazyin[v*2+1] += lazyin[v];
	lazyfl[v*2+1] += lazyfl[v] + lazyin[v] * max(tm - tl+1, 0);
	tree[v*2+1] *= pow_mod(in_range(tm+1, tr), lazyin[v], mod) * pow_mod(fl_range(tm+1, tr), lazyin[v] * max(tm - tl+1, 0) + lazyfl[v], mod) % mod;
	tree[v*2+1] %= mod;
	lazyin[v] = lazyfl[v] = 0;
}

ll update(int v, int tl, int tr, int l, int r, int in, int fl){
	if (l > r) return tree[v];
	if (tl == l && tr == r) {
		lazyin[v] += in, lazyfl[v] += fl;
		tree[v] *= pow_mod(in_range(l, r), in, mod) * pow_mod(fl_range(l, r), fl, mod) % mod;
		tree[v] %= mod;
		return tree[v];
	} else {
		push(v, tl, tr);
		int tm = (tl + tr)/2;
		ll a = update(v*2, tl, tm, l, min(tm, r), in, fl);
		ll b = update(v*2+1, tm+1, tr, max(l, tm+1), r, in, fl + in * max(tm - l+1, 0));
		tree[v] = a * b % mod;
		return tree[v];
	}
}

ll query(int v, int tl, int tr, int l, int r){
	if (l > r) return 1;
	if (tl == l && tr == r) return tree[v];
	else {
		push(v, tl, tr);
		int tm = (tl + tr)/2;
		return query(v*2, tl, tm, l, min(tm, r)) * query(v*2+1, tm+1, tr, max(l, tm+1), r) % mod;
	}
}

void solve(){
	memset(lazyin, 0, sizeof lazyin);
	memset(lazyfl, 0, sizeof lazyfl);
	int n, m;
	cin >> n >> m;
	int arr[n];
	forn(i, 0, n) cin >> arr[i];
	in[0] = 1, fl[0] = 1;
	forn(i, 0, n) in[i+1] = in[i] * pow_mod(arr[i], i+1, mod) % mod, fl[i+1] = fl[i] * arr[i] % mod;
	build(arr, 1, 0, n-1);
	while(m--){
		int t;
		cin >> t;
		if (t == 1){
			int l, r, in;
			cin >> l >> r >> in;
			update(1, 0, n-1, l-1, r-1, in, 0);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(1, 0, n-1, l-1, r-1) << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(12) << fixed;
	solve();
}