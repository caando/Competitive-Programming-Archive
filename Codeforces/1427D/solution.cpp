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
 
int main() {
    int r, n;
    scanf("%d %d", &r, &n);
    int celeb[n][3];
    forn(i, 0, n) scanf("%d %d %d", &celeb[i][0], &celeb[i][1], &celeb[i][2]);
 
    int dp[n];
    forn(i, 0, n) dp[i] = 0;
    forn(i, 0, n){
        if (abs(celeb[i][1] - 1) + abs(celeb[i][2] - 1) <= celeb[i][0]) dp[i] = 1;
        for (int j= i-1; j >= 0; j--){
            if (abs(celeb[i][1] - celeb[j][1]) + abs(celeb[i][2] - celeb[j][2]) <= celeb[i][0] - celeb[j][0] && dp[j] != 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            if (celeb[i][0] - celeb[j][0] > 5 * r) break;
        }
    }
    int high = 0;
    forn(i, 0, n) if (dp[i] > high) high = dp[i]; 
    cout << high;
 
}