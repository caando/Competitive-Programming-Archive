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

ll norm(ll a, ll P) {
	while (a >= P) a -= P;
	while (a < 0) a += P;
	return a;
}

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

ll mul_mod(ll a, ll b, ll P) {
	return a * b % P;
}

int msb(ll a){
	for(int i = 62; i >= 0; i--){
		if (a & ((ll)1 << i)) return i + 1;
	}
	return 0;
}

ll inv(ll a, ll P) {
	return pow_mod(a, P - 2ll, P);
}

ll P = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int matrix[m][n];
	forn(i, 0, n){
		forn(j, 0, m) cin >> matrix[j][i];
	}
	ll invfact = 1, fact=1;
	forn(i, 2, n+1) invfact *= inv(i, P), invfact%=P, fact *= i;

	forn(j, 0, m){
		sort(matrix[j], matrix[j]+n);
	}

	ll total = 0;
	forn(i, 0, m){
		ll add = 0, counter = n, curr=fact;
		forn(j, 0, n){
			if (matrix[i][j] <= n){
				add += curr/counter * (n+1 - matrix[i][j]);
				curr -= curr/counter * (n+1 - matrix[i][j]);
				add %= P;
				counter--;
			}
		}
		total += add;
		total %= P;
	}
	ll ans = (total*invfact) % P;
	cout << ans; 
}