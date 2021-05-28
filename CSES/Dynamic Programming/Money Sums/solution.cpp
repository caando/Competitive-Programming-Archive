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
ll dp[1000000][2];
 
int main(){
	int n;
	cin >> n;
	int c[n];
	forn(i, 0, n) cin >> c[i];
	bool dp[n+1][n*1000+1];
	forn(i, 0, n+1) dp[i][0] = true;
	forn(i, 1, n*1000+1) dp[0][i] = false;
	forn(i, 1, n+1){
		forn(j, 1, n*1000+1){
			dp[i][j] = dp[i-1][j];
			if (j - c[i-1] >= 0) {
				if (dp[i-1][j-c[i-1]]) dp[i][j] = dp[i-1][j-c[i-1]];
			}
		}
	}
	int count = 0;
	forn(i, 1, n*1000+1){
		if (dp[n][i]) count++;
	}
	cout << count << '\n';
	forn(i, 1, n*1000+1){
		if (dp[n][i]) cout << i << ' ';
	}
 
}