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
int P = 998244353;
	
ll gcd(ll a, ll b){
	if (a == 0) return b;
	else if (b == 0) return a;
	return gcd(min(a, b), max(a, b) % min(a, b));
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
	
ll pow_mod(ll a, ll b, ll c){
	ll b_expo[63];
	b_expo[0] = a;
	for(int i = 1; i < 63; i++){
		b_expo[i] = (b_expo[i-1] * b_expo[i-1]) % c;
	}
	ll ans = 1;
	for(ll i = 62; i >= 0; i--){
		if (b >= ((ll)1 << i)){
			ans = (ans * b_expo[i]) % c;
			b-= ((ll)1 << i);
		}
	}
	return ans;
}

	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, p;
		cin >> n >> p;
		int a[n];
		forn(i, 0, n) cin >> a[i];
		vector<pair<int, int>> adjlist[n];
		forn(i, 0, n-1){
			adjlist[i].pb(mp(p, i+1));
			adjlist[i+1].pb(mp(p, i));
		}
		int curr = 1, index=0, v=a[0];
		while (curr < n){
			if (a[curr] % v == 0){
				adjlist[index].pb(mp(v, curr));
				adjlist[curr].pb(mp(v, index));
			} else {
				index = curr, v = a[curr];
			}
			curr++;
		}
		curr = n-2, index=n-1, v=a[n-1];
		while (curr >= 0){
			if (a[curr] % v == 0){
				adjlist[index].pb(mp(v, curr));
				adjlist[curr].pb(mp(v, index));
			} else {
				index = curr, v = a[curr];
			}
			curr--;
		}
		
		bool visited[n];
		forn(i, 0, n) visited[i] = false;
		ll weight = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		visited[0] = true;
		forn(i, 0, adjlist[0].size()) pq.push(adjlist[0][i]);
		while (!pq.empty()){
			auto curr = pq.top();
			pq.pop();
			if (!visited[curr.se]){
				visited[curr.se] = true;
				weight += curr.fi;
				forn(i, 0, adjlist[curr.se].size()) pq.push(adjlist[curr.se][i]);
			}
		}
		cout << weight << endl;
	}
}