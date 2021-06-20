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
#define MOD 998244353

ll gcd(ll a, ll b) {
	return b ? gcd (b, a % b) : a;
}

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
	
ll pow_mod(ll a, ll b, ll c){
	ll b_expo[63];
	b_expo[0] = a;
	for(int i = 1; i < 63; i++){
		b_expo[i] = (b_expo[i-1] * b_expo[i-1]) % c;
	}
	ll ans = 1;
	for(ll i = 62; i >= 0; i--){
		if (b >= ((ll)1 << i)){
			ans = (ans * b_expo[i]) % c;
			b-= ((ll)1 << i);
		}
	}
	return ans;
}

int msb(ll a){
	for(int i = 62; i >= 0; i--){
		if (a & ((ll)1 << i)) return i + 1;
	}
	return 0;
}

ll norm(ll a) {
	while (a >= MOD)
		a -= MOD;
	while (a < 0)
		a += MOD;
	return a;
}

ll mul(ll a, ll b) {
	return (a * 1ll * b % MOD);
}

ll binPow(ll a, ll k) {
	ll ans = 1;
	while (k > 0) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

ll inv(ll a) {
	return binPow(a, MOD - 2);
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		char arr[n];
		int zeros = 0, diff = 0;
		forn(i, 0, n) {
			cin >> arr[i];
			if (arr[i] == '0') zeros++;
		}
		bool is_p = true;
		forn(i, 0, n/2){
			if (arr[i] != arr[n-i-1]) is_p = false, diff++; 
		}
		if (is_p){
			if(zeros%2 == 1 && zeros != 1) cout << "ALICE\n";
			else cout << "BOB\n";
		} else {
			zeros -= diff;
			if (zeros == 0) cout << "ALICE\n";
			else if(zeros == 1){
				if (diff == 1) cout << "DRAW\n";
				else cout << "ALICE\n"; 
			} else if (zeros%2 == 1){
				cout << "ALICE\n";
			} else {
				if (diff == 1) cout << "ALICE\n";
				else if (diff == 2) cout << "ALICE\n";
				else cout << "ALICE\n";
			}
		}
	}
}