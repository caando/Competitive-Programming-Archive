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
	if (a == 0) return b;
	else if (b == 0) return a;
	return gcd(min(a, b), max(a, b) % min(a, b));
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

ll b_expo[300001], dp[300001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	b_expo[0] = 1;
	for(int i = 1; i < 300001; i++){
		b_expo[i] = (b_expo[i-1] * 2) % P;
	}

	char board[n][m];
	ll count = -1, curr=1;
	forn(i, 0, n){
		forn(j, 0, m) {
			cin >> board[i][j];
			if (board[i][j] == 'o') count++;
		}
	}

	dp[count] = b_expo[count-1];
	for(int i = count-1; i >= 0; i--){
		if ((count - i) & 1){
			dp[i] = dp[i+1] - b_expo[i-1];
			if (dp[i] < 0) dp[i] += P;
		} else {
			dp[i] = dp[i+1] + b_expo[i-1];
			if (dp[i] > P) dp[i] -= P;
		}
	}

	int vert[n][m], hori[n][m];
	forn(i, 0, n){
		int curr= 0;
		forn(j, 0, m){
			if (board[i][j] == 'o'){
				curr++;
				hori[i][j] = max(curr-1, 0);
			} else {
				hori[i][j] = 0;
				curr=0;
			}
		}
	}
	forn(j, 0, m){
		int curr= 0;
		forn(i, 0, n){
			if (board[i][j] == 'o'){
				curr++;
				vert[i][j] =  max(curr-1, 0);
			} else {
				vert[i][j] = 0;
				curr=0;
			}
		}
	}
	ll total = 0;
	forn(i, 0, n){
		forn(j, 0, m){
			if (hori[i][j] != 0){
				total += dp[count - hori[i][j] + 1];
				if (total > P) total -= P;
			}
		}
	}
	forn(i, 0, n){
		forn(j, 0, m){
			if (vert[i][j] != 0){
				total += dp[count - vert[i][j] + 1];
				if (total > P) total -= P;
			}
		}
	}
	cout << total;
}