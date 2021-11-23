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
const long long mod = 1e9+7;
const int MAXN = 200000;

pair<int, vector<long double>> arr[MAXN+1];

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    forn(i, 0, n) cin >> a[i] >> b[i];
    forn(i, 0, MAXN+1) arr[i].fi = i;
    forn(i, 0, n) arr[a[i]].se.pb(b[i]);
    long double high = 0;
    vector<int> ans;
    forn(i, 1, 21){
        vector<pair<long double, int>> cur;
        forn(j, 1, MAXN+1){
            pair<long double, int> val = {0, 0};
            for(long double k : arr[j].se) {
                val.fi += min((long double)1, k/i);
            }
            val.se = j;
            if (val.fi) cur.pb(val);
        }
        sort(cur.begin(), cur.end(), greater<pair<long double, int>>());
        long double t = 0;
        forn(j, 0, min(i, sz(cur))) t += cur[j].fi;
        if (t > high){
            high = t;
            ans.clear();
            forn(j, 0, i){
                ans.pb(cur[j].se);
            }
        }
    }
    cout << sz(ans) << '\n';
    for(int i : ans) cout << i << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}