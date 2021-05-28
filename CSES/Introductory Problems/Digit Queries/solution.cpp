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
 
 
 
	ll q;
	cin >> q;
	forn(i, 0, q){
		ll k;
		cin >> k;
		ll curr = 1, high = 9, size = 1;
		while (k > high * size){
			k -= high * size;
			curr *= 10;
			high *= 10;
			size++;
		}
		k--;
		ll temp = curr + k/size;
		forn(i, 0, size-k % size-1){
			temp /= 10;
		}
		cout << temp % 10 << '\n';
	}
}