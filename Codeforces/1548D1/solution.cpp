#include <bits/stdc++.h>
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
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 2000;

void solve(){
    int n;
    cin >> n;
    ll a=0,b=0,c=0,d=0, ans = 0;
    forn(i, 0, n) {
        int x, y;
        cin >> x >> y;
        x/=2, y/=2;
        if ((x&1) && (y&1)) a++;
        else if (!(x&1) && (y&1)) b++;
        else if ((x&1) && !(y&1)) c++;
        else if (!(x&1) && !(y&1)) d++;
    }
    ans += max(0ll, a*(a-1)*(n-a))/2;
    ans += max(0ll, b*(b-1)*(n-b))/2;
    ans += max(0ll, c*(c-1)*(n-c))/2;
    ans += max(0ll, d*(d-1)*(n-d))/2;
    ans += max(0ll, a*(a-1)*(a-2))/6;
    ans += max(0ll, b*(b-1)*(b-2))/6;
    ans += max(0ll, c*(c-1)*(c-2))/6;
    ans += max(0ll, d*(d-1)*(d-2))/6;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}