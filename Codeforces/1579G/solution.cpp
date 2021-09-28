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
    
void solve(){
    ll n;
    cin >> n;
    int curr[2010];
    forn(i, 0, 2010) curr[i] = 1000000;
    curr[0] = 0;
    forn(i, 0, n) {
        int next[2010], next1[2010];
        forn(i, 0, 2010) next[i] = 1000000, next1[i] = 1000000;
        int temp;
        cin >> temp;
        
        forn(i, 0, 2010){
            if (curr[i] < 2010){
                int a = max(i - temp, 0), b = curr[i] + temp;
                if (b + a < 2010) {
                    bool add = true;
                    if (next[a] < b) add = false;
                    else if (next1[b] < a) add = false;
                    if (add){
                        next[a] = b;
                        next1[b] = a;
                    }
                }
                a = max(curr[i] - temp, 0), b = i + temp;
                if (b + a < 2010) {
                    bool add = true;
                    if (next[a] < b) add = false;
                    else if (next1[b] < a) add = false;
                    if (add){
                        next[a] = b;
                        next1[b] = a;
                    }
                }
            }
        }
        forn(i, 0, 2010) curr[i] = next[i];
    }
    ll low = 1000000;
    forn(i, 0, 2010){
        if (i + curr[i] < low) low = i + curr[i];
    }
    cout << low << endl;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}
