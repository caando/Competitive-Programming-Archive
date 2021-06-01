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

int closest[1010][1010];
char board[1010][1010];
bool visited[1010][1010];
int n, m, t;

int inf = 1000 * 1000;

void bfs1(int init){
  deque<pii> q;
  q.pb(mp(1, 1));
  int i = 0;
  while (i < q.size()){
    if (visited[q[i].fi + 1][q[i].se] == false) {
      visited[q[i].fi + 1][q[i].se] = true;
      q.pb(mp(q[i].fi + 1, q[i].se));
    }
    if (visited[q[i].fi][q[i].se + 1] == false) {
      visited[q[i].fi][q[i].se + 1] = true;
      q.pb(mp(q[i].fi, q[i].se + 1));
    }
    i++;
  }
  for (int i= q.size()-1; i >= 0; i--){
    if (board[q[i].fi + 1][q[i].se] == board[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = 0;
    if (board[q[i].fi][q[i].se + 1] == board[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = 0;
    if (closest[q[i].fi + 1][q[i].se] + 1 < closest[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = closest[q[i].fi + 1][q[i].se] + 1;
    if (closest[q[i].fi][q[i].se + 1] + 1 < closest[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = closest[q[i].fi][q[i].se + 1] + 1;
  }
}

void bfs2(int init){
  deque<pii> q;
  q.pb(mp(n, m));
  int i = 0;
  while (i < q.size()){
    if (visited[q[i].fi - 1][q[i].se] == false) {
      visited[q[i].fi - 1][q[i].se] = true;
      q.pb(mp(q[i].fi - 1, q[i].se));
    }
    if (visited[q[i].fi][q[i].se - 1] == false) {
      visited[q[i].fi][q[i].se - 1] = true;
      q.pb(mp(q[i].fi, q[i].se - 1));
    }
    i++;
  }
  for (int i= q.size()-1; i >= 0; i--){
    if (board[q[i].fi - 1][q[i].se] == board[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = 0;
    if (board[q[i].fi][q[i].se - 1] == board[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = 0;
    if (closest[q[i].fi - 1][q[i].se] + 1 < closest[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = closest[q[i].fi - 1][q[i].se] + 1;
    if (closest[q[i].fi][q[i].se - 1] + 1 < closest[q[i].fi][q[i].se]) closest[q[i].fi][q[i].se] = closest[q[i].fi][q[i].se - 1] + 1;
  }
}

int main() {
  cin >> n >> m >> t;
  forn(i, 0, 1010) forn(j, 0, 1010) board[i][j] = '2';
  forn(i, 1, n + 1) forn(j, 1, m + 1) cin >> board[i][j];
  forn(i, 0, 1010) forn(j, 0, 1010) closest[i][j] = inf;
  forn(i, 0, 1010) forn(j, 0, 1010) visited[i][j] = true;
  forn(i, 1, n + 1) forn(j, 1, m + 1) visited[i][j] = false;
  bfs1('0');
  forn(i, 1, n + 1) forn(j, 1, m + 1) visited[i][j] = false;
  bfs1('1');
  forn(i, 1, n + 1) forn(j, 1, m + 1) visited[i][j] = false;
  bfs2('0');
  forn(i, 1, n + 1) forn(j, 1, m + 1) visited[i][j] = false;
  bfs2('1');

  forn(i, 0, t){
    ll x, y, p;
    cin >> x >> y >> p;
    if (closest[x][y] == 1000000) cout << board[x][y] << '\n';
    else if (closest[x][y] > p) cout << board[x][y] << '\n';
    else if ((p - closest[x][y]) % 2 == 0) cout << board[x][y] << '\n';
    else if ((p - closest[x][y]) % 2 == 1 && board[x][y] == '1') cout << '0' << '\n';
    else if ((p - closest[x][y]) % 2 == 1 && board[x][y] == '0') cout << '1' << '\n';
  }


}