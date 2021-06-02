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
	vector<char> tree;
	vector<pair<int, int>> range;
	vector<vector<int>> child;
	string a, b;
	cin >> a >> b;
	tree.pb('.');
	child.pb(vector<int>());
	range.pb(mp(0, 0));
	forn(i, 0, a.size()){
		int curr = 0;
		forn(j, i, a.size()){
			int found = 0;
			for(int k : child[curr]) if (tree[k] == a[j]) found = k;
			if (found){
				curr = found;
			} else {
				child[curr].pb(tree.size());
				curr = tree.size();
				tree.pb(a[j]);
				range.pb(mp(i+1, j+1));
				child.pb(vector<int>());
			}
		}
	}
	for(int i = a.size()-1; i >= 0; i--){
		int curr = 0;
		for(int j = i; j >= 0; j--){
			int found = 0;
			for(int k : child[curr]) if (tree[k] == a[j]) found = k;
			if (found){
				curr = found;
			} else {
				child[curr].pb(tree.size());
				curr = tree.size();
				tree.pb(a[j]);
				range.pb(mp(i+1, j+1));
				child.pb(vector<int>());
			}
		}
	}
	bool poss = true;
	int index= 0, curr = 0, count = 1;
	vector<int> ans_vec;
	while (index < b.size()){
		int found = 0;
		for(int i : child[curr]) {
			if (tree[i] == b[index]) found = i;
		}
		if (found){
			curr = found;
		} else {
			if (curr == 0) poss = false;
			ans_vec.pb(curr);
			curr = 0;
			count++;
			int found = 0;
			for(int i : child[curr]) {
				if (tree[i] == b[index]) found = i;
			}
			curr = found;
		}
		index++;
	}
	if (curr != 0){
		ans_vec.pb(curr);
	}
	if (poss) {
		cout << count << endl;
		for(int i : ans_vec) cout << range[i].fi << ' ' << range[i].se << endl;
	} else cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
