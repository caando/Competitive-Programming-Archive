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
    int r, c;
    cin >> r >> c;
    int map1[r][c], map2[r][c];
    int dist[r][c];
    int jr = -1, jc= -1, fr = -1, fc = -1;
    vector<pair<int, int>> fires;
    forn(i, 0, r){
        forn(j, 0, c){
            char temp;
            scanf(" %c", &temp);
            dist[i][j] = -2;
            if (temp == '#') {
                map1[i][j] = -2;
                map2[i][j] = -2;
            } else {
                map1[i][j] = -1;
                map2[i][j] = -1;
                if (temp == 'J'){
                    jr = i;
                    jc = j;
                } else if (temp == 'F'){
                    fires.pb(mp(i, j));
                }
            }
        }
    }
    queue<pair<int, pair<int, int>>> bfs;
    bfs.push(mp(0, mp(jr, jc)));
    while (!bfs.empty()){
        int curr = bfs.front().fi;
        int x = bfs.front().se.fi, y = bfs.front().se.se;
        bfs.pop();
        if (map1[x][y] == -1){
            map1[x][y] = curr;
            if (x > 0){
                if (map1[x-1][y] == -1) bfs.push(mp(curr+1, mp(x-1, y)));
            }
            if (x < r-1){
                if (map1[x+1][y] == -1) bfs.push(mp(curr+1, mp(x+1, y)));
            }
            if (y > 0){
                if (map1[x][y-1] == -1) bfs.push(mp(curr+1, mp(x, y-1)));
            }
            if (y < c-1){
                if (map1[x][y+1] == -1) bfs.push(mp(curr+1, mp(x, y+1)));
            }
        }
    }
    
    forn(i, 0, fires.size()) bfs.push(mp(0, mp(fires[i].fi, fires[i].se)));
    while (!bfs.empty()){
        int curr = bfs.front().fi;
        int x = bfs.front().se.fi, y = bfs.front().se.se;
        bfs.pop();
        if (map2[x][y] == -1){
            map2[x][y] = curr;
            if (x > 0){
                if (map2[x-1][y] == -1) bfs.push(mp(curr+1, mp(x-1, y)));
            }
            if (x < r-1){
                if (map2[x+1][y] == -1) bfs.push(mp(curr+1, mp(x+1, y)));
            }
            if (y > 0){
                if (map2[x][y-1] == -1) bfs.push(mp(curr+1, mp(x, y-1)));
            }
            if (y < c-1){
                if (map2[x][y+1] == -1) bfs.push(mp(curr+1, mp(x, y+1)));
            }
        }
    }
    bfs.push(mp(1, mp(jr, jc)));
    while (!bfs.empty()){
        int curr = bfs.front().fi;
        int x = bfs.front().se.fi, y = bfs.front().se.se;
        bfs.pop();
        if (dist[x][y] == -2){
            dist[x][y] = curr;
            if (x > 0){
                if (map1[x-1][y] >= 0){
                    if (map1[x-1][y] < map2[x-1][y] || map2[x-1][y] == -1){
                        if (dist[x-1][y] == -2) bfs.push(mp(curr+1, mp(x-1, y)));
                    }
                }
            }
            if (x < r-1){
                if (map1[x+1][y] >= 0){
                    if (map1[x+1][y] < map2[x+1][y] || map2[x+1][y] == -1){
                        if (dist[x+1][y] == -2) bfs.push(mp(curr+1, mp(x+1, y)));
                    }
                }
            }
            if (y > 0){
                if (map1[x][y-1] >= 0){
                    if (map1[x][y-1] < map2[x][y-1] || map2[x][y-1] == -1){
                        if (dist[x][y-1] == -2) bfs.push(mp(curr+1, mp(x, y-1)));
                    }
                }
            }
            if (y < c-1){
                if (map1[x][y+1] >= 0){
                    if (map1[x][y+1] < map2[x][y+1] || map2[x][y+1] == -1){
                        if (dist[x][y+1] == -2) bfs.push(mp(curr+1, mp(x, y+1)));
                    }
                }
            }
        }
    }
    int low = INT_MAX;

    forn(i, 0, r){
        if (dist[i][0] != -2) low = min(dist[i][0], low);
        if (dist[i][c-1] != -2) low = min(dist[i][c-1], low);
    }
    forn(i, 0, c){
        if (dist[0][i] != -2) low = min(dist[0][i], low);
        if (dist[r-1][i] != -2) low = min(dist[r-1][i], low);
    }
    if (low == INT_MAX) cout << "IMPOSSIBLE";
    else cout << low;
}
