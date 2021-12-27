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
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t
    
void debug_out() { cerr << endl; }
    
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
    
#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200000;

int query(int a, int b, int c){
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}


void solve(){
	int n;
	cin >> n;
	int arr[n/3];
	int fa = -1, fb=-1;
	forn(i, 0, n/3){
		arr[i] = query(i*3+1, i*3+2, i*3+3);
		if (arr[i]) fa = i;
		else fb = i;
	}
	int a = fa*3+1, b = fa*3+2, c = -1;
	forn(i, 0, 3){
		if (!query(a, b, fb*3+1+i)) {
			c = fb*3+1+i;
		}
	}
	if (c == -1){
		if (!query(fb*3+1, fb*3+2, a)) {
			b = fb*3+1;
			c = -1;
		} else if (!query(fb*3+1, fb*3+3, a)){
			b = fb*3+1;
			c = -1;
		} else {
			b = fb*3+2;
			c = -1;
		}
	} else {
		a = fa*3+3;
		b = c;
		c = -1;
	}
	int ans[n];
	ans[a-1] = 1;
	ans[b-1] = 0;
	forn(i, 0, n/3){
		if (i*3 + 1 == a || i*3 + 2 == a || i*3 + 3 == a) {
			if (i*3+1 != a) ans[i*3] = query(a, b, i*3+1);
			if (i*3+2 != a) ans[i*3+1] = query(a, b, i*3+2);
			if (i*3+3 != a) ans[i*3+2] = query(a, b, i*3+3);
		} else if (i*3 + 1 == b || i*3 + 2 == b || i*3 + 3 == b) {
			if (i*3+1 != b) ans[i*3] = query(a, b, i*3+1);
			if (i*3+2 != b) ans[i*3+1] = query(a, b, i*3+2);
			if (i*3+3 != b) ans[i*3+2] = query(a, b, i*3+3);
		} else {
			if (arr[i]) {
				if (query(b, i*3+1, i*3+2)){
					ans[i*3] = 1;
					ans[i*3+1] = 1;
					ans[i*3+2] = query(a, b, i*3+3);
				} else {
					ans[i*3+2] = 1;
					if (query(a, b, i*3+1)){
						ans[i*3] = 1;
						ans[i*3+1] = 0;
					} else {
						ans[i*3] = 0;
						ans[i*3+1] = 1;
					}
				}
			} else {
				if (!query(a, i*3+1, i*3+2)){
					ans[i*3] = 0;
					ans[i*3+1] = 0;
					ans[i*3+2] = query(a, b, i*3+3);
				} else {
					ans[i*3+2] = 0;
					if (query(a, b, i*3+1)){
						ans[i*3] = 1;
						ans[i*3+1] = 0;
					} else {
						ans[i*3] = 0;
						ans[i*3+1] = 1;
					}
				}
			}
		}
	}
	int cnt = 0;
	forn(i, 0, n){
		if(ans[i]) cnt++;
	}
	cout << "! " << n - cnt << ' ';
	forn(i, 0, n){
		if (!ans[i]) cout << i + 1 << ' ';
	}
	cout << endl;
	cout.flush();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
	cin >> t;
	while(t--)solve();
}