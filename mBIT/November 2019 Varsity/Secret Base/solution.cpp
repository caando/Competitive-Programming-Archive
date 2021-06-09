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
vector<vi> adj;
int counter = 0;
vii b;

void dfs(int curr, int p){
	b[curr].fi = counter++;
	for (int i : adj[curr]) if (i!= p) dfs(i, curr);
	b[curr].se = counter++;
}

void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	adj = vector<vi>(n);
	b = vii(n);
	forn(i, 0, n-1){
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	dfs(0, -1);
	vector<pair<int, pair<int, int>>> tunnels;
	forn(i, 0, m){
		int a, b, c;
		cin >> a >> b >> c;
		tunnels.pb(mp(a-1, mp(c, b-1)));
		tunnels.pb(mp(b-1, mp(c, a-1)));
	}
	sort(tunnels.begin(), tunnels.end());


	int base = -1;
	map<int, priority_queue<int, vector<int>, greater<int> >> poss;
	set<pair<int, int>> children; 
	ll ans = INT64_MAX;
	
	
	forn(i, 0, tunnels.size()){
		if (tunnels[i].fi != base){
			if (base != -1){
				for(auto it = poss.begin(); it != poss.end(); ++it){
					if ((it->second).size() >= k){
						ll curr = 0;
						forn(j, 0, k) {
							curr += (it->second).top();
							(it->second).pop();
						}
						if (curr < ans) ans = curr;
					}
				}
			}
			base = tunnels[i].fi;
			children.clear();
			poss.clear();
			for(int i : adj[base]){
				children.insert(mp(b[i].se, i));
			}
		}
		int village = tunnels[i].se.se;
		if (b[village].fi > b[base].fi && b[village].se < b[base].se){
			int child = (*children.lower_bound(mp(b[village].se, 0))).se;
			poss[child].push(tunnels[i].se.fi);
		} else {
			poss[0].push(tunnels[i].se.fi);
		}
	}
	
	if (base != -1){
		for(auto it = poss.begin(); it != poss.end(); ++it){
			if ((it->second).size() >= k){
				ll curr = 0;
				forn(j, 0, k) {
					curr += (it->second).top();
					(it->second).pop();
				}
				if (curr < ans) ans = curr;
			}
		}
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(12) << fixed;
	solve();
}