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
	dp[0][0] = 1;
	dp[0][1] = 1;
	forn(i, 1, 1000000){
		dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1]) % P;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2) % P;
	}
	int n;
	cin >> n;
	forn(i, 0, n){
		int temp;
		cin >> temp;
		cout << (dp[temp-1][0] + dp[temp-1][1]) % P << '\n';
	}
}