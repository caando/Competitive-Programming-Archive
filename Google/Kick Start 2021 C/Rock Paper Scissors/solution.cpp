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
void NCR(int n){
	nCr.reserve(n+1);
	forn(i, 0, n+1) {
		vector<ll> v(n+1);
		nCr.pb(v);
	}
	forn(i, 0, n+1) nCr[i][i] = 1, nCr[i][0] = 1;
	forn(i, 1, n+1){
		forn(j, 1, i) nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
	}
}

ll P = 1000000007;

pair<double, char> dp[61][61][61];
double high = 0;
int x, y, z;
double w, e;
 
double topdown(int i, int j, int k){
	if(dp[i][j][k].fi != -1) return dp[i][j][k].fi;
	double curr = 0;
	char c = 'R';
	if (i > 0) {
		if (topdown(i-1, j, k) + (w*j)/(i+j+k-1) + (e*(k))/(i+j+k-1) > curr) {
			curr = dp[i-1][j][k].fi + (w*j)/(i+j+k-1) + (e*(k))/(i+j+k-1);
			c = 'R';
		}
	}
	if (j > 0) {
		if (topdown(i, j-1, k) + (w*k)/(i+j+k-1) + (e*(i))/(i+j+k-1) > curr) {
			curr = dp[i][j-1][k].fi + (w*k)/(i+j+k-1) + (e*(i))/(i+j+k-1);
			c = 'P';
		}
	}
	if (k > 0) {
		if (topdown(i, j, k-1) + (w*i)/(i+j+k-1) + (e*(j))/(i+j+k-1) > curr) {
			curr = dp[i][j][k-1].fi + (w*i)/(i+j+k-1) + (e*(j))/(i+j+k-1);
			c = 'S';
		}
	}
	dp[i][j][k].fi = curr;
	dp[i][j][k].se = c;
	if (i + j + k == 60) {
		if (curr > high) high = curr, x = i, y = j, z = k;
	}
	return dp[i][j][k].fi;
}

string backtrack(int i, int j, int k){
	if (dp[i][j][k].se == 'R') return backtrack(i-1, j, k) + 'R';
	if (dp[i][j][k].se == 'P') return backtrack(i, j-1, k) + 'P';
	if (dp[i][j][k].se == 'S') return backtrack(i, j, k-1) + 'S';
	return "";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t, m;
	cin >> t >> m;
	forn(T, 0, t) {
		int r=0, p=0, s=0;
		cin >> w >> e;
		cout << "Case #" << T+1 << ": ";
		forn(i, 0, 61){
			forn(j, 0, 61){
				forn(k, 0, 61) dp[i][j][k].fi = -1;
			}
		}
		dp[1][0][0].fi = w/3 + e/3;
		dp[0][1][0].fi = w/3 + e/3;
		dp[0][0][1].fi = w/3 + e/3;
		dp[1][0][0].se = 'R';
		dp[0][1][0].se = 'P';
		dp[0][0][1].se = 'S';
		dp[0][0][0].se = ' ';
		high = 0;
		topdown(60, 60, 60);

		cout << backtrack(x, y, z);
		cout << endl;
	}
}