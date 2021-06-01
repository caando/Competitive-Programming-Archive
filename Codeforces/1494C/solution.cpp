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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		ll n, m;
		cin >> n >> m;
		vector<ll> al, ar, bl, br;
		forn(i, 0, n) {
			ll temp;
			cin >> temp;
			if (temp < 0) al.pb(temp);
			else ar.pb(temp);
		}
		forn(i, 0, m) {
			ll temp;
			cin >> temp;
			if (temp < 0) bl.pb(temp);
			else br.pb(temp);
		}
		forn(i, 0, al.size()) al[i] *= -1;
		sort(al.begin(), al.end());
		forn(i, 0, bl.size()) bl[i] *= -1;
		sort(bl.begin(), bl.end());

		int count_left[bl.size()], count_right[br.size()], curr = 0;

		for(int i = bl.size()-1; i >= 0; i--){
			auto temp = lower_bound(al.begin(), al.end(), bl[i]);
			if (temp != al.end()) if (*temp == bl[i]) {
				curr++;
			}
			count_left[i] = curr;
		}
		curr = 0;
		for(int i = br.size()-1; i >= 0; i--){
			auto temp = lower_bound(ar.begin(), ar.end(), br[i]);
			if (temp != ar.end()) if (*temp == br[i]) {
				curr++;
			}
			count_right[i] = curr;
		}

		int num_left[bl.size()];
		int num_right[br.size()];

		int curr1 = 0, curr2 = 0, count = 0;

		forn(i, 0, bl.size()){
			int temp = lower_bound(al.begin(), al.end(), bl[i]) - al.begin();
			while(temp != lower_bound(al.begin(), al.end(), bl[i] + temp) - al.begin()){
				temp = lower_bound(al.begin(), al.end(), bl[i] + temp) - al.begin();
			}
			num_left[i] = temp; 
		}

		forn(i, 0, br.size()){
			int temp = lower_bound(ar.begin(), ar.end(), br[i]) - ar.begin();
			while(temp != lower_bound(ar.begin(), ar.end(), br[i] + temp) - ar.begin()){
				temp = lower_bound(ar.begin(), ar.end(), br[i] + temp) - ar.begin();
			}
			num_right[i] = temp; 
		}
		
		int high1 = 0, high2 = 0;
		forn(i, 0, bl.size()){
			auto temp = upper_bound(bl.begin(), bl.end(), bl[i] + num_left[i]-1);
			int temp1 = 0;
			if (temp != bl.end()) temp1 = count_left[(temp-bl.begin())];
			if ((temp-bl.begin()) - i + temp1 > high1) high1= (temp-bl.begin()) - i + temp1;
		}
		forn(i, 0, br.size()){
			auto temp = upper_bound(br.begin(), br.end(), br[i] + num_right[i]-1);
			int temp1 = 0;
			if (temp != br.end()) temp1 = count_right[temp-br.begin()];
			if ((temp-br.begin()) - i + temp1 > high2) high2 = (temp-br.begin()) - i + temp1;
		}
	
		cout << high1 + high2 << '\n';	
	}
}