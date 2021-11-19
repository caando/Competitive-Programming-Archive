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

string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> s; 

vector<int> cur;
int n;
vector<char> store;
vector<char> ans;

unordered_map<int, vector<vector<int>>> m;

void dfs(){
    for(char c : a){
        vector<int> nxt = cur, pv = cur;
        bool pos = true;
        forn(i, 0, n){
            bool found = false;
            for(; nxt[i] < sz(s[i]) && !found; nxt[i]++){
                if (s[i][nxt[i]] == c){
                    if (sz(ans) < sz(store) + sz(s[i]) - nxt[i]) found = true;
                }
            }
            if (!found){
                pos = false;
            }
        }
        if (pos){
            bool optimal = true;
            for(auto it : m[sz(store) + 1]){
                bool smaller = true;
                forn(j, 0, n){
                    if (it[j] > nxt[j]) smaller = false;
                }
                if (smaller) optimal = false;
            }
            if(optimal){
                m[sz(store) + 1].pb(nxt);
                cur = nxt;
                store.pb(c);
                if (sz(store) > sz(ans)) {
                    ans = store;
                }
                dfs();
                cur = pv;
                store.pop_back();
            }
        }
    }
}

void solve(int T){
    cin >> n;
    cur = vector<int>(n, 0);
    ans.clear();
    store.clear();
    s.clear();
    m.clear();
    forn(i, 0, n){
        string temp;
        cin >> temp;
        s.pb(temp);
    }
    dfs();
    cout << sz(ans) << '\n';
    for(char c : ans) cout << c;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T+1);
}
