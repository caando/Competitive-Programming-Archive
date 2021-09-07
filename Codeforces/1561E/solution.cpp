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
    int n;
    cin >> n;
    int arr[n];
    bool poss = true;
    forn(i, 0, n) {
        cin >> arr[i];
        if (!((i - arr[i])&1)){
            poss = false;
        } 
    }
    if (poss){
        vector<int> rev;
        int i = n;
        while(i > 1){
            int pos = 0;
            forn(j, 0, n) if (arr[j] == i) {
                pos = j;
                break;
            }
            if (pos == 0 && arr[1] == i - 1) {
                rev.pb(i);
                int temp[i];
                forn(j, 0, i) temp[j] = arr[j];
                forn(j, 0, i) arr[j] = temp[i - 1 - j];
                i-=2;
            } else {
                if (pos + 1 == i){
                    if (arr[pos-1] != i-1){
                        rev.pb(pos+1);
                        int temp[pos+1];
                        forn(j, 0, pos+1) temp[j] = arr[j];
                        forn(j, 0, pos+1) arr[j] = temp[pos - j];
                    } else i-= 2;
                } else {
                    if (arr[pos-1] != i - 1 || pos == 0) {
                        if (arr[pos+1] == i - 1 && pos != n - 1){
                            rev.pb(pos+3);
                            int temp[pos+3];
                            forn(j, 0, pos+3) temp[j] = arr[j];
                            forn(j, 0, pos+3) arr[j] = temp[pos - j+2];
                        } else {
                            int find = 0;
                            forn(j, 0, n) if (arr[j] == i-1) {
                                find = j;
                                break;
                            }
                            if (find < pos){
                                rev.pb(pos+1);
                                int temp[pos+1];
                                forn(j, 0, pos+1) temp[j] = arr[j];
                                forn(j, 0, pos+1) arr[j] = temp[pos - j];
                            } else {
                                if (pos != 0){
                                    rev.pb(pos+1);
                                    int temp[pos+1];
                                    forn(j, 0, pos+1) temp[j] = arr[j];
                                    forn(j, 0, pos+1) arr[j] = temp[pos - j];
                                }
                                rev.pb(find);
                                int temp1[find];
                                forn(j, 0, find) temp1[j] = arr[j];
                                forn(j, 0, find) arr[j] = temp1[find - j - 1];
                            }
                        }
                    } else {
                        rev.pb(pos+1);
                        int temp[pos+1];
                        forn(j, 0, pos+1) temp[j] = arr[j];
                        forn(j, 0, pos+1) arr[j] = temp[pos - j];
                    }
                }
            }
        }
        cout << rev.size() << endl;
        forn(i, 0, rev.size()) cout << rev[i] << ' ';
        cout << endl;
    } else cout << -1 << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}