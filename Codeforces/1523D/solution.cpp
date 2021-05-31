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

int countSetBits(ll n){
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

ll P = 1000000007;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, m, p;
	cin >> n >> m >> p;
	ll arr[n];
	vector<int> vec[n];
	forn(i, 0, n){
		arr[i] = 0ll;
		forn(j, 0, m){
			char temp;
			cin >> temp;
			if (temp == '1') arr[i] += (1ll << j), vec[i].pb(j);
		}
	}
	ll high = 0ll, high1 = 0ll;
	forn(i, 0, 25){
		int x = rng() % n;

		int counter[1ll << vec[x].size()], counter1[1ll << vec[x].size()];
		forn(j, 0, (1ll << vec[x].size())) counter[j] = 0, counter1[j] = 0;
		forn(j, 0, n){
			ll val = arr[j] & arr[x], mask=0;
			forn(k, 0, vec[x].size()){
				if (val & (1ll << vec[x][k])) mask += (1ll << k);
			}
			counter[mask]++;
		}
		forn(j, 0, (1ll << vec[x].size())){
			for (int k=j; k; k=(k-1)&j) counter1[k] += counter[j];
		}
		forn(j, 0, (1ll << (vec[x].size()))) {
			if (counter1[j] >= n/2 + n%2) {
				ll curr = 0, count = 0;
				forn(k, 0, vec[x].size()){
					if (j & (1 << k)) curr += (1ll << vec[x][k]), count++;
				}
				if (count > high){
					high = count, high1 = curr;
				}
			}
		}
	}
	forn(i, 0, m) {
		if (high1 & (1ll << i)) cout << '1';
		else cout << '0';
	}
}