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

int n, t[4*MAXN];

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return gcd(query(v*2, tl, tm, l, min(r, tm)),
           query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
    cin >> n;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    build(arr, 1, 0, n-1);
    bool yes[n];
    memset(yes, 0, sizeof yes);
    int cp = -1;
    forn(i, 0, n){
        bool pos = true;
        int l = cp+1, r = i;
        while(l <= r){
            int mid = (l + r) / 2;
            int res = query(1, 0, n-1, mid, i);
            if (res == (i-mid+1)) {
                pos = false;
                break;
            } else if (res < (i-mid+1)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (!pos){
            yes[i] = true;
            cp = i;
        }
    }
    int cnt = 0;
    forn(i, 0, n){
        cnt += yes[i];
        cout << cnt << ' ';
    }
    cout << '\n';
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}