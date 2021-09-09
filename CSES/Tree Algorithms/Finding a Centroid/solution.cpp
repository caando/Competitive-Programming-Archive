#include <bits/stdc++.h>
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
const long long mod = 998244353;
const int MAXN = 200005;

int st[MAXN], n;
vector<int> adjlist[MAXN];

int dfs(int node, int p){
    int& curr = st[node];
    curr = 1;
    for(int c : adjlist[node]){
        if (c != p){
            curr += dfs(c, node);
        }
    }
    return curr;
}

int dfs1(int node, int p){
    for(int c : adjlist[node]){
        if (c != p){
            if (st[c] * 2 > n) return dfs1(c, node);
        }
    }
    return node;
}

void solve(){
    memset(st, 0, sizeof st);
    cin >> n;
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adjlist[a-1].pb(b-1);
        adjlist[b-1].pb(a-1);
    }
    dfs(0, -1);
    cout << dfs1(0, -1) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}