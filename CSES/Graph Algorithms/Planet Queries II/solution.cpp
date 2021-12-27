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

int l[MAXN], r[MAXN], t[MAXN][19], cyc[MAXN], cyc_pos[MAXN];
vector<int> c[MAXN];
int cnt = 0;

void dfs(int cur, int root){
    forn(i, 1, 19){
        if (t[cur][i-1] != -1) t[cur][i] = t[t[cur][i-1]][i-1];
    }
    l[cur] = cnt++;
    for(int v : c[cur]) if(v != root) dfs(v, root);
    r[cur] = cnt++;
}

void solve(){
    int n, q;
    cin >> n >> q;
    forn(i, 0, n){
        forn(j, 0, 19) t[i][j] = -1;
    }
    forn(i, 0, n) {
        int p;
        cin >> p;
        if (p - 1 != i){
            t[i][0] = p - 1;
            c[t[i][0]].pb(i);
        }
    }
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(cyc, 0, sizeof cyc);
    memset(cyc_pos, 0, sizeof cyc_pos);
    forn(i, 0, n){
        int cur = i;
        while (!cyc[cur]){
            cyc[cur] = i+1;
            cur = t[cur][0];
        }
        int end = cur;
        cur = i;
        while(cur != end) {
            cyc[cur] = -1;
            cur = t[cur][0];
        }
        if (!cyc_pos[end] && cyc[end] == i+1){
            int pos = 1;
            cyc_pos[end] = pos++;
            cyc[end] = end+1;
            cur = t[end][0];
            while(cur != end && !cyc_pos[cur]){
                cyc[cur] = end+1;
                cyc_pos[cur] = pos++;
                cur = t[cur][0];
            }
            t[end][0] = -1;
        }
    }
    forn(i, 0, n){
        if (t[i][0] == -1){
            dfs(i, i);
        }
    }
    forn(i, 0, q){
        int a, b;
        cin >> a >> b;
        a--, b--;
        int ans = 0;
        if (l[b] <= l[a] && r[b] >= r[a]){
            int cur = a;
            while(cur != b){
                int nxt = cur, c = 0;
                forn(i, 0, 19){
                    if (t[cur][i] == -1) break;
                    if (l[b] <= l[t[cur][i]] && r[b] >= r[t[cur][i]]){
                        c = (1 << i);
                        nxt = t[cur][i];
                    }
                }
                cur = nxt;
                ans += c;
            }
            cout << ans << '\n';
        } else if (cyc[b] != -1){
            ans += cyc_pos[b] - 1;
            b = cyc[b]-1;
            if (l[b] <= l[a] && r[b] >= r[a]){
                int cur = a;
                while(cur != b){
                    int nxt = cur, c = 0;
                    forn(i, 0, 19){
                        if (t[cur][i] == -1) break;
                        if (l[b] <= l[t[cur][i]] && r[b] >= r[t[cur][i]]){
                            c = (1 << i);
                            nxt = t[cur][i];
                        }
                    }
                    cur = nxt;
                    ans += c;
                }
                cout << ans << '\n';
            } else cout << -1 << '\n';
        } else cout << -1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}