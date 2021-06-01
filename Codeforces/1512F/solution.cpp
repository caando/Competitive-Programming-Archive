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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		ll n, c;
		cin >> n >> c;
		ll a[n], b[n-1];
		forn(i, 0, n) cin >> a[i];
		forn(i, 0, n-1) cin >> b[i];
		ll curr = 0, job = 0, days = 0;
		ll low = INT64_MAX;
		forn(i, 0, n){
			if ((c-curr) / a[i] + (ll)((c-curr) % a[i] > 0 && c > curr) + days < low){
				low = (c-curr) / a[i] + (ll)((c-curr) % a[i] > 0 && c > curr) + days;
			}
			if (i != n-1){
				ll days_add = (b[i]-curr) / a[i] + (ll)((b[i] - curr) % a[i] > 0 && b[i] > curr);
				days += days_add + 1;
				curr += days_add * a[i] - b[i];
			}
		}
		cout << low << '\n';
	}
}