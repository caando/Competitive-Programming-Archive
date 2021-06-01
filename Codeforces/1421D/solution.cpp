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
    cin >> n;
    forn(i, 0, n){
        int xf, yf;
        cin >> xf >> yf;
        ll cost[6];
        cin >> cost[0] >> cost[1] >> cost[2] >> cost[3] >> cost[4] >> cost[5];
        forn (k, 0, 6){
            forn (j, 1, 6){
                if (cost[j] > cost [j-1] + cost[(j+1) % 6]) cost[j] = cost [j-1] + cost[(j+1) % 6];
            }
            if (cost[0] > cost[1] + cost[5]) cost[0] = cost[1] + cost[5];
        }

        int x = 0, y = 0; 
        ll count = 0;
        if (xf > x && yf > y) {
            int temp = min(xf - x, yf - y);
            x += temp;
            y += temp;
            count += cost[0] * temp;
        } 
        if (xf < x && yf < y) {
            int temp = min(x - xf, y - yf);
            x-= temp;
            y-= temp;
            count += cost[3] * temp;
        } 
        if (xf > x){
            count+= cost[5] * (xf - x);
        } 
        if (xf < x){
            count+= cost[2] * (x - xf);
        } 
        if (yf > y){
            count+= cost[1] * (yf - y);
        } 
        if (yf < y){
            count+= cost[4] * (y - yf);
        }
        cout << count << '\n';
    }
}