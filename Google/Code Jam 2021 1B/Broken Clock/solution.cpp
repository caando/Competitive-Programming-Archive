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
	int t;
	cin >> t;
	forn(T, 0, t){
		ll a, b, c;
		cin >> a >> b >> c;
		ll t = 360*120000000000;
		ll s = -1, m = -1, h = -1;
		ll d=-1, e=-1, f=-1;
		ll diff;

		// Case 1
		diff = b-a;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = c - (a - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}

		// Case 2
		diff = c-a;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = b - (a - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}

		// Case 3
		diff = a-b;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = c - (b - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}

		// Case 4
		diff = c-b;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = a - (b - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}

		// Case 5
		diff = a-c;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = b - (c - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}

		// Case 6
		diff = b-c;
		forn(i, 0, 12){
			e = (diff+t*i/12)*12/11;
			d = e - diff;
			f = a - (c - d);
			if (d < 0) d += t;
			if (e < 0) e += t;
			if (f < 0) f += t;
			d %= t;
			e %= t;
			f %= t;
			//cout << d << ' ' << e << ' ' << f << '\n';
			if ((d)*720%t == (f)  && (d)*12%t == (e)){
				h = (d);
				m = (e);
				s = (f);
			}
		}
		if (s == -1) cout << "rip";
		cout << "Case #" << T+1 << ": " << h*12/t << ' ' << m*60/t << ' ' << s*60/(t) << ' ' << s%(t/60)/720 << '\n';
	}

}