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

void solve(){
    int n;
    cin >> n;
    char arr[n];
    forn(i, 0, n) cin >> arr[i];
    int a[n+1], b[n+1], c[n+1], d[n+1], cur = 0, cur1=0, p=0, p1 = 0;
    a[0] = b[0] = c[0] = d[0] = 0;
    forn(i, 0, n){
        if (arr[i] == '1') cur++, p = i;
        if (arr[i] == '0') cur1++, p1 = i;
        a[i+1] = cur, b[i+1] = cur1;
        c[i+1] = p, d[i+1] = p1;
    }
    forn(i, 1, n+1){
        int cur = 0, cnt = 0;
        while(cur+i <= n){
            if (a[cur] == a[cur+i] || b[cur] == b[cur+i]){
                cnt++;
                cur += i;
            } else{
                cur += i;
                cur = min(c[cur], d[cur]) + 1;
            }
        }
        cout << cnt << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}