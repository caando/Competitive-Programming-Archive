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
typedef std::numeric_limits< double > dbl;
	
int main(){
	cout.precision(10);
	int n;
	cin >> n;
	double arr[n];
	forn(i, 0, n) cin >> arr[i];
	//forn(i, 0, n) arr[i] = 0;
	double l = -10000, r = 10000;
	double res = INT32_MAX;
	while (abs(r - l) > 0.00000000001){
		double mid1 = l + (r - l) / 3;
		double mid2 = l + (r - l) * 2 / 3;
		double low1 = 0, high1 = 0, low2 = 0, high2 = 0;
		double curr1 = 0, curr2 = 0;
		forn(i, 0, n) {
			curr1 += arr[i] + mid1;
			if (curr1 > 0) curr1 = 0;
			if (curr1 < low1) low1 = curr1;
			curr2 += arr[i] + mid1;
			if (curr2 < 0) curr2 = 0;
			if (curr2 > high1) high1 = curr2;
		}
		curr1 = 0, curr2 = 0;
		forn(i, 0, n) {
			curr1 += arr[i] + mid2;
			if (curr1 > 0) curr1 = 0;
			if (curr1 < low2) low2 = curr1;
			curr2 += arr[i] + mid2;
			if (curr2 < 0) curr2 = 0;
			if (curr2 > high2) high2 = curr2;
		}
		if (abs(high2) < abs(low2)){
			l = mid2;
		} else if(abs(low1) < abs(high1)) {
			r = mid1;
		} else {
			l = mid1;
			r = mid2;
		}
	}
	double mid1 = l + (r - l) / 3;
	double mid2 = l + (r - l) * 2 / 3;
	double low1 = 0, high1 = 0, low2 = 0, high2 = 0;
	double curr1 = 0, curr2 = 0;
	forn(i, 0, n) {
		curr1 += arr[i] + mid1;
		if (curr1 > 0) curr1 = 0;
		if (curr1 < low1) low1 = curr1;
		curr2 += arr[i] + mid1;
		if (curr2 < 0) curr2 = 0;
		if (curr2 > high1) high1 = curr2;
	}
	curr1 = 0, curr2 = 0;
	forn(i, 0, n) {
		curr1 += arr[i] + mid2;
		if (curr1 > 0) curr1 = 0;
		if (curr1 < low2) low2 = curr1;
		curr2 += arr[i] + mid2;
		if (curr2 < 0) curr2 = 0;
		if (curr2 > high2) high2 = curr2;
	}
	if (max(abs(low1), abs(high1)) < res) res = max(abs(low1), abs(high1));
	if (max(abs(low2), abs(high2)) < res) res = max(abs(low2), abs(high2));
	cout << res << '\n';
	
}