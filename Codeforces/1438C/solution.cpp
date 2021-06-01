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
int P = 998244353;

int main() {
    ll t;
    scanf("%lld", &t);
    forn(i, 0, t){
        ll n, m;
        cin >> n >> m;
        ll table[n][m];
        forn(j, 0, n){
            forn(l, 0, m) {
                cin >> table[j][l];
                if ((table[j][l]%2 + (j+l)%2)%2 == 1) table[j][l]++;
            }
        }
        forn(j, 0, n){
            forn(l, 0, m) cout << table[j][l] << ' ';
            cout << '\n';
        }
    }
}