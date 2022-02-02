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
    ll n, m, p, k, a, b, c;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj = vector<vector<pair<ll, ll>>>(n);
    vector<ll> weights, markers;

    forn(i, 0, m){
        ll l, r, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
        weights.pb(w);
    }
    
    forn(i, 0, m){
        forn(j, 0, i+1){
            markers.pb((weights[i] + weights[j])/2);
        }
    }

    vector<array<ll, 4>> dp;

    for(ll val : markers){
        bool visited[n];
        ll total = 0, high = 0, low = 0, cnt = 1;
        memset(visited, 0, sizeof visited);
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>> > pq;
        visited[0] = true;
        for(auto edge : adj[0]){
            pq.push({abs(edge.se - val), edge.se, edge.fi});
        }
        while(cnt < n){
            if (!visited[pq.top()[2]]){
                cnt++;
                total += pq.top()[0];
                ll v = pq.top()[2];
                if (pq.top()[1] > val) high++;
                else if (pq.top()[1] < val) low++;
                pq.pop();
                visited[v] = true;
                for(auto edge : adj[v]){
                    if (!visited[edge.fi]) pq.push({abs(edge.se - val), edge.se, edge.fi});
                }
            } else pq.pop();
        }
        dp.pb({val, total, high, low});
    }
    sort(dp.begin(), dp.end());
    ll q;
    cin >> p >> k >> a >> b >> c;
    ll last;
    ll ans = 0;
    forn(i, 0, k){
        if (i < p) cin >> q;
        else q = (q * a + b) % c;
        auto ptr = upper_bound(dp.begin(), dp.end(), array<ll, 4>{q, 0, 0, 0});
        ll ans1 = INT64_MAX;
        if (ptr != dp.end()) {
            auto s = *ptr;
            ans1 = min(ans1, s[1] + (n-s[3]-1) * (s[0] - q) - s[3] * (s[0] - q));
        }
        if (ptr != dp.begin()){
            ptr--;
            auto s = *ptr;
            ans1 = min(ans1, s[1] + (n-s[2]-1) * (q - s[0]) - (s[2]) * (q - s[0]));
        }
        ans ^= ans1;
    }
    cout << ans;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}