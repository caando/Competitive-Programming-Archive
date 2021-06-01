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
int P = 998244353;
	
ll gcd(ll a, ll b){
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
	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m, k;
		cin >> m >> k;
		int arr[m], curr = 0, h = 0, h2 = 0, index = 0, index2 = 0;
		forn(i, 0, k){
			int temp;
			cin >> temp;
			if (temp > h) h2 = h, index2 = index, h = temp, index = i+1;
			else if (temp > h2) h2 = temp, index2 = i+1;
			forn(j, 0, temp) arr[curr] = i+1, curr++;
		}
		int high = INT32_MAX, low = 0;
		while (low <= high){
			ll mid = low + (high - low)/2;
			if ((mid*((mid/2)+(mid&1)) >= h) && (mid*mid - (mid/2) * (mid/2) >= m)){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		curr = 0;
		int matrix[low][low];
		forn(i, 0, low){
			forn(j, 0, low) matrix[i][j] = 0;
		}
		forn(i, 0, (low/2) + (low&1)){
			forn(j, 0, (low/2)) {
				if (h > 0) matrix[i*2][j*2+1] = index, h--;
				else if (curr < m) {
					while (arr[curr] == index && curr < m) curr++;
					if (curr >= m) break;
					matrix[i*2][j*2+1] = arr[curr], curr++;
				}
			}
		}
		forn(i, 0, (low/2) + (low&1)){
			forn(j, 0, (low/2) + (low&1)) {
				if (h>0) matrix[i*2][j*2] = index, h--;
				else {
					while (arr[curr] == index && curr < m) curr++;
					if (curr >= m) break;
					matrix[i*2][j*2] = arr[curr], curr++;
				}
			}
		}
		forn(i, 0, (low/2)){
			forn(j, 0, (low/2) + (low&1)) {
				if (curr < m) {
					while (arr[curr] == index && curr < m) curr++;
					if (curr >= m) break;
					else matrix[i*2+1][j*2] = arr[curr], curr++;
				}
			}
		}
		cout << low << '\n';
		forn(i, 0, low){
			forn(j, 0, low) cout << matrix[i][j] << ' ';
			cout << '\n';
		}
	}
}