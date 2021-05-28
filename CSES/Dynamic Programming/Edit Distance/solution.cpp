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
	string a, b;
	cin >> a >> b;
	int dp[a.size()+1][b.size()+1];
	forn(i, 0, a.size()+1) dp[i][0] = i;
	forn(i, 0, b.size()+1) dp[0][i] = i;
	forn(i, 1, a.size()+1){
		forn(j, 1, b.size()+1){
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
			}
		}
	}
	cout << dp[a.size()][b.size()];
 
}