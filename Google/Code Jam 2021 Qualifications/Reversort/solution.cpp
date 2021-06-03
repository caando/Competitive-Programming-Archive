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
        ll ans = 0;
        ll n;
        cin >> n;
        ll arr[n];
        forn(i, 0, n){
            scanf("%lld", &arr[i]);
        }
        forn(i, 0, n-1){
            int low = i;
            forn(j, i + 1, n){
                if (arr[j] < arr[low]) low = j;
            }
            ans += low - i + 1;
            if (low > i) {
                vector<int> lst;
                forn(j, i, low + 1){
                    lst.pb(arr[j]);
                }
                forn(j, 0, lst.size()){
                    arr[i+j] = lst[lst.size() - j - 1];
                }
            }
        }
        cout << "Case #" << T + 1 << ": " << ans << '\n';
    }
}