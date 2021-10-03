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

vector<vector<int>> adj;
vector<pair<int, int>> edges;

void dfs(int v, int p){
    for(int c : adj[v]){
        if (c != p){
            edges.pb(mp(v, c));
            dfs(c, v);
        }
    }
}
 
void solve(){
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0, 0);
    int goal;
    cout << '?' << ' ' << n << ' ';
    forn(i, 0, n) cout << i + 1 << ' ';
    cout << endl;
    cout.flush();
    cin >> goal;
    int low = 0, high = n-2;
    while(low <= high){
        set<int> s;
        int mid = (high - low)/2 + low;
        forn(i, low, mid+1) {
            s.insert(edges[i].fi);
            s.insert(edges[i].se);
        }
        cout << '?' << ' ' << sz(s) << ' ';
        for(int i : s) cout << i + 1 << ' ';
        cout << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res == goal) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "! ";
    cout << edges[low].fi+1 << ' ' <<  edges[low].se+1 << endl;
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}