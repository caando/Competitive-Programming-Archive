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

/*
WARNING:

THIS IS A HUGE MESS AND IS BY NO MEANS A GOOD SOLUTION

*/

ll dp[20][12];

ll calc(int pos, int prev, vector<int> &arr){
    if (arr.size() == 0) return 0;
    if (dp[pos][prev] != -1) return dp[pos][prev];
    ll res = 0;
    int low=0, high;
    if (prev == 11) high = arr[pos]+1;
    else high = 10;
    if (prev == 10 || pos == 0) {
        low = 1;
        if (pos != arr.size()-1) res += calc(pos+1, 10, arr);
    }

    forn(i, low, high){
        if (prev == 11 || pos == 0){
            if (pos == 0){
                if (pos == arr.size()-1) res++;
                else if (i == arr[pos]) res += calc(pos+1, 11, arr);
                else res += calc(pos+1, i, arr);
            } else if (i != arr[pos-1]){
                if (pos == arr.size()-1) res++;
                else if (i == arr[pos]) res += calc(pos+1, 11, arr);
                else res += calc(pos+1, i, arr);
            }
        } else {
            if (i != prev) {
                if (pos == arr.size()-1) res++;
                else res += calc(pos+1, i, arr);
            }
        }
    }
    dp[pos][prev] = res;
    return res;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    a--;
    vector<int> temp, A, B;
    while (a > 0) temp.push_back(a%10), a/=10;
    while (!temp.empty()) A.push_back(temp.back()), temp.pop_back();

    while (b > 0) temp.push_back(b%10), b/= 10;
    while (!temp.empty()) B.push_back(temp.back()), temp.pop_back();

    forn(i, 0, 20) forn(j, 0, 12) dp[i][j] = -1;
    b = calc(0, 11, B);
    if (a < 0) b ++, a = 0;
    forn(i, 0, 20) forn(j, 0, 12) dp[i][j] = -1;
    a = calc(0, 11, A);
    cout << b - a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(16) << fixed;
    solve();
}
