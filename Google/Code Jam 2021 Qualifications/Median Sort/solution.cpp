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
    int t, n, q;
    cin >> t >> n >> q;
    char data[100][10000];
    forn(T, 0, t){
        vector<int> arr;
        arr.pb(1);
        arr.pb(2);
        forn(i, 3, n+1){
            int l = 0, r = arr.size() - 1;
            while (l <= r){
                int mid1 = l + (r - l) / 3;
                int mid2 = r - (r - l) / 3;
                if (mid1 == mid2){
                    if (mid2 != arr.size() - 1){
                        cout << arr[mid1] << ' ' << arr[mid2+1] << ' ' << i << endl << flush;
                        int temp;
                        cin >> temp;
                        if (temp == arr[mid1]){
                            r = mid1-1;
                        } else if (temp == arr[mid2+1]){
                            l = mid2+2;
                        } else {
                            l = mid2+1;
                        }
                    } else {
                        cout << arr[mid1-1] << ' ' << arr[mid2] << ' ' << i << endl << flush;
                        int temp;
                        cin >> temp;
                        if (temp == arr[mid1-1]){
                            r = mid1-2;
                        } else if (temp == arr[mid2]){
                            l = mid2+1;
                        } else {
                            r = mid1-1;
                        }
                    }
                } else {
                    cout << arr[mid1] << ' ' << arr[mid2] << ' ' << i << endl << flush;
                    int temp;
                    cin >> temp;
                    if (temp == arr[mid1]){
                        r = mid1-1;
                    } else if (temp == arr[mid2]){
                        l = mid2+1;
                    } else {
                        r = mid2-1;
                        l = mid1+1;
                    }
                }
            }
            vector<int> next;
            forn(j, 0, arr.size()){
                if (j == l) next.pb(i);
                next.pb(arr[j]);
            }
            if (arr.size() == l) next.pb(i);
            arr = next;
        }
        
        forn(i, 0, arr.size()){
            cout << arr[i] << ' ';
        }
        cout << endl << flush;
        
        int temp;
        cin >> temp;
        if (temp == -1){
            break;
        }
    }
}
