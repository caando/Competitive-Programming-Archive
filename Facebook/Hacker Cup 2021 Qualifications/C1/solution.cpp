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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 300001;

int n;
vector<vector<int>> adjlist;
vector<ll> cnt, gold;

ll dfs(int curr, int p){
    ll high=0;
    for(int i : adjlist[curr]){
        if (i != p){
            ll score = dfs(i, curr);
            if (score > high) high = score;
        }
    }
    cnt[curr] = gold[curr] + high;
    return cnt[curr];
}

void solve(int T){
    cout << "Case #" << T << ": ";
    cin >> n;
    adjlist = vector<vector<int>>(n);
    cnt = vector<ll>(n, 0);
    gold = vector<ll>(n, 0);
    forn(i, 0, n) cin >> gold[i];
    forn(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        adjlist[a-1].pb(b-1);
        adjlist[b-1].pb(a-1);
    }
    dfs(0, -1);
    ll high=0, high1=0;
    for(int i : adjlist[0]){
        if (cnt[i] > high) high1= high, high = cnt[i];
        else if (cnt[i] > high1) high1 = cnt[i];
    }
    cout << high + high1 + gold[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T+1);
}