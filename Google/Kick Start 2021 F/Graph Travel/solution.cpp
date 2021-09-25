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
const long long mod = 1000000007;
const int MAXN = 200005;


void solve(int T){
    cout << "Case #" << T+1 << ": ";
    ll n, m, p;
    vector<set<int>> adj;
    cin >> n >> m >> p;
    ll scores[1<<n];
    adj = vector<set<int>>((1<<n));
    memset(scores, 0, sizeof scores);
    pair<pair<ll, ll>, ll> rooms[n];
    forn(i, 0, n) cin >> rooms[i].fi.fi >> rooms[i].fi.se >> rooms[i].se;

    forn(i, 0, (1 << n)){
        forn(j, 0, n) {
            if (i & (1 << j)) scores[i] += rooms[j].se;
        }
    }
    forn(i, 0, m){
        int a, b;
        cin >> a >> b;
        forn(j, 0, (1 << n)){
            if ((j & (1 << a)) && !(j & (1 << b))){
                if (scores[j] >= rooms[b].fi.fi && scores[j] <= rooms[b].fi.se){
                    adj[j].insert(j | (1 << b));
                }
            }
            if ((j & (1 << b)) && !(j & (1 << a))){
                if (scores[j] >= rooms[a].fi.fi && scores[j] <= rooms[a].fi.se){
                    adj[j].insert(j | (1 << a));
                }
            }
        }
    }
    ll cnt[1<<n];
    memset(cnt, 0, sizeof cnt);
    forn(i, 0, n) cnt[1<<i]++;
    forn(i, 0, (1<<n)){
        for(ll c : adj[i]){
            cnt[c] += cnt[i];
        }
    }

    ll ans = 0;
    forn(i, 0, (1 << n)){
        if (scores[i] == p) ans += cnt[i];
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}