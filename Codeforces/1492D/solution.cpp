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
	int a, b, k;
	cin >> a >> b >> k;
	if (k > 0 && (b <= 1 || k + 1 >= a+b || a == 0)){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		int c = a, d = b;

		while((b > 0 && k == 0) || (b > 1 && a+b > k+1)){
			cout << '1';
			b--;
		}
		while((a > 0 && k == 0) || (a > 1 && a+b > k+1)){
			cout << '0';
			a--;
		}
		if (b && k) {
			cout << '1';
			b--;
		}
		forn(i, 0, b) cout << '1';
		forn(i, 0, a-(k > 0)) cout << '0';
		if (a && k) cout << '0';

		cout << '\n';

		while((d > 0 && k == 0) || (d > 1 && c+d > k+1)){
			cout << '1';
			d--;
		}
		while((c > 0 && k == 0) || (c > 1 && c+d > k+1)){
			cout << '0';
			c--;
		}
		if (c && k) {
			cout << '0';
			c--;
		}
		forn(i, 0, d-(k > 0)) cout << '1';
		forn(i, 0, c) cout << '0';
		if (d && k) cout << '1';
	}
	
}