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

vector<vector<pair<ll, ll>>> adj;

void solve(){
    int n;
    cin >> n;
    if (n == 1){
        cout << "10\n";
        return; 
    }
    vector<int> out[1<<(n-1)];
    forn(i, 0, 1<<(n-1)){
        int j = (i & (INT_MAX ^ (1<<(n-2))))<<1;
        out[i].pb(j);
        out[i].pb(j|1);
    }
    for(int i = 0; i < n-1; i++) cout << '0';
    int cur = 0;
    while(!out[cur].empty()){
        int nxt = out[cur].back();
        out[cur].pop_back();
        cur = nxt;
        cout << (cur&1);
    }
    cout << '\n';
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}