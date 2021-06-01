#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
#define fi first
#define se second
#define sz(c)  ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i,m, n)  for (int i = m, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair
ll P = 1000000007;
 
int main() {
    int n;
    cin >> n;
    pair<int, int> arr[n];
    int  total = 0;
    int range = 0;
    forn(i, 0, n){
        cin >> arr[i].fi >> arr[i].se;
        total += arr[i].se;
        range += arr[i].fi;
    }
    int results[n];
    forn(i, 0, n) results[i] = INT_MIN;
    int dp[n][range+1];
    forn(j, 0, n) forn(k, 0, range+1) dp[j][k] = -1;
    dp[0][arr[0].fi] = arr[0].se + total;
    forn(k, 0, range+1) if (results[0] < min(dp[0][k], k*2)) results[0] = min(dp[0][k], k*2);
    forn(i, 1, n){
        int prev[n][range+2];
        forn(j, 0, n) forn(k, 0, range+1) prev[j][k] = dp[j][k];
        forn(j, 0, n) forn(k, 0, range+1) dp[j][k] = -1;

        forn(j, 0, i+1) dp[0][arr[j].fi] = arr[j].se + total;
        forn(j, 0, n){
            forn(k, 0, range+1){
                if (j == 0){
                    dp[j][k] = max(prev[j][k], dp[j][k]);
                } else {
                    if (k >= arr[i].fi) {
                        if (prev[j-1][k - arr[i].fi] != -1 && prev[j][k] != -1){
                            dp[j][k] = max(prev[j-1][k - arr[i].fi] + arr[i].se, prev[j][k]);
                        } else if (prev[j-1][k - arr[i].fi] != -1){
                            dp[j][k] = prev[j-1][k - arr[i].fi] + arr[i].se;
                        } else if (prev[j][k] != -1){
                            dp[j][k] = prev[j][k];
                        }
                    } else {
                        if (prev[j][k] != -1){
                            dp[j][k] = prev[j][k];
                        }
                    }
                }
            }
            forn(k, 0, range+1) if (results[j] < min(dp[j][k], k*2)) {
                results[j] = min(dp[j][k], k*2);
            }
        }
    }

    forn(i, 0, n){
        cout << (double)(results[i])/2 << ' ';
    }
}