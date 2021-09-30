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
#define NIL 0
#define INF INT_MAX
#define int128 __int128_t

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

int n, m, a[200005], b[200005], start[200005], small[450][450], large[200005], t, k, A, B, cnt=0, j, i, C;
long long curr;

void solve(){
    cin >> n >> m;
    for(i = 0; i < n; i++) cin >> a[i] >> b[i];
    memset(small, 0, sizeof small);
    memset(large, 0, sizeof large);
    for(i = 0; i < m; i++){ 
        cin >> t >> k;
        k--;
        for(j =2; j< 450; j++) cnt += small[j][i%j];
        cnt += large[i];
        A = a[k], B = b[k], C = A + B;
        if (t == 1){
            start[k] = i;
            if (C < 450){
                small[C][(i+A)%C]++;
                small[C][i%C]--;
            } else {
                curr = i;
                while(curr < m){
                    if (curr+A < m) large[curr+A]++;
                    if (curr+C< m) large[curr+C]--;
                    curr += C;
                }
            }
        } else {
            curr = start[k];
            if ((i-curr) % C >= A) cnt--;
            if (C < 450){
                small[C][(curr+A)%C]--;
                small[C][curr%C]++;
            } else {
                while(curr < m){
                    if (curr+A < m) large[curr+A]--;
                    if (curr+C< m) large[curr+C]++;
                    curr += C;
                }
            }
        }
        cout << cnt << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}