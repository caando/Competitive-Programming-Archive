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

string n;
ll m;

ll s(ll pos, ll curr, ll pres, ll count){
    if (pos == n.size()) return curr;
    if (pres & (1 << (n[pos] - '0'))){
        ll test = INT_MAX;
        if (count < m){
            ll res;
            if ((1 << (n[pos] - '0')) & pres) res = s(pos+1, curr * 10 + (n[pos] - '0'), pres, count);
            else res = s(pos+1, curr * 10 + (n[pos] - '0'), pres | (1 << (n[pos] - '0')), count+1);
            forn(i, (n[pos]-'0') + 1, 10){
                ll temp = curr;
                temp *= 10;
                temp += i;
                ll low = i;
                ll add;
                if ((1 << (i)) & pres) add = 0;
                else add = 1;
                if (count + add < m) low = 0;
                else {
                    int temp = pres, counter = 0;
                    while(!(temp & 1) && counter < low) counter++, temp >>= 1;
                    low = min(i, counter);
                }
                forn(i, pos+1, n.size()) temp *= 10, temp += low;
                if (temp < res) res = temp;
            }
            test= res;
        } else {
            ll next = (n[pos]-'0') + 1;
            while (!(pres & (1 << (next))) && next < 10) next++;
            if (next < 10) {
                ll curr1 = curr;
                curr1 *= 10;
                curr1 += next;
                ll low;
                ll temp = pres, counter = 0;
                while(!(temp & 1)) counter++, temp >>= 1;
                low = min(next, counter);
                forn(i, pos+1, n.size()) curr1 *= 10, curr1 += low;
                test = curr1;
            } else test= INT_MAX;
        }
        return min(test, s(pos + 1, curr*10 + (n[pos] - '0'), pres, count));
    } else {
        if (count < m){
            ll res;
            if ((1 << (n[pos] - '0')) & pres) res = s(pos+1, curr * 10 + (n[pos] - '0'), pres, count);
            else res = s(pos+1, curr * 10 + (n[pos] - '0'), pres | (1 << (n[pos] - '0')), count+1);
            forn(i, (n[pos]-'0') + 1, 10){
                ll temp = curr;
                temp *= 10;
                temp += i;
                ll low = i;
                ll add;
                if ((1 << (i)) & pres) add = 0;
                else add = 1;
                if (count + add < m) low = 0;
                else {
                    int temp = pres, counter = 0;
                    while(!(temp & 1) && counter < low) counter++, temp >>= 1;
                    low = min(i, counter);
                }
                forn(i, pos+1, n.size()) temp *= 10, temp += low;
                if (temp < res) res = temp;
            }
            return res;
        } else {
            ll next = (n[pos]-'0') + 1;
            while (!(pres & (1 << (next))) && next < 10) next++;
            if (next < 10) {
                curr *= 10;
                curr += next;
                ll low;
                ll temp = pres, counter = 0;
                while(!(temp & 1)) counter++, temp >>= 1;
                low = min(next, counter);
                forn(i, pos+1, n.size()) curr *= 10, curr += low;
                return curr;
            } else return INT_MAX;
        }
    }
}


void solve(){
	cin >> n >> m;
    cout << s(0, 0, 0, 0) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}