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

ll mod = 1000000007;

void solve(){
    ll n, d;
    cin >> n >> d;
    long double prev[10], curr[10];
    ll arr[n];
    forn(i, 0, n) cin >> arr[i];
    ll backtrack[n][10];
    forn(i, 0, 10) curr[i] = INT_MIN;
    forn(i, 0, 10) prev[i] = INT_MIN;
    prev[1] = 0;
    forn(i, 0, n) forn(j, 0, 10) backtrack[i][j] = -1;
    forn(i, 0, n){
        ll c = arr[i];
        forn(j, 0, 10) curr[j] = prev[j];
        forn(j, 0, 10){
            if (prev[j]+log(c) > curr[c*j%10] && prev[j] >= 0){
                curr[c*j%10] = prev[j]+log(c);
                backtrack[i][c*j%10] = j;
            }
        }
        forn(j, 0, 10) prev[j] = curr[j];
    }
    if (prev[d] == 0) cout << -1;
    else {
        vector<ll> ans;
        ll curr = d;
        for(ll i = n-1; i>= 0; i--){
            if (backtrack[i][curr] >= 0) ans.pb(arr[i]), curr=backtrack[i][curr];
        }
        if (ans.size() == 0) cout << -1;
        else {
            cout << ans.size() << endl;
            forn(i, 0, ans.size()) cout << ans[i] << ' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}