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
const long long mod = 1000000007;
const int MAXN = 1000000;


ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

bool sieve[MAXN+1];

void solve(){
    ll n;
    cin >> n;
    int arr[n], high = 0;
    memset(sieve, 0, sizeof sieve);
    forn(i, 0, n) {
        cin >> arr[i];
        high = max(arr[i], high);
        sieve[arr[i]] = true;
    }
    int ans = 0;
    for(int i = high; i >= 2; i--){
        if (!sieve[i]){
            int cur = -1;
            for(int j = i*2; j <= MAXN; j+=i){
                if (sieve[j]){
                    if (cur == -1) cur = j;
                    else cur = gcd(cur, j);
                }
            }
            if (cur == i){
                ans++;
                sieve[i] = true;
            }
        }
    }
    if (!sieve[1]) ans++;
    cout << ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}