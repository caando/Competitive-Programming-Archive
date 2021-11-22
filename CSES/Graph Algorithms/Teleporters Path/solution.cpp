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
const int MAXN = 200000;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> t[n];
    int IN[n], OUT[n];
    memset(IN, 0, sizeof IN);
    memset(OUT, 0, sizeof OUT);
    forn(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        IN[b]++;
        OUT[a]++;
        t[a].pb(b);
    }
    bool pos = true;
    if (OUT[0] - IN[0] != 1) pos = false;
    if (IN[n-1] - OUT[n-1] != 1) pos = false;
    forn(i, 1, n-1){
        if (IN[i] != OUT[i]) pos = false;
    }
    stack<int> ans;
    if (pos) {
        vector<int> path;
        path.pb(0);
        while(!path.empty()){
            if (t[path.back()].empty()) {
                ans.push(path.back());
                path.pop_back();
            } else {
                int temp = t[path.back()].back();
                t[path.back()].pop_back();
                path.pb(temp);
            }
        }
        if (sz(ans) != m+1) cout << "IMPOSSIBLE";
        else while(!ans.empty()) cout << ans.top() + 1 << ' ', ans.pop();
    } else {
        cout << "IMPOSSIBLE";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}