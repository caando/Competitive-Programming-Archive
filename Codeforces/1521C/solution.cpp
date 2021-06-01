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
		int n;
		cin >> n;
		int low_pos = -1;
		int arr[n];
		forn(i, 0, n) arr[i] = -1;
		forn(i, 0, n/2){
			cout << '?' << ' ' << 2 << ' ' << i*2 +1<< ' ' << i*2+2 << ' ' << 1 << endl;
			cout.flush();
			int temp;
			cin >> temp;
			if (temp == 1) low_pos = i*2;
			else if (temp == 2){
				cout << '?' << ' ' << 2 << ' ' << i*2 +2<< ' ' << i*2+1 << ' ' << 1 << endl;
				cout.flush();
				cin >> temp;
				if (temp == 1) low_pos = i*2 + 1;
			}
		}
		if ((n & 1) && low_pos == -1){
			cout << '?' << ' ' << 2 << ' ' << n-1 << ' ' << n << ' ' << 1 << endl;
			cout.flush();
			int temp;
			cin >> temp;
			if (temp == 1) low_pos = n-2;
			else if (temp == 2){
				cout << '?' << ' ' << 2 << ' ' << n << ' ' << n-1 << ' ' << 1 << endl;
				cout.flush();
				cin >> temp;
				if (temp == 1) low_pos = n-1;
			}
		}
		arr[low_pos] = 1;
		forn(i, 0, n){
			if (i != low_pos){
				cout << '?' << ' ' << 1 << ' ' << low_pos + 1 << ' ' << i + 1 << ' ' << n - 1 << endl;
				cout.flush();
				int temp;
				cin >> temp;
				arr[i] = temp;
			}
		}
		cout << "! ";
		forn(i, 0, n) cout << arr[i] << ' ';
		cout << endl;
		cout.flush();
		
	}
}