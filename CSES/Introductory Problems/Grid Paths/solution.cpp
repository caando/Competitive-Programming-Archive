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
bool visited[7][7];
vector<string> paths;
string curr_string = "????????????????????????????????????????????????";

bool visit(int x, int y){
	if (x > 6 || x < 0) return true;
	if (y > 6 || y < 0) return true;
	return visited[x][y];
}
 
void dfs(int x, int y, int curr){
	if (curr == 48 && x == 6 && y == 0) paths.pb(curr_string);
	else if (x == 6 && y == 0) return;
	else if (curr >= 48) return;
	else {
		visited[x][y] = true;
		if (!visit(x-1, y)) {
			if (visit(x-2, y) || visit(x-2, y+1) || visit(x-2, y-1)){
				if (!(!visit(x-1, y+1) && !visit(x-1, y-1))) {
					curr_string[curr] = 'U';
					dfs(x-1, y, curr + 1);
				}
			} else {
				curr_string[curr] = 'U';
				dfs(x-1, y, curr + 1);
			}
		}
		if (!visit(x+1, y)) {
			if (visit(x+2, y) || visit(x+2, y+1) || visit(x+2, y-1)){
				if (!(!visit(x+1, y+1) && !visit(x+1, y-1))) {
					curr_string[curr] = 'D';
					dfs(x+1, y, curr + 1);
				}
			} else {
				curr_string[curr] = 'D';
				dfs(x+1, y, curr + 1);
				}
		}
		if (!visit(x, y-1)) {
			if (visit(x, y-2) || visit(x+1, y-2) || visit(x-1, y-2)){
				if (!(!visit(x+1, y-1) && !visit(x-1, y-1))) {
					curr_string[curr] = 'L';
					dfs(x, y-1, curr + 1);
				}
			} else {
				curr_string[curr] = 'L';
				dfs(x, y-1, curr + 1);
			}
		}
		if (!visit(x, y+1)) {
			if (visit(x, y+2) || visit(x+1, y+2) || visit(x-1, y+2)){
				if (!(!visit(x-1, y+1) && !visit(x+1, y+1))) {
					curr_string[curr] = 'R';
					dfs(x, y+1, curr + 1);
				}
			} else {
				curr_string[curr] = 'R';
				dfs(x, y+1, curr + 1);
			}
		}
		visited[x][y] = false;
	}
}
 
int main(){
	forn(i, 0, 7){
		forn(j, 0, 7) visited[i][j] = false;
	}
	dfs(0, 0, 0);
	string s;
	cin >> s;
	bool poss[paths.size()];
	forn(i, 0, paths.size()){
		poss[i] = true;
	}
	forn(i, 0, s.size()){
		forn(j, 0, paths.size()){
			if (s[i] != paths[j][i] && s[i] != '?') poss[j] = false;
		}
	}
	int count = 0;
	forn(i, 0, paths.size()){
		if (poss[i]) count++;
	}
	cout << count;
}