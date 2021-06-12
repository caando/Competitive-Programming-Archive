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
using int128 = __int128_t;

int main(){
    int n;
    cin >> n;
    int arr[n];
    forn(i, 0, n){
        cin >> arr[i];
    }
    int lis[n], lds[n];
    for(int i = n-1; i >= 0; i--){
        int higher = 0, lower = 0;
        for(int j = n-1; j > i; j--){
            if (lis[j] > higher && arr[i] > arr[j]) higher = lis[j];
            if (lds[j] > lower && arr[i] < arr[j]) lower = lds[j];
        }
        lis[i] = higher + 1, lds[i] = lower + 1;
    }
    int high = 0;
    forn(i, 0, n){
        if (lis[i] + lds[i] - 1 > high) high = lis[i] + lds[i] - 1;
    }
    cout << high;
}