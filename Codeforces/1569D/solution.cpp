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

void solve(){
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    set<int> vert_lines, hori_lines;
    map<int, vector<int>> points_hori, points_vert;
    vector<int> all_vert, all_hori;
    forn(i, 0, n) {
        int temp;
        cin >> temp;
        vert_lines.insert(temp);
    }
    forn(i, 0, m) {
        int temp;
        cin >> temp;
        hori_lines.insert(temp);
    }
    forn(i, 0, k){
        int x, y;
        cin >> x >> y;
        if (vert_lines.find(x) == vert_lines.end()) all_hori.pb(x), points_hori[y].pb(x);
        if (hori_lines.find(y) == hori_lines.end()) all_vert.pb(y), points_vert[x].pb(y);
    }
    sort(all(all_vert));
    sort(all(all_hori));
    for (auto it = points_hori.begin(); it != points_hori.end(); it++){
        auto temp = it->second;
        sort(all(temp));
        forn(i, 0, temp.size()){
            auto right = vert_lines.upper_bound(temp[i]);
            auto left = right;
            --left;
            auto left_most = upper_bound(temp.begin(), temp.end(), *left);
            auto right_most = lower_bound(temp.begin(), temp.end(), *right);
            ans -= right_most - left_most-1;
            left_most = upper_bound(all_hori.begin(), all_hori.end(), *left);
            right_most = lower_bound(all_hori.begin(), all_hori.end(), *right);
            ans += right_most - left_most-1;
        }
    }
    for (auto it = points_vert.begin(); it != points_vert.end(); it++){
        auto temp = it->second;
        sort(all(temp));
        forn(i, 0, temp.size()){
            auto right = hori_lines.upper_bound(temp[i]);
            auto left = right;
            --left;
            auto left_most = upper_bound(temp.begin(), temp.end(), *left);
            auto right_most = lower_bound(temp.begin(), temp.end(), *right);
            ans -= right_most - left_most-1;
            left_most = upper_bound(all_vert.begin(), all_vert.end(), *left);
            right_most = lower_bound(all_vert.begin(), all_vert.end(), *right);
            ans += right_most - left_most-1;
        }
    }
    cout << ans/2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}