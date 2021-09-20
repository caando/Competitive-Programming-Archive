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

void solve(){
    string n;
    int m;
	cin >> n >> m;
    n = '0' + n;
    
    ll temp = 0, curr = 0;
    forn(j, 1, n.size()){
        curr *= 10;
        curr += (n[j] - '0');
    }
    ll curr1 = curr;
    while (curr1 > 0) {
        temp |= (1 << (curr1 % 10));
        curr1 /= 10;
    }
    ll temp2 = temp;
    int counter = 0;
    while (temp2 > 0) counter += (temp2 & 1ll), temp2 >>= 1ll;
    if (counter <= m) cout << curr << endl;
    else {


    pair<ll, int> dp[n.size()+1][(1<<10)];
    forn(j, 0, n.size()) forn(i, 0, (1<<10)) dp[j][i].fi = INT32_MAX;
    forn(i, 1, 10){
        dp[0][(1<<i)].fi = i;
        dp[0][(1<<i)].se = 1;
    }
    forn(i, 1, n.size()) {
        forn(j, 0, (1ll<<10)) {
            if (dp[i-1][j].fi < __INT32_MAX__){
                forn(k, 0, 10) {
                    ll counter;
                    if (j&(1ll << k)) counter = dp[i-1][j].se;
                    else counter = dp[i-1][j].se + 1;
                    if (counter <= m){
                        if (dp[i - 1][j].fi * 10 + k < dp[i][(j | (1 << k))].fi){
                            dp[i][(j | (1 << k))].fi = dp[i - 1][j].fi * 10 + k;
                            dp[i][(j | (1 << k))].se = counter;
                        }
                    }
                }
            }
        }

        ll curr2 = 0;
        forn(j, 1, i+1){
            curr2 *= 10;
            curr2 += (n[j] - '0');
        }

        for(ll curr = curr2+1; (curr%10) != 0; curr++){
            ll curr1 = curr;
            ll temp = 0;
            while (curr1 > 0) {
                temp |= (1 << (curr1 % 10));
                curr1 /= 10;
            }
            ll temp2 = temp;
            int counter = 0;
            while (temp2 > 0) counter += (temp2 & 1ll), temp2 >>= 1ll;
            if (counter <= m){
                if (curr < dp[i][temp].fi) {
                    dp[i][temp].fi = curr;
                    dp[i][temp].se = counter;
                }
            }
        }

        }
        ll low = INT32_MAX;
        forn(j, 0, (1ll<<10)) if (dp[n.size()-1][j].fi < low) low = dp[n.size()-1][j].fi;
        cout << low << endl;
    }
     
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}