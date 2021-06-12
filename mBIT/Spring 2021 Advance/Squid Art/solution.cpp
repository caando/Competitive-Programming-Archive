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
const ll maxn = 200001;
vector<vector<bool>> graph;
vector<vector<bool>> visited;
vector<vector<int>> value;
int n, m;

pair<int, int> go(pair<int, int> pos, int dir){
	int x = pos.fi, y = pos.se;
	if (dir == 0) {
		if (y < m-1) return mp(x, y+1); 
	}else if (dir == 1 && x > 0){
		if (x & 1)return mp(x-1, y);
		else if (y < m-1) return mp(x-1, y+1);
	} else if (dir == 2 && x > 0) {
		if (x & 1 && y > 0) return mp(x-1, y-1);
		else return mp(x-1, y);
	} else if (dir == 3){
		if (y > 0) return mp(x, y-1);
	} else if (dir == 4 && x < n-1){
		if (x & 1 && y > 0) return mp(x+1, y-1);
		else return mp(x+1, y);
	} else if (dir == 5 && x < n-1) {
		if (x & 1) return mp(x+1, y);
		else if (y < m-1) return mp(x+1, y+1);
	}
	return mp(-1, -1);
}

int high = 0;
pair<int, int> high_pos;

set<pair<int, int>> bfs(pair<int, int> start, int val){
	queue<pair<int, int>> q;
	q.push(mp(start.fi, start.se));
	set<pair<int, int>> s;
	while (!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		if (!visited[curr.fi][curr.se]){
			visited[curr.fi][curr.se] = true;
			value[curr.fi][curr.se] = val;
			if (val > high) high = val, high_pos = curr;
			forn(i, 0, 6){
				pair<int, int> next = go(curr, i);
				if (next != mp(-1, -1)) {
					if (!visited[next.fi][next.se]){
						if (graph[curr.fi][curr.se] == graph[next.fi][next.se]) q.push(next);
						else s.insert(next);
					}
				}
			}
		}
	}
	return s;
}

void bfs2(pair<int, int> start){
	queue<pair<pair<int, int>, int>> q;
	q.push(mp(mp(start.fi, start.se), 0));
	while(!q.empty()){
		pair<int, int> curr = q.front().fi;
		int val = q.front().se;
		q.pop();
		if (!visited[curr.fi][curr.se]){
			set<pair<int, int>> in = bfs(curr, val);
			for (auto i : in) q.push(mp(i, val+1));
		}
	}
}

void solve(){
	cin >> n >> m;
	graph = vector<vector<bool>>(n, vector<bool>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m, 0));
	value = vector<vector<int>>(n, vector<int>(m, INT32_MAX));
	forn(i, 0, n){
		forn(j, 0, m){
			char temp;
			cin >> temp;
			if (temp == '1') graph[i][j] = true;
			else graph[i][j] = false;
		}
	}
	
	bfs2(mp(0, 0));
	/*forn(i, 0, n){
		forn(j, 0, m) cout << value[i][j];
		cout << endl;
	}*/
	visited = vector<vector<bool>>(n, vector<bool>(m, 0));
	value = vector<vector<int>>(n, vector<int>(m, INT32_MAX));
	high = 0;
	int ans = 0;
	if (!graph[high_pos.fi][high_pos.se]) ans++;
	bfs2(high_pos);/*
	forn(i, 0, n){
		forn(j, 0, m) cout << value[i][j];
		cout << endl;
	}*/
	cout << ans + high/2;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}