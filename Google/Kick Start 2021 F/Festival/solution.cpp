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
    ll d, n, k;
    cin >> d >> n >> k;
    vector<pair<ll, ll>> events[d+1];
    forn(i, 0, n) {
        ll h, s, e;
        cin >> h >> s >> e; 
        events[s-1].pb(mp(h, i));
        events[e].pb(mp(-1*h, i));
    }
    multiset<pair<ll, ll>, greater<pair<ll, ll>> > curr;
    auto cutoff = curr.end();
    ll val = 0, high = 0;
    forn(i, 0, d+1){
        forn(j, 0, sz(events[i])){
            if (events[i][j].fi > 0){
                curr.insert(events[i][j]);
                if (sz(curr) > k){
                    if (events[i][j] > (*cutoff)){
                        val -= (*cutoff).fi;
                        val += events[i][j].fi;
                        --cutoff;
                    }
                } else {
                    val += events[i][j].fi;
                    cutoff = curr.end();
                    if (sz(curr) == k) --cutoff;
                }
            } else {
                events[i][j].fi *= -1;
                if (sz(curr) <= k) {
                    val -= events[i][j].fi;
                    cutoff = curr.end();
                } else {
                    if (events[i][j] >= (*cutoff)){
                        val -= events[i][j].fi;
                        ++cutoff;
                        val += (*cutoff).fi;
                    }
                } 
                curr.erase(events[i][j]);
            }
        }
        if (val > high) high = val;
    }
    cout << high << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}