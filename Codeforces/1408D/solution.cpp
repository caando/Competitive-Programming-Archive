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
#define forn(i,n)  for (int i = 0, nnnn = (n); i < nnnn; ++i)
#define pb  push_back

int n, m;
pii r[2000];
pii s[2000];

set<int> S;

int recursive(int x_curr, int y_curr){
    if (S.size() > 0){
        if (*S.begin() <= x_curr + y_curr) return x_curr + y_curr;
    }
    int x_min = 0, y_min = 0;
    forn(j, m){
        forn(i, n){
            if (s[j].fi + 1 - r[i].fi - x_curr <= s[j].se + 1 - r[i].se - y_curr){
                if (x_min < s[j].fi + 1 - r[i].fi - x_curr) x_min = s[j].fi + 1 - r[i].fi - x_curr;
            } else {
                if (y_min < s[j].se + 1 - r[i].se - y_curr) y_min = s[j].se + 1 - r[i].se - y_curr;
            }
        }
    }
    if (x_min == 0 && y_min == 0) {
        S.insert(x_curr + y_curr);
        return x_curr + y_curr;
    }
    if (x_min == 0) return recursive(x_curr, y_curr + y_min);
    if (y_min == 0) return recursive(x_min + x_curr, y_curr);
    return min(recursive(x_min + x_curr, y_curr), recursive(x_curr, y_curr + y_min));
}

int main() {
    cin >> n >> m;
    forn(i, n) cin >> r[i].fi >> r[i].se;
    forn(j, m) cin >> s[j].fi >> s[j].se;
    cout << recursive(0, 0);
}