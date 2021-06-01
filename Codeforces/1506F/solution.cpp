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
        
int main(){
    int t;
    cin >> t;
    forn(T, 0, t){
        int n;
        cin >> n;
        pair<int, int> arr[n+1];

        forn(i, 0, n) cin >> arr[i+1].fi;
        forn(i, 0, n) cin >> arr[i+1].se;
        arr[0].fi = 1;
        arr[0].se = 1;
        sort(arr, arr+n+1);
        ll cost = 0;
        forn(i, 1, n+1){
            if(arr[i].fi - arr[i].se == arr[i-1].fi - arr[i-1].se){
                if (((arr[i].fi + arr[i].se) & 1) == 0) {
                    cost += (arr[i].se - arr[i-1].se);
                } else {

                }
            } else {
                if (((arr[i-1].fi + arr[i-1].se) & 1) == 0){
                    arr[i-1].fi++;
                }
                arr[i-1].fi += (arr[i].se - arr[i-1].se);
                arr[i-1].se += (arr[i].se - arr[i-1].se);
                cost += (arr[i].fi - arr[i-1].fi)/2 + (((arr[i].fi + arr[i].se) & 1) == 0);
            }
        }
        cout << cost << '\n';
    }
    
}