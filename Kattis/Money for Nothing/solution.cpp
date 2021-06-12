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
vector<pair<ll, ll>> p1, c1, p2, c2;
ll ans = 0;

void DnC(int l, int r, int low, int high){
    if (l > r) return;
    ll mid = l + (r-l)/2, index = high, h = INT64_MIN;
    forn(i, low, high+1){
        if (h <= (c2[mid].fi - p2[i].fi) * (c2[mid].se - p2[i].se) && (c2[mid].se - p2[i].se) >= 0){ 
            h = (c2[mid].fi - p2[i].fi) * (c2[mid].se - p2[i].se);
            index = i;
        }
    }
    if (h > ans) {
        ans = h;
    }
    if (l < mid) {
        DnC(l, mid-1, low, index);
    }
    if (r > mid) {
        DnC(mid+1, r, index, high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    pair<ll, ll> p[n], c[m];
    forn(i, 0, n) cin >> p[i].fi >> p[i].se;
    forn(i, 0, m) cin >> c[i].fi >> c[i].se;
    sort(p, p+n);
    sort(c, c+m);
    ll curr_x = -1, curr_y = -1;
    forn(i, 0, n){
        if (p[i].fi != curr_x){
            if (curr_x != -1){
                p1.pb(mp(curr_x, curr_y));
            } 
            curr_x = p[i].fi;
            curr_y = p[i].se;
        } else {
            if (curr_y > p[i].se) curr_y = p[i].se;
        }
    }
    if (curr_x != -1){
        p1.pb(mp(curr_x, curr_y));
    } 
    ll curr = INT32_MAX;
    for(int i = 0; i < sz(p1); i++){
        if (p1[i].se < curr) {
            p2.pb(p1[i]);
            curr = p1[i].se;
        }
    }
    curr_x = -1, curr_y = -1;
    forn(i, 0, m){
        if (c[i].fi != curr_x){
            if (curr_x != -1){
                c1.pb(mp(curr_x, curr_y));
            } 
            curr_x = c[i].fi;
            curr_y = c[i].se;
        } else {
            if (curr_y < c[i].se) curr_y = c[i].se;
        }
    }
    if (curr_x != -1){
        c1.pb(mp(curr_x, curr_y));
    } 
    curr = -1;
    for(int i = sz(c1)-1; i >= 0; i--){
        if (c1[i].se > curr) {
            c2.pb(c1[i]);
            curr = c1[i].se;
        }
    }
    sort(c2.begin(), c2.end());
    DnC(0, sz(c2)-1, 0, sz(p2)-1);
    cout << ans << '\n';
}