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
const long long mod = 998244353;
const int MAXN = 200001;

ll n, high[4*MAXN], low[4*MAXN];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        high[v] = a[tl];
        low[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        high[v] = max(high[v*2], high[v*2+1]);
        low[v] = min(low[v*2], low[v*2+1]);
    }
}

ll query_max(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return __INT64_MAX__ * -1;
    if (l == tl && r == tr) {
        return high[v];
    }
    int tm = (tl + tr) / 2;
    return max(query_max(v*2, tl, tm, l, min(r, tm)), query_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

ll query_min(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return __INT64_MAX__;
    if (l == tl && r == tr) {
        return low[v];
    }
    int tm = (tl + tr) / 2;
    return min(query_min(v*2, tl, tm, l, min(r, tm)), query_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}


void solve(){
    ll q;
    cin >> n >> q;
    ll a[n], b[n];
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i], b[i] -= a[i];
    ll p[n];
    ll curr = 0;
    forn(i, 0, n){
        curr += b[i];
        p[i] = curr;
    }
    build(p, 1, 0, n-1);
    forn(i, 0, q){
        int a, b;
        cin >> a >> b;
        bool poss = true;
        if (a==1) {
            if (p[b-1] != 0) poss = false;
        } else {
            if (p[b-1] != p[a-2]) poss = false;
        }
        if (query_min(1, 0, n-1, a-1, b-1) < p[b-1]) poss = false;
        if (!poss) cout << -1 << endl;
        else cout << query_max(1, 0, n-1, a-1, b-1) - p[b-1] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}
