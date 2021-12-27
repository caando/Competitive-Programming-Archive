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
const long long mod = 998244353;
const int MAXN = 200000;

void solve(){
    ll n, m;
    cin >> n >> m;
    pair<ll, string> arr[n];
    forn(i, 0, n) cin >> arr[i].fi;
    forn(i, 0, n) cin >> arr[i].se;
    ll ans = 0;
    ll p[m];
    forn(i, 0, m) p[i] = i+1;
    forn(i, 0, (1<<n)){
        pair<ll, ll> cnt[m];
        memset(cnt, 0, sizeof cnt);
        forn(j, 0, m) cnt[j].se = j;
        ll score = 0;
        forn(j, 0, n){
            if (i & (1<<j)) score -= arr[j].fi;
            else score += arr[j].fi;
            forn(k, 0, m){
                if (arr[j].se[k] == '1'){
                    if (i & (1<<j)) cnt[k].fi++;
                    else cnt[k].fi--;
                }
            }
        }
        sort(cnt, cnt + m);
        forn(j, 0, m){
            score += (j+1) * cnt[j].fi;
        }
        if (ans < score) {
            ans = score;
            forn(j, 0, m){
                p[cnt[j].se] = j + 1;
            }
        }
    }
    forn(i, 0, m){
        cout << p[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}
