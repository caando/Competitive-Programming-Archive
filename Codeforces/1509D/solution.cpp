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
	int T = t;
	while (T--){
		int n;
		cin >> n;
		char s[3][2*n];
		pair<int, int> count[3];
		forn(j, 0, 3){
			forn(i, 0, 2*n) {
				cin >> s[j][i];
				if (s[j][i] == '0') count[j].fi++;
				else count[j].se++;
			}
		}
		vector<pair<int, int>> combi;
		forn(i, 0, 3){
			forn(j, 0, 3) if (i != j) combi.pb(mp(i, j));
		}
		forn(i, 0, combi.size()){
			int a = 0, b = 0, counter = 0;
			if (min(count[combi[i].fi].fi, count[combi[i].se].fi) >= n){
				while (a < 2*n || b < 2*n){
					if (a == 2*n) {
						cout << s[combi[i].se][b];
						b++;
					} else if (b == 2*n){
						cout << s[combi[i].fi][a];
						a++;
					} else if (s[combi[i].fi][a] == s[combi[i].se][b]) {
						cout << s[combi[i].fi][a];
						a++;
						b++;
					} else if (s[combi[i].fi][a] == '1'){
						cout << s[combi[i].fi][a];
						a++;
					} else {
						cout << s[combi[i].se][b];
						b++;
					}
					counter++;
				}
				while (counter < 3*n) {
					cout << '0';
					counter++;
				}
				cout << '\n';
				break;
			} else if (min(count[combi[i].fi].se, count[combi[i].se].se) >= n){
				while (a < 2*n || b < 2*n){
					if (a == 2*n) {
						cout << s[combi[i].se][b];
						b++;
					} else if (b == 2*n){
						cout << s[combi[i].fi][a];
						a++;
					} else if (s[combi[i].fi][a] == s[combi[i].se][b]) {
						cout << s[combi[i].fi][a];
						a++;
						b++;
					} else if (s[combi[i].fi][a] == '0'){
						cout << s[combi[i].fi][a];
						a++;
					} else {
						cout << s[combi[i].se][b];
						b++;
					}
					counter++;
				}
				while (counter < 3*n) {
					cout << '0';
					counter++;
				}
				cout << '\n';
				break;
			}
		}
		
	}	
}