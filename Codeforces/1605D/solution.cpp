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

vector<vector<int>> adj; 
vector<bool> parity, taken;
vector<int> assign;
int even, odd;

void dfs(int v, int p, int par){
    parity[v] = par&1;
    if (par&1) odd++;
    else even++;
    for(int c : adj[v]){
        if (c != p){
            dfs(c, v, par + 1);
        }
    }
}

void solve(int t){
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    parity = vector<bool>(n);
    taken = vector<bool>(n+1, false);
    assign = vector<int>(n, -1);
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[b-1].pb(a-1);
        adj[a-1].pb(b-1);
    }
    even = 0, odd = 0;
    int e=0, o=0;
    dfs(0, 0, 0);
    if (even < odd){
        for(int exp = 0; exp < 19; exp++){
            if (even & (1<<exp)){
                forn(i, (1<<exp), (1<<(exp+1))){
                    while(parity[e]) e++;
                    assign[e] = i;
                    taken[i] = true;
                    e++;
                }
            }
        }
        
        forn(i, 1, n+1){
            if (!taken[i]) {
                while(!parity[o]) o++;
                assign[o] = i;
                taken[i] = true;
                o++;
            }
        }
    } else {
        
        for(int exp = 0; exp < 19; exp++){
            if (odd & (1<<exp)){
                forn(i, (1<<exp), (1<<(exp+1))){
                    while(!parity[o]) o++;
                    assign[o] = i;
                    taken[i] = true;
                    o++;
                }
            }
        }
        
        forn(i, 1, n+1){
            if (!taken[i]) {
                while(parity[e]) e++;
                assign[e] = i;
                taken[i] = true;
                e++;
            }
        }
    }
    forn(i, 0, n) cout << assign[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}