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
    scanf("%d", &n);
    int arr[n];
    deque<int> A, B, C;
    int last = 0;
    forn(i, 0, n){
        cin >> arr[i];
        if (arr[i] == 1) {
            A.pb(i);
            last = arr[i];
        }
        else if (arr[i] == 2) {
            B.pb(i);
            last = arr[i];
        }
        else if (arr[i] == 3) {
            C.pb(i);
            last = arr[i];
        }
    }
    vector<pair<int, int>> res;
    if (B.size() > A.size() || last > 1) cout << -1 << '\n';
    else {
        int level = 1;
        bool poss = true;
        forn(i, 0, n){
            if (arr[i] == 3){
                C.pop_front();
                res.pb(mp(i+1, level));
                if (C.empty() == false){
                    res.pb(mp(C.front()+1, level));
                }else if (B.empty() == false){
                    res.pb(mp(B.front()+1, level));
                } else if (A.empty() == false){
                    res.pb(mp(A.front()+1, level));
                } else {
                    poss = false;
                }
            } else if(arr[i] == 2){
                B.pop_front();
                res.pb(mp(i+1, level));
                res.pb(mp(A.front()+1, level));
                A.pop_front();
            } else if (arr[i] == 1){
                if (A.front() == i){
                    A.pop_front();
                    res.pb(mp(i+1, level));
                }
                if (B.size() > A.size()) {
                    poss = false;
                    break;
                }
            }
            level++;
        }
        if (poss){
            cout << res.size() << '\n';
            forn(i, 0, res.size()) cout << res[i].se << ' ' << res[i].fi << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}