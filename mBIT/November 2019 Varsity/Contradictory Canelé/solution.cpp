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

void solve(){
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	if (n%a == 0 && m%b == 0) cout << "NO\n";
	else {
		cout << "YES\n";
		int pattern[a][b], count = -1*a*b/2;
		if (a&1 && b&1){
			forn(i, 0, (a-1)/2){
				forn(j, 0, (b-1)) pattern[i*2][j] = count, count++;
			}
			forn(i, 0, b/2){
				pattern[a-1][i*2] = count, count++;
			}
			forn(i, 0, a/2){
				pattern[i*2][b-1] = count, count++;
			}
			pattern[a-1][b-1] = count, count++;
			forn(i, 0, a/2){
				pattern[i*2+1][b-1] = count, count++;
			}
			forn(i, 0, b/2){
				pattern[a-1][i*2+1] = count, count++;
			}
			forn(i, 0, (a-1)/2){
				forn(j, 0, (b-1)) pattern[i*2+1][j] = count, count++;
			}

		} else if (a & 1){
			forn(i, 0, b/2){
				forn(j, 0, a) pattern[j][i*2] = count, count++;
			}
			count++;
			forn(i, 0, b/2){
				forn(j, 0, a) pattern[j][i*2+1] = count, count++;
			}
		} else {
			forn(i, 0, a/2){
				forn(j, 0, b) pattern[i*2][j] = count, count++;
			}
			count++;
			forn(i, 0, a/2){
				forn(j, 0, b) pattern[i*2+1][j] = count, count++;
			}
		}
		int board[n][m];
		forn(i, 0, n){
			forn(j, 0, m) board[i][j] = pattern[i%a][j%b];
		}
		/*
		forn(i, 0, a){
			forn(j, 0, b) cout << pattern[i][j] << ' ';
			cout << endl;
		}*/
		ll t = 0;
		forn(i, 0, n){
			forn(j, 0, m) cout << board[i][j] << ' ', t += board[i][j];
			cout << endl;
		}
		//cout << t << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(12) << fixed;
	solve();
}