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
const int MAXN = 2000000;

int sieve[MAXN+1];

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    int ans = 0;
    forn(i, 0, n){
        int zeros = 0;
        set<int> allps;
        forn(j, 0, n){
            int diff = arr[j]-arr[i], prev = 0, cur=1;
            if (diff==0)zeros++;
            set<int> ps;
            ps.insert(1);
            while(diff > 1){
                set<int> nx = ps;
                for(int p : ps) nx.insert(p*sieve[diff]);
                diff/=sieve[diff];
                ps = nx;
            }
            for(int p : ps) allps.insert(p);
        }
        if (zeros >= n/2) ans = INT_MAX;
        else {
            for(int p : allps){
                int cnt = 0;
                forn(j, 0, n){
                    if (arr[j] > arr[i]){
                        if (gcd(arr[j]-arr[i], p) == p) cnt++;
                    }
                }
                if (cnt + zeros >= n/2) ans = max(ans, p);
            }

        }
    }
    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    memset(sieve, 0, sizeof sieve);
    for(long long i = 2; i < MAXN+1; i++){
        if (!sieve[i]) {
            sieve[i] = i;
            for(long long j = i * i; j <= MAXN; j+=i) if(!sieve[j])sieve[j] = i;
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
}