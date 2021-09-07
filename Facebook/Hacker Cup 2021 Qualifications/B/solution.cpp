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

void solve(int T){
    cout << "Case #" << T << ": ";
    int n;
    cin >> n;
    char g[n][n];
    forn(i, 0, n) forn(j, 0, n) cin >> g[i][j];
    ll low = INT_MAX, count = 0;
    forn(i, 0, n){
        ll score = 0;
        forn(j, 0, n) {
            if (g[i][j] == '.') score++;
            else if (g[i][j] == 'O') score += INT_MAX;
        }
        if (score < low) low = score, count = 1;
        else if (score == low) count++;
    }
    forn(i, 0, n){
        ll score = 0, index = 0;
        forn(j, 0, n) {
            if (g[j][i] == '.') score++, index = j;
            else if (g[j][i] == 'O') score += INT_MAX;
        }
        if (score < low) low = score, count = 1;
        else if (score == low) {
            if (score == 1){
                int score1 = 0;
                forn(k, 0, n){
                    if (g[index][k] == '.') score1++;
                    else if (g[index][k] == 'O') score1 += INT_MAX;
                }
                if (score1 != 1) count++;
            } else count++;
        }
    }
    if (low >= INT_MAX) cout << "Impossible";
    else cout << low << ' ' << count;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T+1);
}