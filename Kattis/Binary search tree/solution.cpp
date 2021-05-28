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
    int n;
    cin >> n;
    set<pair<int, int>> values;
    int left[n], right[n], height[n];
    bool leftC[n], rightC[n];
    forn(i, 0, n){
        left[i] = INT_MIN;
        right[i] = INT_MAX;
        height[i] = 0;
        leftC[i] = false;
        rightC[i] = false;
    }
    values.insert(mp(0, 0));
    values.insert(mp(n+1, 0));
    long long count = 0;
    forn(i, 0, n){
        int value;
        scanf("%d", &value);
        auto se = values.lower_bound(mp(value, 0));
        auto fi = se;
        fi--;
        if ((*fi).fi == 0 || rightC[(*fi).se] == true){
            leftC[(*se).se] = true;
            right[i] = (*se).fi;
            left[i] = left[(*se).se];
            height[i] = height[(*se).se] + 1;
        } else if ((*se).fi == n+1 || leftC[(*se).se] == true){
            rightC[(*fi).se] = true;
            right[i] = right[(*fi).se];
            left[i] = (*fi).fi;
            height[i] = height[(*fi).se] + 1;
        } else {
             if (value <= right[(*fi).se]){
                right[i] = right[(*fi).se];
                left[i] = (*fi).fi;
                height[i] = height[(*fi).se] + 1;
            } else {
                right[i] = (*se).fi;
                left[i] = left[(*se).se];
                height[i] = height[(*se).se] + 1;
            }
        }
        count += height[i] - 1;
        printf("%lld\n", count);
        values.insert(mp(value, i));
    }
}
