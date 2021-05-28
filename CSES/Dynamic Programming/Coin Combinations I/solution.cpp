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
	ll n, x;
	cin >> n >> x;
	ll c[n], dp[x+1];
	forn(i, 0, n) cin >> c[i];
	dp[0] = 1;
	forn(i, 1, x+1) {
		dp[i] = 0;
		forn(j, 0, n){
			if (i - c[j] >= 0) dp[i] += dp[i-c[j]];
		}
		dp[i] %= P;
	}
	cout << dp[x];
}