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
    int t;
    cin >> t;
    forn(T, 0, t){
        int n, m;
        scanf("%d %d", &n, &m);;
        int ufds[n], height[n];
        bool visited[n], parent[n];
        forn(i, 0, n) {
            ufds[i] = i;
            height[i] = 0;
            parent[i] = false;
        }
        forn(i, 0, m){
            int p, c;
            scanf("%d %d", &p, &c);
            p--;
            c--;
            parent[c] = true;
            int p1 = p;
            int p2 = c;
            while (ufds[p1] != p1) p1 = ufds[p1];
            while (ufds[p2] != p2) p2 = ufds[p2];
            if (height[p1] > height[p2]){
                ufds[p2] = p1;
            } else if (height[p2] > height[p1]) {
                ufds[p1] = p2;
            } else {
                ufds[p2] = p1;
                height[p1]++;
            }
        }
        forn(i, 0, n) visited[i] = false; 
        int count = 0;
        forn(i, 0, n){
            if (parent[i] == false) {
                count++;
                int curr = ufds[i];
                while (ufds[curr] != curr) curr = ufds[curr];
                visited[curr] = true;
            }
        }
        forn(i, 0, n){
            if (ufds[i] == i && visited[i] == false) count++;
        }
        cout << count << '\n';
    }
}
