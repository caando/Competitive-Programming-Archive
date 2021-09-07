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
    cout << "Case #" << T+1 << ": ";
    string s;
    cin >> s;
    int matrix[26][26];
    forn(i, 0, 26){
        forn(j, 0, 26){
            if (i == j) {
                matrix[i][j] = 0;
            } else if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                if (j == 0 || j == 4 || j == 8 || j == 14 || j == 20){
                    matrix[i][j] = 2;
                } else {
                    matrix[i][j] = 1;
                }
            } else {
                if (j == 0 || j == 4 || j == 8 || j == 14 || j == 20){
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 2;
                }
            }
            
        }
    }
    ll low = INT_MAX;
    forn(i, 0, 26){
        ll score = 0;
        forn(j, 0, s.size()){
            score += matrix[s[j]-'A'][i];
        }
        if (score < low) low = score;
    }
    cout << low << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(T, 0, t) solve(T);
}