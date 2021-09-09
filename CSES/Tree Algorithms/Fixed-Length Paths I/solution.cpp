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

int n, k;
bool visited[MAXN];
vector<int> adj[MAXN];
int st[MAXN];

int get_subtree(int v, int p){
    int& curr = st[v];
    curr = 1;
    for(int c : adj[v]){
        if (c == p) continue;
        if (visited[c]) continue;
        curr += get_subtree(c, v);
    }
    return curr;
}

int get_centroid(int v, int p, int s){
    for(int c : adj[v]){
        if (c == p) continue;
        if (visited[c]) continue;
        if (st[c] * 2 > s) return get_centroid(c, v, s);
    }
    return v;
}

void get_cnt(int v, int p, int count, vector<int>& cnt){
    if (count > k) return ;
    while((int)cnt.size() < count) cnt.pb(0);
    cnt[count-1]++;
    for(int c : adj[v]){
        if (c == p) continue;
        if (visited[c]) continue;
        get_cnt(c, v, count+1, cnt);
    }
}

ll get_paths(int v, int s){
    get_subtree(v, -1);
    int centroid = get_centroid(v, -1, s);
    get_subtree(centroid, -1);
    visited[centroid] = true;
    vector<vector<int>> cnt(adj[centroid].size());
    ll res = 0;
    int max_size = 0;
    forn(i, 0, adj[centroid].size()){
        if (visited[adj[centroid][i]]) continue;
        get_cnt(adj[centroid][i], centroid, 1, cnt[i]);
        if((int)cnt[i].size() == k) res += cnt[i][k-1]*2, cnt[i].pop_back();
        if ((int)cnt[i].size() > max_size) max_size = cnt[i].size();
    }
    ll total[max_size];
    memset(total, 0, sizeof total);
    forn(j, 0, adj[centroid].size()){
        forn(i, 0, cnt[j].size()){
            total[i] += cnt[j][i];
        }
    }
    forn(j, 0, adj[centroid].size()){
        forn(i, 0, cnt[j].size()){
            if (k-i-2 < max_size){
                if (k-i-2 < (int)cnt[j].size()) res += cnt[j][i] * (total[k-i-2] - cnt[j][k-i-2]);
                else res += cnt[j][i] * total[k-i-2];
            }
        }
    }
    for(int c : adj[centroid]){
        if (visited[c]) continue;
        res += get_paths(c, st[c]);
    }
    return res;
}

void solve(){
    memset(visited, 0, sizeof visited);
    cin >> n >> k;
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    cout << get_paths(0, n)/2;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}