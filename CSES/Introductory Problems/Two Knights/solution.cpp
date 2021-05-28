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
	ll n;
	cin >> n;
	ll C2[10001];
	C2[0] = 0;
	C2[1] = 0;
	ll minus[10001];
	minus[0] = 0;
	minus[1] = 0;
	minus[2] = 0;
	minus[3] = 8;
	forn(i, 4, 10001) {
		minus[i] = minus[i-1] + 2 * (i-1)*2 + 2*(i-2)*2 - 4;
	}
	forn(i, 2, 10001) {
		ll j = i * i;
		C2[i] = (j-1) * (2+j-2)/2;
	}
	forn(i, 1, n+1){
		cout << C2[i] - minus[i] << '\n';
	}
}