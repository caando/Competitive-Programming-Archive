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

vector<int> solve(int c, int i, int n){
    vector<int> lst;
    if (i >= n - 1){
        lst.pb(i+1);
        return lst;
    }
    if (c >= (n-i-1)) {
        vector<int> temp = solve(c-(n-i-1), i+1, n);
        forn(i, 0, temp.size()){
            lst.pb(temp[temp.size() - 1 - i]);
        }
        lst.pb(i+1);
    } else {
        vector<int> temp = solve(c, i+1, n);
        lst.pb(i+1);
        forn(i, 0, temp.size()){
            lst.pb(temp[i]);
        }
    }
    return lst;
};

int main(){
    int t;
    cin >> t;
    forn(T, 0, t){
        ll ans = 0;
        ll n, c;
        cin >> n >> c;
        if (c < n - 1 || (n-1) * (2*2 + (n-2))/2 < c){
            cout << "Case #" << T + 1 << ": IMPOSSIBLE\n";
        } else {
            c -= n-1;
            vector<int> ans = solve(c, 0, n);
            
            cout << "Case #" << T + 1 << ": " ;
            forn(i, 0, ans.size()) {
                cout << ans[i] << ' ';
            }
            cout <<  '\n';
        }
    }
}
