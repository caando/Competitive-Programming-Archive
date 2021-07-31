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
const int MAXN = 1000001;

int n, m, t[4*MAXN], lazy[4*MAXN];

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
    cin >> n >> m;
    pair<int, pair<int, int>> arr[n];
    forn(i, 0, n) cin >> arr[i].se.fi >> arr[i].se.se >> arr[i].fi;
    sort(arr, arr+n);
    int low=0, high=0, ans=INT_MAX;
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
    update(1, 1, m, arr[0].se.fi, arr[0].se.se, 1);
    while(low < n){
        while(query(1, 1, m, 1, m-1) == 0 && high < n - 1){
            high++;
            update(1, 1, m, arr[high].se.fi, arr[high].se.se-1, 1);
        }
        if (query(1, 1, m, 1, m-1)){
            if (arr[high].fi - arr[low].fi < ans) ans = arr[high].fi - arr[low].fi;
        } else {
            break;
        }
        update(1, 1, m, arr[low].se.fi, arr[low].se.se-1, -1);
        low++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}