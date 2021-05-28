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
	ll x;
	cin >> x;
	ll dp[x+1];
	dp[0] = 0;
	forn(i, 1, x+1) {
		ll curr = i;
		dp[i] = INT64_MAX;
		while (curr > 0){
			ll digit = curr % 10;
			curr /= 10;
			if (dp[i] > dp[i-digit] + 1 && digit != 0) dp[i] = dp[i-digit] + 1;
		}
	}
	cout << dp[x];
}