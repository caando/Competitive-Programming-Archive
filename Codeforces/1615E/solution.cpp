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

vector<vector<ll>> adj;
vector<ll> s, parent;
ll bm;

ll dfs(ll v, ll p){
    parent[v] = p;
    ll t = 0;
    for(ll c : adj[v]){
        if (c == p) continue;
        t = max(t, dfs(c, v));
    }
    s[v] = t+1;
    return t + 1;
}

priority_queue<pair<ll, ll>> pq;

void deconstruct(ll v, ll p){
    ll high = 0, index = -1;
    for(ll c : adj[v]){
        if (c == p) continue;
        if (s[c] > high) high = s[c], index = c;
    }
    for(ll c : adj[v]){
        if (c == p) continue;
        if (index != c) pq.push(mp(s[c], c));
    }
    bm--;
    if (index != -1) deconstruct(index, v);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    bm = n;
    adj = vector<vector<ll>>(n);
    s = vector<ll>(n);
    parent = vector<ll>(n);
    forn(i, 0, n-1){
        ll a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0, 0);
    
    pq.push(mp(s[0], 0));
    ll score = INT64_MIN;
    for(ll r=0; r< k+1; r++){
        if (bm == 0){
            r = min(k, max(r, n/2));
            score = max(score, r*(n-r));
            break;
        }
        ll b = n/2;
        b = min(b, bm);
        score = max(score, (r-b)*(n-r-b));
        ll index = pq.top().se;
        pq.pop();
        deconstruct(index, parent[index]);
    }
    cout << score << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}