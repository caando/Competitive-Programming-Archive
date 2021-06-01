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
    int n, m, k;
    cin >> n >> m >> k;
    ll dp[n+1][m+1][m/2+1][k];
    int arr[71][71];
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++){
            for (int c = 0; c < m/2+1; c++){
                for (int l = 0; l < k; l++) dp[i][j][c][l] = -1;
            }
        }
    }
    dp[0][0][0][0] = 0;
    dp[1][0][0][0] = 0;
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++) cin >> arr[i][j];
    }

    for (int i = 1; i < n+1; i++){
        for (int l = 0; l < k; l++) {
            for (int c = 0; c <= m/2+1; c++) {
                if (dp[i][0][0][l] < dp[i-1][m][c][l]) dp[i][0][0][l] = dp[i-1][m][c][l];
            }
        }
        for (int j = 1; j < m+1; j++) {
            for (int c = 0; c < m/2+1; c++){
                for (int l = 0; l < k; l++){
                    if (dp[i][j-1][c][l] >= 0){
                        if (dp[i][j-1][c][l] > dp[i][j][c][l]) dp[i][j][c][l] = dp[i][j-1][c][l];
                    }
                    if (c > 0){
                        int temp = l - arr[i][j];
                        while (temp < 0) temp += k;
                        if (dp[i][j-1][c-1][temp] >= 0){
                            if (dp[i][j-1][c-1][temp] + arr[i][j] > dp[i][j][c][l]) dp[i][j][c][l] = dp[i][j-1][c-1][temp] + arr[i][j];
                        }
                    }
                }
            }
        }
    }

    int highest = 0;
    for (int c = 0; c < m/2+1; c++){
        if (dp[n][m][c][0] > highest) highest = dp[n][m][c][0];
    }
    cout << highest;
}