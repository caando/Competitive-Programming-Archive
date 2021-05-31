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

vector<vector<pair<ll, ll>>> edges;
vector<vector<ll>> adj;
ll n, m;
vector<ll> level, ptr;

// Dinics
void bfs(ll s){
	fill(level.begin(), level.end(), INT32_MAX);
	queue<pair<ll, ll>> q;
	q.push(mp(s, 0));
	while(!q.empty()){
		auto curr = q.front();
		level[curr.fi] = min(curr.se, level[curr.fi]);
		q.pop();
		for(auto it : adj[curr.fi]){
			if (level[it] == INT32_MAX && edges[curr.fi][it].fi > edges[curr.fi][it].se){
				q.push(mp(it, curr.se + 1));
			}
		}
	}
}

ll dfs(ll curr, ll t, ll in){
	if (curr == t) {
		return in;
	}
	if (in == 0) return 0;
	for(ll& it = ptr[curr]; it < adj[curr].size(); ++it){
		int i = adj[curr][it];
		if (level[i] == level[curr] + 1){
			if (edges[curr][i].fi > edges[curr][i].se){
				ll flow = dfs(i, t, min(edges[curr][i].fi - edges[curr][i].se, in));
				if (flow > 0) {
					edges[curr][i].se += flow;
					edges[i][curr].se -= flow;
					return flow;
				}
			}
		}
	}
	return 0;
}

void solve(){
	cin >> n >> m;
	forn(i, 0, n){
		edges.pb(vector<pair<ll, ll>>(n, mp(0, 0)));
		adj.pb(vector<ll>());
	}
	ll flow = 0;
	level = vector<ll>(n);
	ptr = vector<ll>(n);
	forn(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		edges[a-1][b-1].fi += c;
		auto s = lower_bound(adj[a-1].begin(), adj[a-1].end(), b-1);
		if (s == adj[a-1].end()) adj[a-1].pb(b-1), adj[b-1].pb(a-1);
		else if (*s != b-1) adj[a-1].pb(b-1), adj[b-1].pb(a-1);
	}
	bfs(0);
	while(level[n-1] != INT32_MAX){
		fill(ptr.begin(), ptr.end(), 0);
		while (ll add = dfs(0, n-1, INT64_MAX)) flow += add;
		bfs(0);
	}
	cout << flow;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}