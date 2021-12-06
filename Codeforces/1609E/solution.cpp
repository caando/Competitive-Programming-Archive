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
const int MAXN = 100000;

// a, b, c, ab, bc
vector<int> t[4*MAXN];

vector<pair<pair<int, int>, int>> p;

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c(32, 100000);
    for(auto it : p){
        c[it.se] = min(c[it.se], a[it.fi.fi] + b[it.fi.se]);
    }
    return c;
}

vector<int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return vector<int>(32, 0);
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm)),
           query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, char c) {
    if (tl == tr) {
        t[v] = vector<int>(32, 100000);
        t[v][1] = 1;
        t[v][2] = 1;
        t[v][4] = 1;
        if (c == 'a'){
            t[v][1] = 0;
        } else if (c == 'b'){
            t[v][2] = 0; 
        } else {
            t[v][4] = 0; 
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, c);
        else
            update(v*2+1, tm+1, tr, pos, c);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}

void solve(){
    forn (i, 0, 32){
        forn(j, 0, 32) {
            if ((i&8) && (i&3)!=3) continue;
            if ((j&8) && (j&3)!=3) continue;
            if ((i&16) && (i&6)!=6) continue;
            if ((j&16) && (j&6)!=6) continue;
            if (((i&8) && (j&4))) continue;
            if ((i&1) && (j&16)) continue;
            int d = i|j;
            if ((i&1)&&(j&2)) d |= 8;
            if ((i&2)&&(j&4)) d |= 16;
            p.pb(mp(mp(i, j), d));
        } 
    }
    forn(i, 0, 4*MAXN) t[i] = vector<int>(32, 100000);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    forn(i, 0, n){
        update(1, 0, n-1, i, s[i]);
    }
    forn(i, 0, q){
        int pos;
        char c;
        cin >> pos >> c;
        s[pos-1] = c;
        update(1, 0, n-1, pos-1, s[pos-1]);
        int low = 100000;
        for(int i : query(1, 0, n-1, 0, n-1)){
            if (i < low) low = i;
        }
        cout << low << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}