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
	ll h[n], s[n];
	forn(i, 0, n) cin >> h[i];
	forn(i, 0, n) cin >> s[i];
	ll prev[x+1], curr[x+1];
	forn(j, 0, x+1) prev[j] = 0;
	curr[0] = 0;
	forn(i, 0, n){
		forn(j, 1, x+1) {
			curr[j] = max(curr[j-1], prev[j]);
			if (j - h[i] >= 0) {
				if (prev[j - h[i]] + s[i] > curr[j]) curr[j] = prev[j - h[i]] + s[i];
			}
		}
		forn(j, 1, x+1) {
			prev[j] = curr[j];
		}
	}
	cout << curr[x];
}