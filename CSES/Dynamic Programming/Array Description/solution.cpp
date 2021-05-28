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
 
 
int main(){
	int n, m;
	cin >> n >> m;
	int x[n];
	forn(i, 0, n) cin >> x[i];
	ll dp[n][m];
	forn(j, 0, m){
		if (x[0] == 0 || x[0] - 1 == j) dp[0][j] = 1;
		else dp[0][j] = 0;
	}
	forn(i, 1, n){
		forn(j, 0, m){
			dp[i][j] = 0;
			if (x[i] == 0 || j == x[i] - 1){
				if (j > 0) dp[i][j] += dp[i-1][j-1];
				dp[i][j] += dp[i-1][j];
				if (j < m-1) dp[i][j] += dp[i-1][j+1];
				if (dp[i][j] > P) dp[i][j] %= P;
			} else dp[i][j] = 0;
		}
	}
	ll res = 0;
	forn(j, 0, m){
		res += dp[n-1][j];
		if (res > P) res %= P;
	}
	cout << res;
}