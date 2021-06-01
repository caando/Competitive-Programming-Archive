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
    
int arr[200000];

int temp[200000];

ll mergesort(int a, int b){
    if (a == b) return 0;
    int mid = (a + b) / 2;
    ll res = mergesort(a, mid) + mergesort(mid + 1, b);

    int i1 = a, i2 = mid+1, index = a;
    while(i1 <= mid || i2 <= b){
        if (i2 > b){
            temp[index] = arr[i1];
            i1++;
        } else if (i1 > mid){
            res += i2 - index;
            temp[index] = arr[i2];
            i2++;
        } else if(arr[i2] < arr[i1]){
            res += i2 - index;
            temp[index] = arr[i2];
            i2++;
        } else {
            temp[index] = arr[i1];
            i1++;
        }
        index++;
    }
    forn (i, a, index) arr[i] = temp[i];
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    set<int> alpha1[26];
    set<int> alpha2[26];
    forn(i, 0, n) {
        char temp;
        scanf(" %c", &temp);
        alpha1[(int)temp - 97].insert(i);
        alpha2[(int)temp - 97].insert(n - i - 1);
    }
    for (int i=0; i < 26; i++){
        auto it2 = alpha2[i].begin();
        for (auto it1 = alpha1[i].begin(); it1 != alpha1[i].end(); ++it1){
            arr[*it1] = *it2;
            ++it2;
        }
    }
    cout << mergesort(0, n-1);
    
}