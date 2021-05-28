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
int spf[10000001];
int n;
pair<int, int> ranges[1000001];
int table1[10000001];
int table2[10000001];
bool poss = true;
int parent[1000001];

int solve(int l, int r){
    if (l == r) return l;
    if (r < l) return -1;
    int pos = -1;
    forn(i, 0, (r-l)/2 + 1){
        if (ranges[i+l].fi < l && ranges[i+l].se > r){
            pos = i+l;
            break;
        } 
        if (ranges[r-i].fi < l && ranges[r-i].se > r){
            pos = r-i;
            break;
        }
    }
    if (pos == -1) {
        poss = false;
        return -1;
    }
    int L = solve(l, pos - 1), R = solve(pos + 1, r);
    if (L != -1) parent[L] = pos+1;
    if (R != -1) parent[R] = pos+1;
    return pos;
}


int main() {
    cin >> n;
    int arr[n];
    forn(i, 0, n){
        scanf("%d", &arr[i]);
    }
    forn(i, 1, 10000001){
        spf[i] = i;
    }
    for(int j= 0; j < 10000001/2; j ++) {
        spf[j*2] = 2;
    }
    for(int j= 1; j < 10000001/3; j+=2) {
        spf[j*3] = 3;
    }

    for(int i= 5; i < 10000001; i += 2){
        if (spf[i] == i){
            for(int j= 1; j < 10000001/i; j +=2) {
                if (i < spf[j*i]) spf[j*i] = i;
            }
        }
    }
    vector<int>factors[n];
    forn(i, 0, n){
        int curr = arr[i];
        int prev = 1;
        while (curr != 1){
            if (spf[curr] > prev) {
                factors[i].pb(spf[curr]);
                prev = spf[curr];
            }
            curr = curr/spf[curr];
        }
    }
    forn(i, 0, 10000001) table1[i] = -1;
    forn(i, 0, 10000001) table2[i] = n;
    forn(i, 0, n) {
        ranges[i].fi = -1;
        ranges[i].se = n;
    }

    forn (i, 0, n) parent[i] = 0;
    forn(i, 0, n){
        forn(j, 0, factors[i].size()){
            if (table1[factors[i][j]] > ranges[i].fi) ranges[i].fi = table1[factors[i][j]];
            table1[factors[i][j]] = i;
        }
    }
    for(int i = n-1; i >= 0; i--){
        forn(j, 0, factors[i].size()){
            if (table2[factors[i][j]] < ranges[i].se) ranges[i].se = table2[factors[i][j]];
            table2[factors[i][j]] = i;
        }
    }
    solve(0, n-1);
    if (poss){
        forn(i, 0, n) {
            printf("%d ", parent[i]);
        }
    } else {
        printf("impossible");
    }
}