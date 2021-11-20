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
const int MAXN = 1000001;

ll map_pos[MAXN];
ll map_neg[MAXN];

void solve(){
    int n;
    cin >> n;
    ll a[n+1], b[n+1], c[n+1], d[n+1];
    forn(i, 1, n+1) cin >> a[i];
    forn(i, 1, n+1) cin >> b[i], c[i] = b[i] - a[i];
    ll mul[n+1];
    memset(mul, 0, sizeof mul);
    mul[1] = 1;
    forn(i, 2, n+1){
        for(int j = i*2; j <= n; j+=i) c[j] -= c[i];
    }
    forn(i, 1, n+1){
        for(int j = i*2; j <= n; j+=i) mul[j] -= mul[i];
    }
    ll t = 0, cnt = 0;
    vector<ll> pos, neg;
    forn(i, 2, n+1) t += abs(c[i]);
    forn(i, 2, n+1){
        cnt += abs(mul[i]);
        ll temp = c[i] * mul[i] * -1;
        if (temp > 0) pos.pb(temp);
        else if (temp < 0) neg.pb(-temp);
    }
    sort(all(pos));
    sort(all(neg));
    ll cur = 0;
    map_pos[0] = 0;
    map_neg[0] = 0;
    int index = 0;
    forn(i, 1, MAXN){
        while(index < sz(pos)){
            if (pos[index] >= i) break;
            index++;
        }
        map_pos[i] = map_pos[i-1];
        map_pos[i] += sz(pos) - index;
    }
    index = 0;
    forn(i, 1, MAXN){
        while(index < sz(neg)){
            if (neg[index] >= i) break;
            index++;
        }
        map_neg[i] = map_neg[i-1];
        map_neg[i] += sz(neg) - index;
    }
    int q;
    cin >> q;
    forn(i, 0, q){
        ll x;
        cin >> x;
        x = x - a[1];
        ll ans = t + (cnt+1) * abs(x);
        if (x < 0) ans -= map_neg[-x] * 2;
        else ans -= map_pos[x] * 2;
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}