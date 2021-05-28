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
int P = 1000000007;

vector<int> child[1000];
vector<int> parent[1000];
int children[1000];
int m = P;
bool poss = true;
int paths[1000];
int n;


int find_path(int curr){
    if (paths[curr] != -2) return paths[curr];
    ll count = 0;
    bool include = false;
    forn(i, 0, child[curr].size()){
        if (find_path(child[curr][i]) >= 0){
            count += find_path(child[curr][i]);
            include = true;
        }
    }
    if (include) {
        count = (count + 1) % m;
        paths[curr] = count;
        return count;
    } else {
        paths[curr] = -1;
        return -1;
    }
}

int get_children(int curr, int counter){
    if (counter > 1000) {
        poss = false;
        return 0;
    }
    if (children[curr] != -1) return children[curr];
    ll count = 1;
    forn (i, 0, child[curr].size()){
        count += get_children(child[curr][i], counter + 1);
    }
    count = count % m;
    children[curr] = count;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d %d", &n, &m) == 1;
    forn(i, 0, n){
        int C;
        scanf("%d", &C) == 1;
        forn(j, 0, C){
            int temp;
            scanf("%d", &temp) == 1;
            child[i].pb(temp);
            parent[temp].pb(i);
        }
    }
    forn(i, 0, n) {
        children[i] = -1;
    }
    get_children(0, 0);
    int q, t;
    scanf("%d %d", &q, &t) == 1;
    if (t == 0){
        if (poss){
            printf("%d\n", children[0] % m);
            forn (i, 0, q){
                int N;
                scanf("%d", &N) == 1;
                forn(j, 0, n) paths[j] = -2;
                forn(j, 0, N) {
                    int node;
                    scanf("%d", &node) == 1;
                    paths[node] = children[node];
                }
                printf("%d\n", max(find_path(0) % m, 0));
            }
        } else {
            printf("Invalid\n");
        }
    } else {
        if (poss) printf("Valid\n");
        else printf("Invalid\n");
    }
}