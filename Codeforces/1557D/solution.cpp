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
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 600001;
pair<int, int> t[4*MAXN], lazy[4*MAXN];
map<int, int> cnt;

void push(int v) {
    if(lazy[v].fi-lazy[v].se < t[v*2].fi - t[v*2].se) t[v*2] = lazy[v];
    if(lazy[v].fi-lazy[v].se < lazy[v*2].fi-lazy[v*2].se) lazy[v*2] = lazy[v];
    if(lazy[v].fi-lazy[v].se < t[v*2+1].fi - t[v*2+1].se) t[v*2+1] = lazy[v];
    if(lazy[v].fi-lazy[v].se < lazy[v*2+1].fi-lazy[v*2+1].se) lazy[v*2+1] = lazy[v];
}

void update(int v, int tl, int tr, int l, int r, pair<int, int> val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = val;
        lazy[v] = val;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        if (t[v*2].fi - t[v*2].se < t[v*2+1].fi - t[v*2+1].se) t[v] = t[v*2];
        else t[v] = t[v*2+1];
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return mp(INF, 0);
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    pair<int, int> a = query(v*2, tl, tm, l, min(r, tm)), b = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    if (a.fi - a.se < b.fi - b.se) return a;
    else return b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg[n];
    forn(i, 0, m){
        int row, l, r;
        cin >> row >> l >> r;
        seg[row-1].pb(mp(l, r));
        cnt[l]=1;
        cnt[r]=1;
    }
    int curr = 1;
    for(auto it : cnt) cnt[(it.fi)] = curr++;
    int dp[n][2], prev[n];
    dp[0][0] = 0;
    dp[0][1] = 1;
    prev[0] = -1;
    forn(i, 0, seg[0].size()) {
        update(1, 0, curr-2, cnt[seg[0][i].fi]-1, cnt[seg[0][i].se]-1, mp(0, 1));
    }
    forn(i, 1, n){
        int low = INT_MAX, index = 0;
        forn(j, 0, seg[i].size()) {
            pair<int, int> temp = query(1, 0, curr-2, cnt[seg[i][j].fi]-1, cnt[seg[i][j].se]-1);
            if (temp.fi - temp.se < low) low = temp.fi - temp.se, index = temp.se;
        }
        prev[i] = index-1;
        if (index == 0) dp[i][0] = i;
        else dp[i][0] = dp[prev[i]][0] + i - index;
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
        forn(j, 0, seg[i].size()) {
            update(1, 0, curr-2, cnt[seg[i][j].fi]-1, cnt[seg[i][j].se]-1, mp(dp[i][0], i+1));
        }
    }
    int inc;
    if (dp[n-1][0] < dp[n-1][1]) {
        inc = 0;
    } else {
        inc = 1;
    }
    curr = n-1;
    vector<int> ans;
    while(curr != -1){
        if (inc) {
            ans.pb(curr+1);
            curr--;
            if (dp[curr][0] <= dp[curr][1]) inc = 0;
            else inc = 1;
        } else {
            forn(i, prev[curr] + 1, curr) ans.pb(i+1);
            curr = prev[curr];
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    forn(i, 0, ans.size()) cout << ans[i] << ' ';
}

int main(){
    forn(i, 0, 4*MAXN) t[i].fi = INT_MAX, t[i].se = 0;
    forn(i, 0, 4*MAXN) lazy[i].fi = INT_MAX, lazy[i].se = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}