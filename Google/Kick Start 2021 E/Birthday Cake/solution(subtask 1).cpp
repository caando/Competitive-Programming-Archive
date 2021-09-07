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
const long long mod = 1000000007;
const int MAXN = 200000;

void solve(int t){
    cout << "Case #" << t+1 << ": ";
    int r, c, k, r1, c1, r2, c2;
    cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;
    if (k==1) {
        bool vert[r][c+1], hori[r+1][c];
        memset(vert, 0, sizeof vert);
        memset(hori, 0, sizeof hori);
        int small = INT_MAX;
        small = min(small, c - max(c1, c2));
        small = min(small, min(c1, c2) - 1);
        small = min(small, r - max(r1, r2));
        small = min(small, min(r1, r2) - 1);
        forn(i, 0, r) vert[i][0] = true, vert[i][c] = true;
        forn(i, 0, c) hori[0][i] = true, hori[r][i] = true;
        int count = 0;
        forn(i, min(r1, r2)-1, max(r1, r2)){
            forn(j, min(c1, c2)-1, max(c1, c2)){
                if (!vert[i][j]) count++, vert[i][j] = true;
                if (!vert[i][j+1]) count++, vert[i][j+1] = true;
                if (!hori[i][j]) count++, hori[i][j] = true;
                if (!hori[i+1][j]) count++, hori[i+1][j] = true;
            }
        }
        cout << count + small << endl;

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(i,0, t) solve(i);
}