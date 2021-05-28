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
	int n;
	cin >> n;
	if (n*(1+n)/2 % 2 == 1) cout << 0;
	else{
		ll dp[n*(1+n)/2/2+1];
		forn(i, 1, n*(1+n)/2/2+1) dp[i] = 0;
		dp[0] = 1;
		forn(i, 1, n+1){
			for(int j = n*(1+n)/2/2; j >= 0; j--){
				if (j - i >= 0) {
					dp[j] += dp[j-i];
					if (dp[j] > P*2) dp[j] -= P*2;
				}
			}
		}
		cout << dp[n*(1+n)/2/2]/2;
	}
 
}