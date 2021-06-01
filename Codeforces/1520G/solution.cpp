#include<bits/stdc++.h>
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
//using int128 = __int128_t;
ll P = 1000000007;
ll n, m;
ll grid[2010][2010];

ll travel(ll x, ll y){
	if (x < 0 || x >= n) return -1;
	if (y < 0 || y >= m) return -1;
	return grid[x][y];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll w;
	cin >> n >> m >> w;
	forn(i, 0, n){
		forn(j, 0, m) cin >> grid[i][j];
	}
	// BFS ending point
	queue<pair<pair<int, ll>, ll>> q;
	ll dist_to_end[n][m];
	forn(i, 0, n){
		forn(j, 0, m) dist_to_end[i][j] = -1;
	}
	q.push(mp(mp(n-1, m-1), 0));
	while (!q.empty()){
		ll x = q.front().fi.fi, y = q.front().fi.se, d = q.front().se;
		q.pop();
		if (dist_to_end[x][y] < 0) dist_to_end[x][y] = d;
		if (travel(x-1, y) != -1){
			if (dist_to_end[x-1][y] == -1) {
				dist_to_end[x-1][y] = -2;
				q.push(mp(mp(x-1, y), d+w));
			}
		}
		if (travel(x+1, y) != -1){
			if (dist_to_end[x+1][y] == -1) {
				dist_to_end[x+1][y] = -2;
				q.push(mp(mp(x+1, y), d+w));
			}
		}
		if (travel(x, y-1) != -1){
			if (dist_to_end[x][y-1] == -1) {
				dist_to_end[x][y-1] = -2;
				q.push(mp(mp(x, y-1), d+w));
			}
		}
		if (travel(x, y+1) != -1){
			if (dist_to_end[x][y+1] == -1) {
				dist_to_end[x][y+1] = -2;
				q.push(mp(mp(x, y+1), d+w));
			}
		}
	}
	ll dist_from_start[n][m];
	forn(i, 0, n){
		forn(j, 0, m) dist_from_start[i][j] = -1;
	}
	q.push(mp(mp(0, 0), 0));
	while (!q.empty()){
		ll x = q.front().fi.fi, y = q.front().fi.se, d = q.front().se;
		q.pop();
		if (dist_from_start[x][y] < 0) dist_from_start[x][y] = d;
		if (travel(x-1, y) != -1){
			if (dist_from_start[x-1][y] == -1) {
				dist_from_start[x-1][y] = -2;
				q.push(mp(mp(x-1, y), d+w));
			}
		}
		if (travel(x+1, y) != -1){
			if (dist_from_start[x+1][y] == -1) {
				dist_from_start[x+1][y] = -2;
				q.push(mp(mp(x+1, y), d+w));
			}
		}
		if (travel(x, y-1) != -1){
			if (dist_from_start[x][y-1] == -1) {
				dist_from_start[x][y-1] = -2;
				q.push(mp(mp(x, y-1), d+w));
			}
		}
		if (travel(x, y+1) != -1){
			if (dist_from_start[x][y+1] == -1) {
				dist_from_start[x][y+1] = -2;
				q.push(mp(mp(x, y+1), d+w));
			}
		}
	}
	/*
	forn(i, 0, n){
		forn(j, 0, m) cout << dist_from_start[i][j] << ' ';
		cout << '\n';
	}
	forn(i, 0, n){
		forn(j, 0, m) cout << dist_to_end[i][j] << ' ';
		cout << '\n';
	}
	*/
	ll low = -1;
	if (dist_from_start[n-1][m-1] != -1) low = dist_from_start[n-1][m-1];
	ll portal_start = -1, portal_end = -1;
	forn(i, 0, n){
		forn(j, 0, m) {
			if (travel(i, j) > 0){
				if (dist_from_start[i][j] != -1) {
					if (portal_start == -1 || travel(i, j) + dist_from_start[i][j] < portal_start) portal_start = travel(i, j) + dist_from_start[i][j];
				}
			}
		}
	}
	forn(i, 0, n){
		forn(j, 0, m) {
			if (travel(i, j) > 0){
				if (dist_to_end[i][j] != -1) {
					if(portal_end == -1 || travel(i, j) + dist_to_end[i][j] < portal_end) portal_end = travel(i, j) + dist_to_end[i][j];
				}
			}
		}
	}
	//cout << portal_start << ' ' << portal_end << '\n';
	
	if (portal_start != -1 && portal_end != -1 && (low == -1 || portal_start + portal_end < low)) low = portal_start + portal_end;
	cout << low << '\n';
}