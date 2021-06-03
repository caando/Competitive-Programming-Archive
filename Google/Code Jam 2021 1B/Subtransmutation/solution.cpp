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
	int t;
	cin >> t;
	forn(T, 0, t){
		int n, a, b;
		cin >> n >> a >> b;
		int arr[1000];
		forn(i, 0, 1000) arr[i] = 0;
		forn(i, 0, n) cin >> arr[i];
		int low = -1;
		forn(i, 0, 1000){
			bool poss = true;
			int curr[1000];
			forn(j, 0, 1000) curr[j] = 0;
			curr[i] = 1;
			for(int j = 999; j >= 0; j--){
				if (curr[j] > arr[j]) {
					if (j - a >= 0) {
						curr[j-a] = min(curr[j-a] + curr[j] - arr[j], 400);
					}
					if (j - b >= 0) {
						curr[j-b] = min(curr[j-b] + curr[j] - arr[j], 400);
					}
					curr[j] -= curr[j] - arr[j];
				} else if (arr[j] > curr[j]) {
					poss = false;
				}
			}
			if (poss) {
				low = i;
				break;
			}
		}
		if (low == -1) cout << "Case #" << T+1 << ": " << "IMPOSSIBLE" << '\n';
		else cout << "Case #" << T+1 << ": " << low + 1 << '\n';
	}

}