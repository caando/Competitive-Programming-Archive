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

void solve(){
    int n;
    cin >> n;
    if ((n-3)%4==0){
        cout << "YES\n";
        cout << n/2+1 << '\n';
        cout << "1 2 ";
        forn(i, 4, n+1){
            if ((i-4) %4 == 0 || (i-4) %4 == 3) cout << i << ' ';
        }
        cout << '\n' << n/2 << '\n' << "3 ";
        forn(i, 4, n+1){
            if ((i-4) %4 == 1 || (i-4) %4 == 2) cout << i << ' ';
        }
    } else if (n%4==0) {
        cout << "YES\n";
        cout << n/2 << '\n';
        forn(i, 1, n+1){
            if (i %4 == 0 || i % 4 == 1) cout << i << ' ';
        }
        cout << '\n';
        cout << n/2 << '\n';
        forn(i, 1, n+1){
            if (i %4 == 2 || i % 4 == 3) cout << i << ' ';
        }
    } else cout << "NO";

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}