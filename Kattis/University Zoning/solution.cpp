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
int P = 1000000007;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll r, c, f, s, g;
    cin >> r >> c >> f >> s >> g;
    vector<pair<ll, ll>> fac[f];
    forn(i, 0, f){
        ll n;
        cin >> n;
        forn(j, 0, n){
            pair<ll, ll> temp;
            cin >> temp.fi >> temp.se;
            fac[i].pb(temp);
        }
        sort(fac[i].begin(), fac[i].end());
    }
    vector<pair<ll, pair<ll, ll>>> students[f];
    forn(i, 0, s){
        ll r, c, d, F;
        cin >> r >> c >> d >> F;
        pair<ll, pair<ll, ll>> temp;
        temp.fi = d;
        temp.se.fi = r;
        temp.se.se = c;
        students[F-1].pb(temp);
    }
    forn(i, 0, f) sort(students[i].begin(), students[i].end());
    ll cost[f];
    forn(i, 0, f) cost[i] = 0;
    ll t[f];
    forn(i, 0, f) cin >> t[i];
    forn(i, 0, f){
        vector<ll> lst;
        forn(j, 0, students[i].size()){
            ll c = abs(students[i][j].se.fi - fac[i][j].fi) + abs(students[i][j].se.se - fac[i][j].se);
            lst.pb(c);
        }
        sort(lst.begin(), lst.end());
        forn(j, 0, t[i]) cost[i] += lst[j];
    }
    ll total = 0;
    sort(cost, cost + f);
    forn(i, 0, g) total += cost[i];
    cout << total;
}