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
ll p = 1000000007;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin >> n;
	ll dp[n+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	forn(i, 3, n+1) dp[i] = ((i-1) * (dp[i-1] +  dp[i-2])) % p;
	cout << dp[n]; 
}