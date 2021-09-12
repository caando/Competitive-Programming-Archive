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
    cout << "Case #" << T << ": ";
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a < n+m-1 || b < n+m-1) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        int c = a - m - n + 2;
        int d = b - m - n + 2;
        forn(i, 0, n){
            forn(j, 0, m){
                if (i == 0 && j == 0) cout << c << ' ';
                else if (i == 0 && j == m-1) cout << d << ' ';
                else cout << 1 << ' ';
            }
            cout << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 1, t+1) solve(T);
}