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
    
int main(){
    ll n;
    cin >> n;
    cout << "? " << 1 << ' ' << n << '\n';
    cout.flush();
    int smax;
    cin >> smax;
    int temp;
    if (smax == 1) temp = 0;
    else {
        cout << "? " << 1 << ' ' << smax << '\n';
        cout.flush();
        cin >> temp;
    }
    if (temp == smax){
        int low = 1, high = smax;
        int curr = smax;
        while (low <= high){
            int mid = (low + high) / 2;
            if (mid == smax) {
                low = high; 
                break;
            }
            cout << "? " << mid << ' ' << smax << '\n';
            cout.flush();
            cin >> curr;
            if (curr == smax){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << "! " << low - 1 << '\n';
    } else {
        int low = smax, high = n;
        int curr = smax;
        while (low <= high){
            int mid = (low + high) / 2;
            if (mid == smax) {
                high = low; 
                break;
            }
            cout << "? " << smax << ' ' << mid << '\n';
            cout.flush();
            cin >> curr;
            if (curr == smax){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "! " << high + 1 << '\n';
    }
}