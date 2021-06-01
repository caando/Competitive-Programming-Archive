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

int main() {
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    ll low1=INT32_MAX, low2=INT32_MAX, low3=INT32_MAX;
    forn(i, 0, n1){
        ll temp;
        scanf("%lld", &temp);
        sum1+= temp;
        if (temp < low1) low1 = temp;
    }
    forn(i, 0, n2){
        ll temp;
        scanf("%lld", &temp);
        sum2+= temp;
        if (temp < low2) low2 = temp;
    }
    forn(i, 0, n3){
        ll temp;
        scanf("%lld", &temp);
        sum3+= temp;
        if (temp < low3) low3 = temp;
    }
    if (min(sum1, min(sum2, sum3)) < min(low1+low2, min(low2+low3, low1+low3))){
        cout << sum1+sum2+sum3 - 2* min(sum1, min(sum2, sum3)) << '\n';
    } else {
        cout << sum1+sum2+sum3 - 2 * min(low1+low2, min(low2+low3, low1+low3)) << '\n';
    }
}