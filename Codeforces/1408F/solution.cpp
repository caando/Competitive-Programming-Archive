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
#define forn(i,n)  for (int i = 0, nnnn = (n); i < nnnn; ++i)
#define pb  push_back
#define mp  make_pair

vector<pair<int, int>> steps;

void get_steps(int curr, int increment){
    if (curr != 0){
        get_steps(curr-1, increment);
        get_steps(curr-1, increment + pow(2, curr));
    }
    forn (i, pow(2, curr)) steps.pb(mp(increment + i, increment + pow(2, curr) + i));
}

int main() {
    ll n;
    cin >> n;
    if (n <= 2) cout << 0;
    else {
        int largest = 0;
        while (pow(2, largest) <= n) largest++;
        largest--;
        get_steps(largest - 1, 0);
        get_steps(largest - 1, n - pow(2, largest));
        cout << steps.size() << '\n';
        forn(i, steps.size()) cout << steps[i].first + 1 << ' ' << steps[i].second + 1<< '\n';
    }
}