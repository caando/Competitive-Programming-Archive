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

pair<int, int> segtree[4*(int)3e5+1];
int arr[(int)3e5+1];
vector<int> store[(int)3e5+1];

vector<int> query_res;

void build(int l, int r, int p){
	if (l == r) {
		segtree[p] = mp(arr[l], 1);
	} else {
		set<int> counter;
		forn(i, l, r+1){
			counter.insert(arr[i]);
		}
		ll high = 0, val = 0;
		for(auto it = counter.begin(); it != counter.end(); ++it) {
			int temp = upper_bound(store[(*it)-1].begin(), store[(*it)-1].end(), r) - lower_bound(store[(*it)-1].begin(), store[(*it)-1].end(), l);
			if (temp > high) {
				high = temp;
				val = (*it);
			}
		}
		segtree[p] = mp(val, high);
		build(l, (l+r)/2, p*2);
		build((l+r)/2+1, r, p*2+1);
	}
}

vector<int> query(int l, int r, int left, int right, int p){
	vector<int> res;
	if (l > r || left > right) return res;
	if (left == l && right == r){
		if(segtree[p].se > (right-left+1)/2) query_res.pb(segtree[p].fi);
		return res;
	} else {
		query(l, (l+r)/2, left, min(right, (l+r)/2), p*2);
		query((l+r)/2 + 1, r, max(left, (l+r)/2 + 1), right, p*2+1);
		return res;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	forn(i, 0, n) {
		cin >> arr[i];
		store[arr[i]-1].pb(i);
	}
	build(0, n-1, 1);
	forn(i, 0, q){
		int count = 0;
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		query_res.clear();
		query(0, n-1, a, b, 1);
		forn(i, 0, query_res.size()) {
			int temp = upper_bound(store[query_res[i]-1].begin(), store[query_res[i]-1].end(), b) - lower_bound(store[query_res[i]-1].begin(), store[query_res[i]-1].end(), a);
			if (temp > count) count = temp;
		}
		cout << max(1, 2 * count - (b-a+1)) << '\n';
	}
}