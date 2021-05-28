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
	ll x[n];
	forn(i, 0, n) cin >> x[i];
	pair<ll, ll> dp[n][n];
	forn(i, 0, n){
		dp[i][i].fi = x[i];
		dp[i][i].se = 0;
	}
	for(int i = n-1; i >= 0; i--){
		forn(j, i+1, n){
			dp[i][j].fi = max(dp[i+1][j].se + x[i], dp[i][j-1].se + x[j]);
			dp[i][j].se = min(dp[i+1][j].fi, dp[i][j-1].fi);
		}
	}
	cout << dp[0][n-1].fi;
 
}