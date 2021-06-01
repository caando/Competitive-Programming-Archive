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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	pair<ll, int> A[a], B[b], C[c], D[d];
	forn(i, 0, a) cin >> A[i].fi, A[i].se = i;
	forn(i, 0, b) cin >> B[i].fi, B[i].se = i;
	forn(i, 0, c) cin >> C[i].fi, C[i].se = i;
	forn(i, 0, d) cin >> D[i].fi, D[i].se = i;
	sort(A, A+a);
	sort(D, D+d);
	int m1;
	cin >> m1;
	vector<int> E[b];
	forn(i, 0, m1){
		int fi, se;
		cin >> fi >> se;
		E[se-1].pb(fi-1);
	}
	forn(i, 0, b) {
		sort(E[i].begin(), E[i].end());
		bool found = false;
		ll low = INT64_MAX;
		forn(j, 0, a){
			if (B[i].fi + A[j].fi > low) break;
			auto temp = lower_bound(E[i].begin(), E[i].end(), A[j].se);
			if (temp == E[i].end()){
				B[i].fi += A[j].fi;
				found = true;
				if (B[i].fi < low) low = B[i].fi;
				break;
			} else if ((*temp) != A[j].se) {
				B[i].fi += A[j].fi;
				found = true;
				if (B[i].fi < low) low = B[i].fi;
				break;
			}
		}
		if (!found){
			B[i].fi += INT32_MAX;
		}
	}
	int m2;
	cin >> m2;
	vector<int> G[b];
	forn(i, 0, m2){
		int fi, se;
		cin >> fi >> se;
		G[fi-1].pb(se-1);
	}
	int m3;
	cin >> m3;
	vector<int> F[c];
	forn(i, 0, m3){
		int fi, se;
		cin >> fi >> se;
		F[fi-1].pb(se-1);
	}
    
	forn(i, 0, c) {
		sort(F[i].begin(), F[i].end());
		bool found = false;
		ll low = INT64_MAX;
		forn(j, 0, d){
			if (D[j].fi + C[i].fi > low) break;
			auto temp = lower_bound(F[i].begin(), F[i].end(), D[j].se);
			if (temp == F[i].end()){
				C[i].fi += D[j].fi;
				found = true;
				if (C[i].fi < low) low = C[i].fi;
				break;
			} else if ((*temp) != D[j].se) {
				C[i].fi += D[j].fi;
				found = true;
				if (C[i].fi < low) low = C[i].fi;
				break;
			}
		}
		if (!found){
			C[i].fi += INT32_MAX;
		}
	}
	sort(C, C+c);
	forn(i, 0, b) {
		sort(G[i].begin(), G[i].end());
		bool found = false;
		ll low = INT64_MAX;
		forn(j, 0, c){
			if (B[i].fi + C[j].fi > low) break;
			auto temp = lower_bound(G[i].begin(), G[i].end(), C[j].se);
			if (temp == G[i].end()){
				B[i].fi += C[j].fi;
				found = true;
				if (B[i].fi < low) low = C[j].fi;
				break;
			} else if ((*temp) != C[j].se) {
				B[i].fi += C[j].fi;
				found = true;
				if (B[i].fi < low) low = C[j].fi;
				break;
			}
		}
		if (!found){
			B[i].fi += INT32_MAX;
		}
	}
	sort(B, B+b);
	if (B[0].fi < INT32_MAX) cout << B[0].fi << '\n';
	else cout << -1 << '\n';
}