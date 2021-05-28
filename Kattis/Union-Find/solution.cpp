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
    int n, q;
    cin >> n >> q;
    int ufds[n+1], height[n+1];
    forn(i, 0, n+1) {
        ufds[i] = i;
        height[i] = 0;
    }
    forn(i, 0, q){
        char c;
        scanf(" %c", &c);
        int a, b;
        scanf("%d %d", &a, &b);
        if (c == '='){
            while (ufds[a] != a) {
                a = ufds[a];
            }
            while (ufds[b] != b){
                b = ufds[b];
            }
            if (a != b){
                if (height[b] > height[a]){
                    ufds[a] = b;
                    height[b] = max(height[b], height[a] + 1);
                } else {
                    ufds[b] = a;
                    height[a] = max(height[a], height[b] + 1);
                }
            }
        } else if (c == '?') {
            while (ufds[a] != a) {
                a = ufds[a];
            }
            while (ufds[b] != b){
                b = ufds[b];
            }
            if (a == b) printf("yes\n");
            else printf("no\n");
        }
    }
}
