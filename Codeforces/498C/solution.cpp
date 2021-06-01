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

// Combinations
vector<vector<ll>> nCr;
void NCR(int n, ll P){
	nCr.reserve(n+1);
	forn(i, 0, n+1) {
		vector<ll> v(n+1);
		nCr.pb(v);
	}
	forn(i, 0, n+1) nCr[i][i] = 1, nCr[i][0] = 1;
	forn(i, 1, n+1){
		forn(j, 1, i) {
			nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
			if (nCr[i][j] > P) nCr[i][j] -= P;
		}
	}
}

// RNG
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Mod
ll mod = 1000000007;

// Ford-Fulkerson
vector<vector<pair<ll, ll>>> edges;
vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> arr;
vector<ll> primes;

ll n, m;
ll counter = 0;

ll dfs(ll curr, ll t, ll flow){
	if (curr == t) {
		ll curr = flow;
		for(ll prime : primes) {
			while (curr % prime == 0) counter++, curr /= prime;
		}
		if (curr != 1) counter++;
		return flow;
	}
	if (flow == 1) return 1;
	if (visited[curr]) return 1;
	visited[curr] = true;
	forn(i, 0, adj[curr].size()){
		if (!visited[adj[curr][i]]){
			ll it = adj[curr][i];
			if (edges[curr][it].fi > edges[curr][it].se/edges[it][curr].se){
				ll res;
				if (flow == -1) res = dfs(it, t, edges[curr][it].fi*edges[it][curr].se/edges[curr][it].se);
				else res = dfs(it, t, GCD(flow, edges[curr][it].fi*edges[it][curr].se/edges[curr][it].se));
				if (res != 1){
					edges[curr][it].se *= max(res/edges[it][curr].se, 1ll);
					edges[it][curr].se /= min(edges[it][curr].se, res);
					if (edges[it][curr].se == 0) cout << it << ' ' << curr << endl;
					visited[curr] = false;
					return res;
				}
			}
		}
	}
	visited[curr] = false;
	return 1;
}

void solve(){
	for(int i = 2; i < 100000; i++){
		bool is_prime = true;
		for(ll prime : primes) {
			if (i % prime == 0) is_prime=false;
			break;
		}
		if (is_prime) primes.pb(i);
	}

	cin >> n >> m;
	forn(i, 0, n+2){
		edges.pb(vector<pair<ll, ll>>(n+2, mp(1, 1)));
		adj.pb(vector<ll>());
	}
	
	visited = vector<bool>(n+1, false);
	forn(i, 0, n){
		ll temp;
		cin >> temp;
		arr.pb(temp);
		if (i & 1){
			adj[i+1].pb(n+1);
			edges[i+1][n+1].fi = temp;
		} else {
			adj[0].pb(i+1);
			edges[0][i+1].fi = temp;
		}
	}
	forn(i, 0, m){
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		if (a & 1) {
			edges[a][b].fi = GCD(arr[a-1], arr[b-1]);
			edges[b][a].fi = 1;
		} else {
			edges[b][a].fi = GCD(arr[a-1], arr[b-1]);
			edges[a][b].fi = 1;
		}
	}
	while(dfs(0, n+1, -1) != 1) ;
	cout << counter << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}