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
int spf[1000001];

int main() {
    forn(i, 0, 1000001){
        spf[i] = i;
    }
    int counter = 3;
    for(int j= 1; j < 1000001/2+1; j ++) {
        spf[j*2] = 2;
    }
    for(int i= 3; i < 1000001+1; i += 2){
        if (spf[i] == i){
            for(int j= 1; j < 1000001/i; j +=2) {
                if (i < spf[j*i]) spf[j*i] = i;
            }
        }
    }

    int t;
    cin >> t;
    forn(T, 0, t){
        int n;
        cin >> n;
        int arr[n];
        vector<pair<int, int>> factors[n];
        forn(i, 0, n){
            int temp;
            scanf("%d", &temp);
            while (temp > 1){
                if (factors[i].size() > 0){
                    if (spf[temp] == factors[i][factors[i].size()-1].fi){
                        factors[i][factors[i].size()-1].se++;
                    } else {
                        factors[i].pb(mp(spf[temp], 1));
                    }
                } else {
                    factors[i].pb(mp(spf[temp], 1));
                }
                temp = temp/spf[temp];
            }
        }
        int nums[n];
        forn(i, 0, n){
            nums[i] = 1;
            forn(j, 0, factors[i].size()) if (factors[i][j].se % 2 == 1) nums[i] *= factors[i][j].fi;
        }
        set<pair<int, int>> counter;
        forn(i, 0, n){
            if ((*counter.lower_bound(mp(nums[i], 0))).fi != nums[i]) {
                counter.insert(mp(nums[i], 1));
            } else {
                int temp = (*counter.lower_bound(mp(nums[i], 0))).se;
                counter.erase(counter.lower_bound(mp(nums[i], 0)));
                counter.insert(mp(nums[i], temp+1));
            }
        }
        int high = 0, even = 0, ones = 0;
        for(auto it = counter.begin(); it != counter.end(); ++it){
            if ((*it).se > high) high = (*it).se;
            if ((*it).se % 2 == 0 && (*it).fi != 1) even += (*it).se;
            else if ((*it).fi == 1) ones =  (*it).se;
        }

        int q;
        cin >> q;
        forn(i, 0, q){
            ll temp;
            scanf("%lld", &temp);
            if (temp == 0){
                cout << high << '\n';
            } else {
                cout << max(high, ones + even) << '\n';
            }
        }
    }

}