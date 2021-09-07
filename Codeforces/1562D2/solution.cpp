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

int n, dp[MAXN];

int sum(int l, int r){
    if (l == 0) return dp[min(n-1, r)];
    else return dp[min(n-1, r)] - dp[l-1];
}

void solve(){
    int q;
    cin >> n >> q;
    char a[n];
    forn(i, 0, n) cin >> a[i];
    memset(dp, 0, sizeof dp);
    if (a[0] == '+') dp[0] -= 1;
    else dp[0] += 1;
    forn(i, 1, n){
        dp[i] = dp[i-1];
        if (i & 1){
            if (a[i] == '+') dp[i] += 1;
            else dp[i] -= 1;
        } else {
            if (a[i] == '+') dp[i] -= 1;
            else dp[i] += 1;
        }
    }
    forn(i, 0, q){
        int l, r;
        cin >> l >> r;
        if (l == r){
            cout << 1 << endl << l << endl;
        } else {
            int res = abs(sum(l-1, r-1));
            if (res == 0) cout << 0 << endl;
            else {
                if (res & 1){
                    cout << 1 << endl;
                } else {
                    cout << 2 << endl;
                    cout << l << ' ';
                    l++;
                }
                int low = l-1, high = r-1;
                while (low <= high){
                    int mid = (low + high)/2;
                    if (abs(sum(l-1, mid)) < abs(sum(mid+1, r-1))){
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (abs(sum(l-1, low-1)) == abs(sum(low + 1, r-1))) {
                    cout << low + 1 << endl;
                } else {
                    cout << low << endl;
                }
            }
        }
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