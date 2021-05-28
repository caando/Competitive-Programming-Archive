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
	int a, b;
	cin >> a >> b;
	int dp[a+1][b+1];
	forn(i, 0, a+1){
		forn(j, 0, b+1){
			if (i == j || i == 0 || j == 0) dp[i][j] = 0;
			else{
				int low = INT32_MAX;
				forn(k, 1, i){
					if (dp[k][j] + dp[i-k][j] < low) low = dp[k][j] + dp[i-k][j] + 1;
				}
				forn(k, 1, j){
					if (dp[i][k] + dp[i][j-k] < low) low = dp[i][k] + dp[i][j-k] + 1;
				}
				dp[i][j] = low;
			}
		}
	}
	cout << dp[a][b];
 
}