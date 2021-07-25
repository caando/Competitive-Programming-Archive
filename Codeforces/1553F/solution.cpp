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

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll pow_mod(ll a, ll b, ll P){
    ll curr = a, ans = 1;
    while(b != 0){
        if (b&1) {
            ans *= curr;
            ans%=P;
        }
        curr *= curr;
        curr %= P;
        b >>= 1;
    }
    return ans;
}

ll inv_mod(ll a, ll P) {
    return pow_mod(a, P - 2ll, P);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const ll MAXN = 300001;
ll t[4*MAXN], t2[4*MAXN];

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int add) {
    if (tl == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, add);
        else
            update(v*2+1, tm+1, tr, pos, add);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum2(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return sum2(v*2, tl, tm, l, min(r, tm))
           + sum2(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update2(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t2[v]++;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update2(v*2, tl, tm, pos);
        else
            update2(v*2+1, tm+1, tr, pos);
        t2[v] = t2[v*2] + t2[v*2+1];
    }
}

void solve(){
    ll n;
    cin >> n;
    ll arr[n], total[n], left[n], right[n];
    memset(total, 0, sizeof total);
    forn(i, 0, n) {
        cin >> arr[i], total[i] += arr[i];
        if (i != 0) total[i] += total[i-1];
    }
    memset(t, 0, sizeof t);
    memset(t2, 0, sizeof t2);
    ll curr = 0;
    forn(i, 0, n){
        ll ans = curr + arr[i] * i;
        if (i != 0) ans += total[i-1];
        ans -= sum(1, 0, MAXN-1, 0, arr[i]);
        for(int j = 1; j*arr[i] < MAXN; j++){
            update(1, 0, MAXN-1, j * arr[i], arr[i]);
        }
        for(int j = 1; j*arr[i] < MAXN; j++){
            ans -= sum2(1, 0, MAXN-1, arr[i]*j, min(arr[i]*(j+1)-1, MAXN-1)) * arr[i] * j;
        }
        update2(1, 0, MAXN-1, arr[i]);
        cout << ans << ' ';
        curr = ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}