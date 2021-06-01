#include <bits/stdc++.h>
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
ll P = 1000000007;

int gcd(int a, int b){
    if (min(a, b) == 0) return max(a, b);
    else return gcd(min(a, b), max(a, b) % min(a, b));
}

int main(){
    int lcm = 1;
    forn(i, 1, 17) lcm = lcm * i / gcd(lcm, i);
    int n, m;
    cin >> n >> m;
    forn(i, 0, n){
        forn(j, 0, m){
            int t;
            cin >> t;
            if ((i+j)%2 ==0) cout << lcm << ' ';
            else cout << lcm + t*t*t*t << ' ';
        }
        cout << '\n';
    }
}