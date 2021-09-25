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
    cout << "Case #" << T+1 << ": ";
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> round(n+1);
    forn(i, 0, n+1){
        forn(j, 0, m) {
            int temp;
            cin >> temp;
            round[i].pb(temp);
        }
        sort(all(round[i]));
    }
    ll ans = 0;
    map<int, int> store;
    forn(i, 0, m) store[round[0][i]]++;
    forn(i, 0, n){
        int a = 0, b = 0, count = 0;
        while(a < m || b < m) {
            if (a == m) {
                b++;
            } else if (b == m) {
                if (store[round[i][a]] > 0) {
                    store[round[i][a]]--;
                    count++;
                }
                a++;
            } else if(round[i][a] == round[i+1][b]) a++, b++, count++;
            else if(round[i][a] < round[i+1][b]) {
                if (store[round[i][a]] > 0) {
                    store[round[i][a]]--;
                    count++;
                }
                a++;
            } else if(round[i][a] > round[i+1][b]) {
                b++;
            }
        }
        ans += m - count;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}