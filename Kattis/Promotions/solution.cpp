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
vector<int> child[5000], parent[5000];
bool counter[5000];

void getChild(int curr){
    if (counter[curr] == true) return;
    counter[curr] = true;
    forn(i, 0, child[curr].size()){
        getChild(child[curr][i]);
    }
}

void getParent(int curr){
    if (counter[curr] == true) return;
    counter[curr] = true;
    forn(i, 0, parent[curr].size()){
        getParent(parent[curr][i]);
    }
}
int main() {
    int a, b, e, p;
    cin >> a >> b >> e >> p;
    int res1[e], res2[e];
    forn(i, 0, e) {
        res1[i] = 0;
        res2[i] = 0;
    }
    forn(i, 0, p){
        int fi, se;
        cin >> fi >> se;
        child[fi].pb(se);
        parent[se].pb(fi);
    }
    forn(i, 0, e){
        getChild(i);
        forn(j, 0, e) {
            if (counter[j] == true) {
                res1[i]++;
                counter[j] = false;
            }
        }
        getParent(i);
        forn(j, 0, e) {
            if (counter[j] == true) {
                res2[i]++;
                counter[j] = false;
            }
        }
    }
    int A = 0, B = 0, C =0;
    forn(i, 0, e) {
        if (e - res1[i] < a) A++;
        if (e - res1[i] < b) B++;
        if (res2[i] - 1 >= b) C++;
    }
    cout << '\n';
    cout << A << '\n' << B << '\n' << C;

}