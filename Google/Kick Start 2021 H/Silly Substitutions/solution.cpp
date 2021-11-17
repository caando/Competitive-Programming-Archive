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


void solve(int t){
    cout << "Case #" << t + 1 << ": ";
    int n;
    cin >> n;
    map<pair<char, char>, char> m = {
        {{'0', '1'}, '2'},
        {{'1', '2'}, '3'},
        {{'2', '3'}, '4'},
        {{'3', '4'}, '5'},
        {{'4', '5'}, '6'},
        {{'5', '6'}, '7'},
        {{'6', '7'}, '8'},
        {{'7', '8'}, '9'},
        {{'8', '9'}, '0'},
        {{'9', '0'}, '1'}
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>> > pq;
    char arr[n];
    int nx[n], pv[n];
    forn(i, 0, n) cin >> arr[i], nx[i] = i+1, pv[i] = i - 1;
    int count = 0;
    forn(i, 0, n-1) {
        if (m[mp(arr[i], arr[nx[i]])]){
            pq.push(mp(arr[i] - '0', mp(i, nx[i])));
        }
    }
    while(pq.empty() == false){
        int p = pq.top().fi, i = pq.top().se.fi, j = pq.top().se.se;
        pq.pop();
        if (j != nx[i]) continue;
        if (nx[i] == n) continue;
        if (m[mp(arr[i], arr[j])]){
            arr[i] = m[mp(arr[i], arr[j])];
            int temp = nx[j];
            nx[j] = n;
            pv[j] = -1;
            nx[i] = temp;
            if (pv[i] != -1) {
                if (m[mp(arr[pv[i]], arr[i])]){
                    pq.push(mp(p+1, mp(pv[i], i)));
                }
            }
            if (nx[i] != n) {
                pv[nx[i]] = i;
                if (m[mp(arr[i], arr[nx[i]])]){
                    pq.push(mp(p+2, mp(i, nx[i])));
                }
            }
        }
    }
    int cur = 0;
    while(cur != n){
        cout << arr[cur];
        cur = nx[cur];
    }
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}