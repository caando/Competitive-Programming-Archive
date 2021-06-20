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
	
ll P = 1000000007;
ll dp[200001];
ll n, m;
vector<pair<ll, pair<ll, ll>>> steps;
queue<pair<int, ll>> q;
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	forn(i, 0, n){
		ll t, x, y;
		cin >> t >> x >> y;
		steps.pb(mp(t, mp(x, y)));
	}
	forn(i, 0, m+1) dp[i] = INT32_MAX;
	q.push(mp(0, 0));
	while (!q.empty()){
		int curr = q.front().fi;
		ll val = q.front().se;
		q.pop();
		if (curr != steps.size()) {
			q.push(mp(curr+1, val));
			if (steps[curr].fi == 1){
				ll count = val;
				forn(i, 0, steps[curr].se.se){
					ll add = steps[curr].se.fi;
					if (add % 100000 != 0) add += 100000 - (add % 100000);
					add /= 100000;
					count += add;
					if (count <= m) {
						if (curr + 1 < dp[count]) {
							dp[count] = curr + 1;
							q.push(mp(curr+1, count));
						} else break;
					} else break;
				} 
			} else if (steps[curr].fi == 2){
				ll count = val;
				count *= steps[curr].se.fi;
				if (count % 100000 != 0) count += 100000 - (count % 100000);
				count /= 100000;
				forn(i, 0, steps[curr].se.se){
					if (count <= m) {
						if (curr + 1 < dp[count]) {
							dp[count] = curr + 1;
							q.push(mp(curr+1, count));
						} else break;
					}
					if (steps[curr].se.fi > 100000){
						if (count <= m){
							count *= steps[curr].se.fi;
							if (count % 100000 != 0) count += 100000 - (count % 100000);
							count /= 100000;
						} else break;
					} else {
						count *= steps[curr].se.fi;
						if (count % 100000 != 0) count += 100000 - (count % 100000);
						count /= 100000;
					}
				}
			}
		}
	}

	forn(i, 1, m+1) {
		if (dp[i] != INT32_MAX) cout << dp[i] << ' ';
		else cout << -1 << ' ';
	}
	cout << '\n';
	
}