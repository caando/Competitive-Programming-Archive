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
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<int> sieve;
void calc_sieve(int n){
    sieve.reserve(n+1);
    forn(i, 0, n+1) sieve[i] = i;
    forn(i, 2, n+1){
        if (sieve[i] == i){
            for(ll j = i * i; j <= n; j += i){
                if (sieve[j] == j) sieve[j] = i;
            }
        }
    }
}

ll norm(ll a, ll P) {
    while (a >= P) a -= P;
    while (a < 0) a += P;
    return a;
}

ll mul_mod(ll a, ll b, ll P) {
    return a * b % P;
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

ll div_mod(ll a, ll b, ll P) {
    return a * inv_mod(b, P) % P;
}

int msb(ll a){ 
    for(int i = 62; i >= 0; i--){
        if (a & ((ll)1 << i)) return i + 1;
    }
    return 0;
}

vector<ll> fact;
void calc_fact(int n, ll P){
    if (fact.size() < 1) fact.pb(1);
    forn(i, fact.size(), n+1) fact.pb(fact[i-1] * i  % P);
}

vector<ll> fact_inv;
void calc_fact_inv(int n, ll P){
    if (fact_inv.size() < 1) fact_inv.pb(1);
    forn(i, fact_inv.size(), n+1) fact_inv.pb(fact_inv[i-1] * inv_mod(i, P) % P);
}

ll nCr(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact[n] * fact_inv[r] % P) * fact_inv[n-r] % P;
}

ll nCr_inv(int n, int r, ll P){
    if (r > n) return 0;
    calc_fact(n, P);
    calc_fact_inv(n, P);
    return (fact_inv[n] * fact[r] % P) * fact[n-r] % P;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const ll MAXN = 500000;
ll n, q, p, t[5][4*MAXN];

void build(ll s, ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[s][v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(s, a, v*2, tl, tm);
        build(s, a, v*2+1, tm+1, tr);
        t[s][v] = t[s][v*2] + t[s][v*2+1];
    }
}

ll sum(ll s, ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[s][v];
    }
    ll tm = (tl + tr) / 2;
    return sum(s, v*2, tl, tm, l, min(r, tm))
           + sum(s, v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(ll s, ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[s][v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(s, v*2, tl, tm, pos, new_val);
        else
            update(s, v*2+1, tm+1, tr, pos, new_val);
        t[s][v] = t[s][v*2] + t[s][v*2+1];
    }
}

void solve(){
    memset(t, 0, sizeof t);
    cin >> n >> q >> p;
    ll a[n], b[n], c[n], d[n];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    forn(i, 0, n) {
        ll curr;
        cin >> curr;
        if (curr % p == 0){
            ll count = 0;
            while (curr % p == 0 && curr != 0) count++, curr /= p;
            a[i] = count;
        } else if (curr > p){
            ll temp = curr - curr % p, count = 0;
            while (temp % p == 0 && temp != 0) count++, temp /= p;
            b[i] = count;
            temp = curr + curr % 2, count = -1;
            while (temp % p == 0 && temp != 0) count++, temp /= p;
            c[i] = count;
            d[i] = 1;
        }
    }
    build(0, a, 1, 0, n-1);
    build(1, b, 1, 0, n-1);
    build(2, c, 1, 0, n-1);
    build(3, d, 1, 0, n-1);
    forn(i, 0, q){
        ll t;
        cin >> t;
        if (t == 1) {
            ll curr, pos;
            cin >> pos >> curr;
            if (curr % p == 0 && curr != 0){
                ll count = 0;
                while (curr % p == 0 && curr != 0)count++, curr /= p;
                update(0, 1, 0, n-1, pos-1, count);
                update(1, 1, 0, n-1, pos-1, 0);
                update(2, 1, 0, n-1, pos-1, 0);
                update(3, 1, 0, n-1, pos-1, 0);
            } else if(curr > p){
                update(0, 1, 0, n-1, pos-1, 0);
                ll temp = curr - curr % p, count = 0;
                while (temp % p == 0 && temp != 0) count++, temp /= p;
                update(1, 1, 0, n-1, pos-1, count);
                temp = curr + 1, count = -1;
                while (temp % p == 0 && temp != 0) count++, temp /= p;
                update(2, 1, 0, n-1, pos-1, count);
                update(3, 1, 0, n-1, pos-1, 1);
            } else {
                update(0, 1, 0, n-1, pos-1, 0);
                update(1, 1, 0, n-1, pos-1, 0);
                update(2, 1, 0, n-1, pos-1, 0);
                update(3, 1, 0, n-1, pos-1, 0);
            }
        } else {
            ll s, l, r, ans = 0;
            cin >> s >> l >> r;
            if (p == 2 && s % 2 == 0){
                ans += sum(2, 1, 0, n-1, l-1, r-1);
            }
            ans += sum(1, 1, 0, n-1, l-1, r-1);
            ans += s*sum(0, 1, 0, n-1, l-1, r-1);
            ll temp = s, count = 0;
            while (temp % p == 0) count++, temp /= p;
            ans += count*sum(3, 1, 0, n-1, l-1, r-1);
            cout << ans << ' ';
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) {
        cout << "Case #" << T + 1 << ": ";
        solve();
    }
}