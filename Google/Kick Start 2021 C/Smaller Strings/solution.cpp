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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(T, 0, t){
		ll n, k, ans;
		cin >> n >> k;
		string s;
		cin >> s;
		ll count = 0;
		string build, build1, back, front;
		forn(i, 0, (n/2+n%2)){
			count *= k;
			count += min((ll)(s[i] - 'a'), k-1);
			count %= P;
			build += (char)('a' + min((ll)(s[i] - 'a'), k-1));
		}
		forn(i, 0, n/2){
			build1 = build[i] + build1;
		}
		if (build + build1 < s) count++;
		count %= P;
		cout << "Case #" << T + 1 << ": " << count << endl;
	}
}