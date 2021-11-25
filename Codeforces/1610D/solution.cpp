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
const long long mod = 1e9+7;
const int MAXN = 200000;

ll pow_mod(ll a, ll b, ll P){
    ll ans = 1;
    while(b){
        if (b&1) ans = ans*a%P;
        a = a*a%P;
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    int exp[30];
    memset(exp, 0, sizeof exp);
    forn(i, 0, n){
        int temp, cnt = 0;
        cin >> temp;
        while((temp&1)==0){
            cnt++;
            temp >>= 1;
        }
        exp[cnt]++;
    }
    ll ans = pow_mod(2, n, mod) - 1;
    n -= exp[0];
    forn(i, 1, 30){
        n -= exp[i];
        if (exp[i]) ans = (ans - pow_mod(2, exp[i]-1, mod)*pow_mod(2, n, mod) % mod + mod) % mod;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}