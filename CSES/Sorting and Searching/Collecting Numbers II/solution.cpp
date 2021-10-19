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

void solve(){
    int n, m;
    cin >> n >> m;
    int ma[n], arr[n];
    forn(i, 0, n){
        cin >> arr[i];
        --arr[i];
        ma[arr[i]] = i;
    }
    int ans = 1;
    int g[n];
    memset(g, 0, sizeof g);
    forn(i, 1, n) {
        g[i] = ma[i] < ma[i-1];
        ans+=g[i];
    }
    forn(i, 0, m){
        int a, b, A, B;
        cin >> A >> B;
        --A, --B;
        a = arr[A], b= arr[B];
        swap(arr[A], arr[B]);
        swap(ma[a], ma[b]);
        if (a > 0){
            if (ma[a] < ma[a-1]){
                ans += 1 - g[a];
                g[a] = 1;
            } else {
                ans += 0 - g[a];
                g[a] = 0;
            }
        }
        if (a < n - 1){
            if (ma[a+1] < ma[a]){
                ans += 1 - g[a+1];
                g[a+1] = 1;
            } else {
                ans += 0 - g[a+1];
                g[a+1] = 0;
            }
        }
        if (b > 0){
            if (ma[b] < ma[b-1]){
                ans += 1 - g[b];
                g[b] = 1;
            } else {
                ans += 0 - g[b];
                g[b] = 0;
            }
        }
        if (b < n - 1){
            if (ma[b+1] < ma[b]){
                ans += 1 - g[b+1];
                g[b+1] = 1;
            } else {
                ans += 0 - g[b+1];
                g[b+1] = 0;
            }
        }
        cout << ans << '\n';
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}