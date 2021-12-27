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
    int n, high = 0, high1 = 0, low = INT_MAX;
    cin >> n;
    bool a = false, b = false;
    forn(i, 0, n){
        int e;
        cin >> e;
        if(e > high) high1 = high, high = e;
        else if (e > high1 && e != high) high1 = e;
        if(e < low) low = e;
        if (e%3 == 1) a = true;
        else if (e%3 == 2) b = true;
    }
    if (high <= 3){
        cout << min(min(n, high), 2) << '\n';
    } else if (!a && !b){
        cout << high/3 << '\n';
    } else if (!a || !b) {
        cout << high/3 + 1 << '\n';
    } else if (high%3 == 0) {
        cout << max(3, high/3+1) << '\n';
    } else if(low > 1 && high%3 == 1 && high1 < high-1){
        cout << high/3 + 1 << '\n';
    } else {
        cout << high/3 + 2 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--)solve();
}