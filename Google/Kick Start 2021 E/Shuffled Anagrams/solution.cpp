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
const int MAXN = 200000;


void solve(int t){
    cout << "Case #" << t+1 << ": ";
    string s;
    cin >> s;
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    forn(i, 0, s.size()) cnt[s[i]-'a']++;
    bool poss = true;
    int cnt2[26];
    forn(i, 0, 26) {
        cnt2[i] = cnt[i];
        if (cnt[i] > s.size()/2) poss = false;
    }
    if (poss){
        string res = "";
        forn(i, 0, s.size()){
            int index = -1;
            forn(j, 0, 26){
                if (index == -1 && s[i]-'a' != j && cnt[j] > 0) index = j;
                else if (min(cnt[j], cnt2[j]) > min(cnt[index], cnt2[index]) && (s[i]-'a') != j && cnt[j] > 0) index = j;
            }
            res += 'a' + index;
            cnt[index]--;
            cnt2[s[i] - 'a']--;
        }
        cout << res << endl;
    } else cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    forn(i,0, t) solve(i);
}