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

int main() {
    int N, K;
    cin >> N >> K;
    int ufds[N], height[N];
    forn(i, 0, N) {
        ufds[i] = i;
        height[i] = 0;
    }
    forn(i, 0, K){
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        p1--;
        p2--;
        while (ufds[p1] != p1){
            p1 = ufds[p1];
        }
        while (ufds[p2] != p2){
            p2 = ufds[p2];
        }
        if (height[p1] >= height[p2]){
            ufds[p2] = ufds[p1];
            height[p1] = max(height[p1], height[p2] + 1);
        } else {
            ufds[p1] = ufds[p2];
            height[p2] = max(height[p2], height[p1] + 1);
        }
    }
    bool poss = true;
    forn(i, 0, N){
        int p1 = i, p2 = N-1-i;
        while (ufds[p1] != p1){
            p1 = ufds[p1];
        }
        while (ufds[p2] != p2){
            p2 = ufds[p2];
        }
        if (p1 != p2) poss = false;
    }
    if (poss) cout << "Yes\n";
    else cout << "No\n";
}