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
    int n, m;
    cin >> n >> m;
    char cw[n][m];
    vector<pair<pair<int, int>, char>> letters;
    forn(i, 0, n){
        forn(j, 0, m) {
            cin >> cw[i][j];
            if (cw[i][j] != '.' && cw[i][j] != '#') letters.pb(mp(mp(i, j), cw[i][j]));
        }
    }
    vector<pair<int, int>> wv[m], wh[n];
    forn(i, 0, n){
        int start = 0, end = -1;
        forn(j, 0, m){
            if (cw[i][j] != '#'){
                end = j;
            } else {
                if (start <= end){
                    wh[i].pb(mp(start, end));
                }
                start = j+1, end = j;
            }
        }
        if (start < m){
            wh[i].pb(mp(start, m-1));
        }
    }
    forn(j, 0, m){
        int start = 0, end = -1;
        forn(i, 0, n){
            if (cw[i][j] != '#'){
                end = i;
            } else {
                if (start <= end){
                    wv[j].pb(mp(start, end));
                }
                start = i+1, end = i;
            }
        }
        if (start < n){
            wv[j].pb(mp(start, n-1));
        }
    }
    int i =0, count = 0;
    while(i < letters.size()){
        int x = letters[i].fi.fi, y=letters[i].fi.se;
        char l = letters[i].se;
        if(cw[x][y] != l) cw[x][y] = l, count++;
        auto a = upper_bound(wh[x].begin(), wh[x].end(), mp(y, INT_MAX));
        a--;
        int posa = ((*a).se - (y-(*a).fi));
        if (cw[x][posa] != l) {
            letters.push_back(mp(mp(x, posa), l));
        }

        auto b = upper_bound(wv[y].begin(), wv[y].end(), mp(x, INT_MAX));
        b--;
        int posb = ((*b).se - (x-(*b).fi));
        if (cw[posb][y] != l) {
            letters.push_back(mp(mp(posb, y), l));
        }
        i++;
    }
    cout << count << endl;
    forn(i, 0, n){
        forn(j, 0, m) cout << cw[i][j];
        cout << endl;
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