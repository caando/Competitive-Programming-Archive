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
vector<vector<pair<int, int>>> edges;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<bool>> tracker;

int n, m, k;

void reset(){
	forn(i, 0, adj.size()){
		forn(j, 0, adj[i].size()) tracker[i][j] = false;
	}
}

int dfs(int curr, int t, int flow){
	if (curr == t) return flow;
	if (visited[curr]) return 0;
	visited[curr] = true;
	forn(i, 0, adj[curr].size()){
		if (!tracker[curr][i]){
			tracker[curr][i] = true;
			int it = adj[curr][i];
			if (edges[curr][it].fi > edges[curr][it].se && !visited[it]){
				int res = dfs(it, t, min(flow, edges[curr][it].fi - edges[curr][it].se));
				if (res){
					edges[curr][it].se += res;
					edges[it][curr].se -= res;
					visited[curr] = false;
					return res;
				}
			}
		}
	}
	visited[curr] = false;
	return 0;
}

void solve(){
	cin >> n >> m >> k;
	forn(i, 0, n+m+2){
		edges.pb(vector<pair<int, int>>(n+m+2, mp(0, 0)));
		tracker.pb(vector<bool>(n+m+2));
		adj.pb(vector<int>());
	}
	visited = vector<bool>(n+m+2, false);
	forn(i, 0, k){
		int a, b;
		cin >> a >> b;
		edges[a][b+n].fi = 1;
		if (find(adj[a].begin(), adj[a].end(), b+n) == adj[a].end()) adj[a].pb(b+n), adj[b+n].pb(a);
		edges[0][a].fi = 1;
		if (find(adj[a].begin(), adj[a].end(), 0) == adj[a].end()) adj[a].pb(0), adj[0].pb(a);
		edges[b+n][n+m+1].fi = 1;
		if (find(adj[b+n].begin(), adj[b+n].end(), n+m+1) == adj[b+n].end()) adj[b+n].pb(n+m+1), adj[n+m+1].pb(b+n);
	}
	reset();
	while(dfs(0, n+m+1, INT32_MAX)) reset();
	int ans = 0;
	forn(i, 1, n+1){
		for(int j : adj[i]) if (edges[i][j].se == 1 && j != 0) ans++;
	}
	cout << ans << endl;
	forn(i, 1, n+1){
		for(int j : adj[i]) if (edges[i][j].se == 1 && j != 0) cout << i << ' ' << j - n << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}