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
const int MAXN = 1000000;

void solve(){
    int n;
    cin >> n;
    int assignment[n];
    vector<pair<int, pair<int, int>>> events;
    forn(i, 0, n){
        int a, b;
        cin >> a >> b;
        events.pb(mp(a, mp(1, i)));
        events.pb(mp(b+1, mp(-1, i)));
    }
    sort(all(events));
    set<int> rooms;
    forn(i, 0, n) rooms.insert(i+1);
    int cnt= 0, ans = 0;
    forn(i, 0, 2*n){
        cnt += events[i].se.fi;
        if (cnt > ans) ans = cnt;
        if (events[i].se.fi>0) {
            assignment[events[i].se.se] = *rooms.begin();
            rooms.erase(rooms.begin());
        } else {
            rooms.insert(assignment[events[i].se.se]);
        }
    }
    cout << ans << '\n';
    forn(i, 0, n) cout << assignment[i] << ' ';
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}