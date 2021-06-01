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
//using int128 = __int128_t;
ll P = 1000000007;

ll gcd(ll a, ll b){
	return a == 0 ? b : gcd(b % a, a);
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		ll n, m;
		cin >> n >> m;
		ll arr[n], start[n], high_curr = 0, delta = 0, high[n];
		forn(i, 0, n) {
			cin >> arr[i];
			delta += arr[i];
			start[i] = delta;
			if (delta > high_curr) high_curr = delta;
			high[i] = high_curr;
		}
		forn(i, 0, m){
			ll x;
			cin >> x;
			if (delta <= 0 && x > high_curr) cout << -1 << ' ';
			else {
				ll low_row = 0, high_row = INT64_MAX/high_curr, low_index = 0, high_index = n-1;
				if (delta <= 0) {
					while (low_index <= high_index){
						ll mid = low_index + (high_index - low_index)/2;
						if (delta * (low_row) + high[(mid % n)] < x){
							low_index = mid + 1;
						} else {
							high_index = mid - 1;
						}
					}
				} else {
					while (low_row <= high_row){
						ll mid = low_row + (high_row - low_row)/2;
						if (delta * mid + high_curr < x){
							low_row = mid + 1;
						} else {
							high_row = mid - 1;
						}
					}
					while (low_index <= high_index){
						ll mid = low_index + (high_index - low_index)/2;
						if (delta * (low_row) + high[(mid % n)] < x){
							low_index = mid + 1;
						} else {
							high_index = mid - 1;
						}
					}
				}
				cout << low_row * n + low_index << ' ';
			}
		}
		cout << '\n';
	}
}