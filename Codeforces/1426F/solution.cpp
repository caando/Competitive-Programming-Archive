#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i,m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair

ll pow_mod_k (ll a, ll b) {
  if (b >= 0){
    ll result = 1 ;
    while (b--) {
      result *= a;
      result %= 1000000007;
    }
    return result;
  }
  return 1;
}

int main() {
  ll n;
  cin >> n;
  ll prime = 1000000007;
  char abc[n];
  ll q_num = 0;
  forn(i, 0, n) {
    cin >> abc[i];
    if (abc[i] == '?') q_num++;
  }
  ll a0=0, b0=0, c0=0, a1=0, b1=0, c1=0, b2=0, c2=0, c3=0;
  forn(i, 0, n){
    if (abc[i] == 'a') a0++;
    else if (abc[i] == 'b') {
      b0 = (b0 + a0);
      b1 = (b1 + a1);
    } else if (abc[i] == 'c') {
      c0 = (c0 + b0);
      c1 = (c1 + b1);
      c2 = (c2 + b2);
    } else{
      c1 = (c1 + b0);
      c2 = (c2 + b1);
      c3 = (c3 + b2);
      b1 = (b1 + a0);
      b2 = (b2 + a1);
      a1++;
    }
  }
  cout << ((c0 % prime) * pow_mod_k(3, q_num) + (c1 % prime) * pow_mod_k(3, q_num-1) + (c2 % prime) * pow_mod_k(3, q_num-2) + (c3 % prime) * pow_mod_k(3, q_num-3)) % 1000000007;

}