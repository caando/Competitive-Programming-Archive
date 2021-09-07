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

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 200005;

int n,  p[4*MAXN], s[4*MAXN], arr[MAXN];
ll t[4*MAXN];

pair<ll, pair<int, int>> merge(ll t1, int p1, int s1, int r, ll t2, int p2, int s2, int l){
    if (r <= l){
        if (s1 == -1 && s2 == -1) return mp(0, mp(p1 + p2, -1));
        else if (s1 == -1) return mp(t2, mp(p1 + p2, s2));
        else if (s2 == -1) return mp(t1, mp(p1, s1 + p2));
        else {
            ll n = s1 + p2;
            return mp(t1 + t2 + n*(n+1)/2, mp(p1, s2));
        }
    } else {
        if (s1 == -1 && s2 == -1) return mp(0, mp(p1, p2));
        else if (s1 == -1) {
            ll n = p2;
            return mp(t2 + n*(n+1)/2, mp(p1, s2));
        } else if (s2 == -1) {
            ll n = s1;
            return mp(t1 + n*(n+1)/2, mp(p1, p2));
        } else {
            ll n1 = s1, n2 = p2;
            return mp(t1 + t2 + n1*(n1+1)/2 + n2*(n2+1)/2, mp(p1, s2));
        }
    }
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = 0;
        p[v] = 1;
        s[v] = -1;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v*2, tl, tm, pos);
        else update(v*2+1, tm+1, tr, pos);
        pair<ll, pair<int, int>> val = merge(t[v*2], p[v*2], s[v*2], arr[tm], t[v*2+1], p[v*2+1], s[v*2+1], arr[tm+1]);
        t[v] = val.fi;
        p[v] = val.se.fi;
        s[v] = val.se.se;
    }
}

pair<ll, pair<int, int>> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return mp(0, mp(0, -1));
    if (l == tl && r == tr) {
        return mp(t[v], mp(p[v], s[v]));
    }
    int tm = (tl + tr) / 2;
    pair<ll, pair<int, int>> a = query(v*2, tl, tm, l, min(r, tm));
    pair<ll, pair<int, int>> b = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return merge(a.fi, a.se.fi, a.se.se, arr[tm], b.fi, b.se.fi, b.se.se, arr[tm+1]);
}

void solve(){
    int q;
	cin >> n >> q;
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) update(1, 0, n-1, i);
    forn(i, 0, q){
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1){
            arr[a-1] = b;
            update(1, 0, n-1, a-1);
        } else {
            pair<ll, pair<ll, ll>> ans = query(1, 0, n-1, a-1, b-1);
            if (ans.se.se == -1) cout << ans.se.fi * (ans.se.fi+1)/2 << endl;
            else {
                cout << ans.fi + ans.se.fi * (ans.se.fi+1)/2 + ans.se.se * (ans.se.se+1)/2 << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}
