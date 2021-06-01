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
#define P 998244353

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

int msmb(ll a){
	for(int i = 62; i >= 0; i--){
		if (a & ((ll)1 << i)) {
			for(int j = i-1; j >= 0; j--){
				if (!(a & ((ll)1 << j))) return j+1;
			}
			return 0;
		}
	}
	return 0;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n], res = INT32_MAX;
	cin >> arr[0];
	forn(i, 1, n) {
		cin >> arr[i];
		if (arr[i] < arr[i-1]) res = 0;
	}
	forn(i, 0, n-2){
		if (msb(arr[i]) == msb(arr[i+1]) && msb(arr[i+1]) == msb(arr[i+2])) if (res > 1) res = 1;
	}
	if (res <= 1) cout << res;
	else {
		forn(i, 0, n-1){
			int curr = 0;
			forn(j, i+1, n){
				curr ^= arr[j];
				int curr1 = 0;
				for(int k = i; k >= 0; k--){
					curr1 ^= arr[k];
					if (curr1 > curr) if (j - i - 1 + (i - k) < res) {
						res = j - i - 1 + (i - k);
					}
				}
			}
		}
		if (res == INT32_MAX) cout << -1;
		else cout << res;
	}
}