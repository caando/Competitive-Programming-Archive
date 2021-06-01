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

ll gcd(ll a, ll b){
	return a == 0 ? b : gcd(b % a, a);
}

vector<int> sieve;

void prime_sieve(int n){
	sieve.reserve(n+1);
	forn(i, 0, n+1) sieve[i] = i;
	forn(i, 2, n+1){
		if (sieve[i] == i){
			forn(j, 2, n/i+1){
				if (sieve[i*j] == i*j) sieve[i*j] = i;
			}
		}
	}
}

int parent[100000][25];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime_sieve(1e5);
	int n, q;
	cin >> n >> q;
	int arr[n];
	forn(i, 0, n) {
		cin >> arr[i];
	}
	int counter[100001];
	int limits[n];
	forn(i, 0, 1e5+1) counter[i] = n;
	for(int i = n-1; i >= 0; i--){
		int curr = arr[i];
		limits[i] = n;
		set<int> store;
		while (curr != 1){
			if (counter[sieve[curr]] < limits[i]) limits[i] = counter[sieve[curr]];
			store.insert(sieve[curr]);
			curr /= sieve[curr];
		}
		for(auto it = store.begin(); it != store.end(); ++it) counter[(*it)] = i;
	}

	int segments[n];
	int curr = n;
	for(int i = n-1; i >= 0; i--){
		if (limits[i] < curr) curr = limits[i];
		segments[i] = curr;
	}
	forn(i, 0, n){
		forn(j, 0, 25) parent[i][j] = n;
	}
	forn(i, 0, n){
		parent[i][0] = segments[i];
	}
	forn(j, 1, 25){
		for(int i = n-1; i >= 0; i--){
			if(parent[i][j-1] < n) parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
	forn(i, 0, q){
		int l, r, count;
		count = 0;
		cin >> l;
		cin >> r;
		l--;
		r--;
		if (r < n){
			curr = l;
			while (curr <= r && count < n){
				int step = 0;
				while (parent[curr][step+1] <= r && step + 1 < 25 && parent[curr][step+1] != curr) {
					step++;
				}
				count += (1 << step);
				curr = parent[curr][step];
			}
			cout << count << '\n';
		}
	}
	
}