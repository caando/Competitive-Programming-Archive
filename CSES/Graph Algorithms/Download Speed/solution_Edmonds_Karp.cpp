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

vector<vector<ll>> capacity;
vector<vector<ll>> adj;
ll n, m;

// Edmonds Karp
ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push(mp(s, INT64_MAX));
    while (!q.empty()) {
        ll curr = q.front().fi;
        ll flow = q.front().se;
        q.pop();
        forn (i, 0, adj[curr].size()) {
			if (parent[adj[curr][i]] == -1 && capacity[curr][adj[curr][i]]) {
                parent[adj[curr][i]] = curr;
                ll next = min(flow, capacity[curr][adj[curr][i]]);
                if (adj[curr][i] == t) return next;
                q.push(mp(adj[curr][i], next));
            }
        }
    }
    return 0;
}

void solve(){
	cin >> n >> m;
	forn(i, 0, n){
		capacity.pb(vector<ll>(n, 0));
		adj.pb(vector<ll>());
	}
	forn(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		capacity[a-1][b-1] += c;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	ll flow = 0, next_flow;
	vector<ll> parent(n);
	while (next_flow = bfs(0, n-1, parent)){
		flow += next_flow;
		ll curr = n-1;
		while (curr != 0){
			ll prev = parent[curr];
			capacity[prev][curr] -= next_flow;
			capacity[curr][prev] += next_flow;
			curr = prev;
		}
	}
	cout << flow << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}