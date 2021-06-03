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
ll P = 1000000007;
#define INF 0x3f3f3f3f

int main(){
    int t;
    cin >> t;
    forn(T, 0, t){
        ll ans, x, y, curr = 0;
        string s;
        cin >> x >> y >> s;
        ll dp[s.size()][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        forn(i, 1, s.size()){
            if (s[i] == '?'){
                if (s[i-1] == 'C'){
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][0] + x;
                } else if (s[i-1] == 'J'){
                    dp[i][0] = dp[i-1][1] + y;
                    dp[i][1] = dp[i-1][1];
                } else {
                    dp[i][0] = min(dp[i-1][1] + y, dp[i-1][0]);
                    dp[i][1] = min(dp[i-1][0] + x, dp[i-1][1]);
                }
            } else if (s[i] == 'C'){
                if (s[i-1] == 'J') dp[i][0] = dp[i-1][1] + y;
                else if (s[i-1] == 'C') dp[i][0] = dp[i-1][0];
                else dp[i][0] = min((ll)dp[i-1][0], (ll)dp[i-1][1] + (ll)y);
            } else if (s[i] == 'J'){
                if (s[i-1] == 'C') dp[i][1] = dp[i-1][0] + x;
                else if (s[i-1] == 'J') dp[i][1] = dp[i-1][1];
                else dp[i][1] = min((ll)dp[i-1][1], (ll)dp[i-1][0] + (ll)x);
            }
        }
        cout << "Case #" << T + 1 << ": " << min(dp[s.size()-1][0], dp[s.size()-1][1]) << '\n';
    }
}