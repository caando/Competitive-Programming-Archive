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
	int n, t;
	cin >> n >> t;
	ll prev = 0;
	ll segmenttree[4*n];
	forn(i, 0, 4*n) segmenttree[i] = -1;

	while (t--){
		int k;
		cin >> k;
		cout.flush();
		ll low = 1, high = n, curr = 0, index = 1;
		while (low <= high){
			ll mid = (low + high)/2;
			ll temp = segmenttree[index];
			if (segmenttree[index] == -1){
				cout << '?' << ' ' << low << ' ' << mid << endl;
				cout.flush();
				cin >> temp;
				cout.flush();
				segmenttree[index] = temp;
			} 
			if ((mid - low + 1 - temp) + curr < k) {
				curr += (mid - low + 1 - temp);
				low = mid + 1;
				index = index * 2 + 1;
			} else {
				high = mid - 1;
				index *= 2;
			}
		}
		cout << '!' << ' ' << low << '\n';
		cout.flush();
		segmenttree[index]++;
		while (index != 0) {
			bool add = (index % 2 == 0);
			index /= 2;
			if (add) segmenttree[index]++;
		}
	}
}