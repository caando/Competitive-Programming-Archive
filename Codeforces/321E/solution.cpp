#include <iostream>
#include <vector>
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

int prev_dp[4005], curr_dp[4005];
int precomp[4005][4005];
int mid, Index;
int l;
int n, k;

void DnC(int low, int high, int left, int right){
	mid = (low+high)/2, Index=0, l = INT32_MAX;
	for(k = left;k <= right; k++){
		if (prev_dp[k] + precomp[k+1][mid] <= l) {
			l = prev_dp[k] + precomp[k+1][mid];
			Index=k;
		} 
	}
	curr_dp[mid] = l;
	if (mid-1 >= low) DnC(low, mid-1, left, Index);
	if (high >= mid+1) DnC(mid+1, high, Index, right);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> k;
	cin.get();
	forn(i, 0, n){
		string s;
		getline(cin, s);
		forn(j, 0, n){
			precomp[i][j] = s[j*2] - '0';
		}
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = i+1; j < n; j++){
			precomp[i][j] += precomp[i+1][j];
		}
	}

	forn(i, 0, n){
		forn(j, 0, n){
			if (i < j) {
				precomp[i][j] += precomp[i][j-1];
			} else {
				precomp[i][j] = 0;
			}
		}
	}
	forn(i, 0, n){
		curr_dp[i] = precomp[0][i];
	}
	forn(i, 1, k){
		forn(j, 0, n) prev_dp[j] = curr_dp[j];
		DnC(0, n-1, 0, n-1);
	}
	cout << curr_dp[n-1];
}