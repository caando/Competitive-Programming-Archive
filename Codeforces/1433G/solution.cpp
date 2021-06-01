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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adjlist[n];
    int shortest_path[n][n];
    pair<int, int> edges[m];
    forn(i, 0, n){
        forn(j, 0, n) {
            if (i == j) {
                shortest_path[i][j] = 0;
            } else {
                shortest_path[i][j] = INT32_MAX;
            }
        }
    }
    forn(i, 0, m){
        int fi, se, cost;
        cin >> edges[i].fi >> edges[i].se >> cost;
        adjlist[edges[i].fi-1].pb(mp(edges[i].se-1, cost));
        adjlist[edges[i].se-1].pb(mp(edges[i].fi-1, cost));
    }
    forn(i, 0, n){
        set<int> visited;
        visited.insert(i);
        set<pair<int, int>> paths;
        forn(j, 0, adjlist[i].size()){
            paths.insert(mp(adjlist[i][j].se, adjlist[i][j].fi));
        }
        while (visited.size() < n){
            if (paths.size() == 0) break;
            int node = (*paths.begin()).se;
            if ( visited.find(node) == visited.end()){
                int cost = (*paths.begin()).fi;
                visited.insert(node);
                shortest_path[i][node] = cost;
                forn(j, 0, adjlist[node].size()){
                    if ( visited.find(adjlist[node][j].fi) == visited.end()){
                        paths.insert(mp(shortest_path[i][node] + adjlist[node][j].se, adjlist[node][j].fi));
                    }
                }
            }
            paths.erase(paths.begin());
        }
    }
    int total = INT32_MAX;
    pair<int, int> queries[k];
    forn(i, 0, k) cin >> queries[i].fi >> queries[i].se;

    forn(i, 0, m){
        int cost = 0;
        forn(j, 0, k) {
            int temp = shortest_path[queries[j].fi-1][queries[j].se-1];
            if (shortest_path[queries[j].fi-1][edges[i].fi-1] + shortest_path[edges[i].se-1][queries[j].se-1] < temp) temp = shortest_path[queries[j].fi-1][edges[i].fi-1] + shortest_path[edges[i].se-1][queries[j].se-1];
            if (shortest_path[queries[j].fi-1][edges[i].se-1] + shortest_path[edges[i].fi-1][queries[j].se-1] < temp) temp = shortest_path[queries[j].fi-1][edges[i].se-1] + shortest_path[edges[i].fi-1][queries[j].se-1];
            cost += temp;
        }
        if (cost < total) total = cost;
    }
    cout << total;
}