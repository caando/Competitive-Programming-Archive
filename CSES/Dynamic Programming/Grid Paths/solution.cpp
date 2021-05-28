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
	ll n;
	cin >> n;
	char grid[n][n];
	forn(i, 0, n){
		forn(j, 0, n) cin >> grid[i][j];
	}
	ll dp[n][n];
	forn(i, 0, n){
		forn(j, 0, n){
			if (i == j && i == 0 && grid[i][j] != '*') dp[i][j] = 1;
			else dp[i][j] = 0;
			if (grid[i][j] != '*'){
				if (i > 0) dp[i][j] += dp[i-1][j];
				if (j > 0) dp[i][j] += dp[i][j-1];
			}
			if (dp[i][j] > P) dp[i][j] -= P;
		}
	}
	cout << dp[n-1][n-1];
}