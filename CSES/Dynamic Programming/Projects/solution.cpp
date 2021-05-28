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
	pair<pair<ll, ll>, ll> arr[n];
	ll p[n];
	forn(i, 0, n) cin >> arr[i].fi.se >> arr[i].fi.fi >> arr[i].se;
	sort(arr, arr+n);
	ll dp[n][2];
	dp[0][0] = arr[0].se;
	dp[0][1] = 0;
	forn(i, 1, n){
		int low = 0, high = n;
		while (low <= high) {
			int mid = low + (high - low)/2;
			if (arr[mid].fi.fi >= arr[i].fi.se){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
		if (low == 0){
			dp[i][0] = arr[i].se;
		} else {
			dp[i][0] = max(dp[low-1][0], dp[low-1][1]) + arr[i].se;
		}
	}
	cout << max(dp[n-1][0], dp[n-1][1]);
 
}