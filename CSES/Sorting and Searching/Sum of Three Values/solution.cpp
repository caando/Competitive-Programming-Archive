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
    ll n, x;
    cin >> n >> x;
    multiset<pair<int, int>> s;
    ll arr[n];
    cin >> arr[0];
    forn(i, 1, n) cin >> arr[i], s.insert(mp(arr[i], i));

    forn(i, 1, n){
        s.erase(s.find(mp(arr[i], i)));
        forn(j, 0, i){
            auto it = s.lower_bound(mp(x - arr[i]-arr[j], 0));
            if (it == s.end()) continue;
            if ((*it).fi != x - arr[i]-arr[j]) continue;
            cout << j+1 << ' ' << i + 1 << ' ' << (*it).se + 1;
            return;
        }
    }
    cout << "IMPOSSIBLE";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}