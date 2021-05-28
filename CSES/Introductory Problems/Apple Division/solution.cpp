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
	ll p[n];
	forn(i, 0, n) cin >> p[i];
	ll diff = INT64_MAX;
	forn(i, 0, (1 << (n))){
		ll a = 0, b = 0;
		forn(j, 0, n){
			if (i & (1 << j)){
				a += p[j];
			} else {
				b += p[j];
			}
		}
		if (abs(a-b) < diff) diff = abs(a-b);
	}
	cout << diff;
}