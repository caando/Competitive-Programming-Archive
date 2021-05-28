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
	ll arr[n];
	forn(i, 0, n){
		arr[i] = 0;
		if (i <= 5) arr[i]++;
		forn(j, 1, 7){
			if (i - j >= 0){
				arr[i] = (arr[i] + arr[i-j]) % P;
			}
		}
	}
	cout << arr[n-1];
}