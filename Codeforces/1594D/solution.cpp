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
const int MAXN = 100005;

void solve(){
    int n, m;
    cin >> n >> m;
    int ufds[n], rank[n], parity[n];
    bool poss = true;
    memset(rank, 0, sizeof rank);
    memset(parity, 0, sizeof parity);
    forn(i, 0, n) ufds[i] = i;
    forn(i, 0, m){
        int a, b, pa=0, pb=0;
        string c;
        cin >> a >> b >> c;
        a--;
        b--;
        while(ufds[a] != a) pa += parity[a], a = ufds[a];
        while(ufds[b] != b) pb += parity[b], b = ufds[b];
        if (a == b){
            if (c == "imposter"){
                if (abs(pa - pb) % 2 == 0) poss = false;
            } else {
                if (abs(pa - pb) % 2 == 1) poss = false;
            }
        } else {
            if (c == "imposter"){
                if (rank[a] >= rank[b]){
                    ufds[b] = a;
                    parity[b] = (abs(pa+pb) + 1)%2;
                    if (rank[a] == rank[b]) rank[a]++;
                } else {
                    ufds[a] = b;
                    parity[a] = (abs(pa+pb) + 1)%2;
                }
            } else {
                if (rank[a] >= rank[b]){
                    ufds[b] = a;
                    parity[b] = (abs(pa+pb))%2;
                    if (rank[a] == rank[b]) rank[a]++;
                } else {
                    ufds[a] = b;
                    parity[a] = (abs(pa+pb))%2;
                }
            }
        }
    }
    int counter[n], s[n];
    memset(counter, 0, sizeof counter);
    memset(s, 0, sizeof s);
    forn(i, 0, n){
        int p = 0, curr = i;
        while(ufds[curr]!=curr) p+= parity[curr], curr = ufds[curr];
        if (p%2) counter[curr]++;
        s[curr]++;
    }
    int ans = 0, t = 0;
    forn(i, 0, n){
        ans += max(counter[i], s[i]-counter[i]);
        t+= s[i];
    }
    if (!poss) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--)solve();
}