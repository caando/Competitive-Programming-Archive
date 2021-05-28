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
ll dp[1000000][2];
 
int main(){
	int n;
	cin >> n;
	vector<int> lis;
	forn(i, 0, n){
		int temp;
		cin >> temp;
		int high = lis.size();
		int low = 0;
		while (low <= high && lis.size() > 0){
			int mid = low + (high - low)/2;
			if (lis[mid] >= temp){
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
 
		//cout << low << ' ' << high << '\n';
		if (low >= lis.size()) lis.pb(temp);
		else if (lis[low] > temp) lis[low] = temp;
		//forn(j, 0, lis.size()) cout << lis[j] << ' ';
		//cout << '\n';
	}
	cout << lis.size();
 
}