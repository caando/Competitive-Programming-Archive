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
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 1000000;
 
multiset<int> l, r;
 
int insert(int v){
    if (l.empty()) l.insert(v);
    else if (v < *l.rbegin()) {
        l.insert(v);
    } else {
        r.insert(v);
    }
    if (r.size() > l.size()){
        l.insert(*r.begin());
        r.erase(r.begin());
    }
    if (l.size() > r.size()+1){
        r.insert(*l.rbegin());
        l.erase(l.find(*l.rbegin()));
    }
    return *l.rbegin();
}
 
void remove(int v){
    if (r.find(v) != r.end()){
        if (*r.find(v) == v){
            r.erase(r.find(v));
            if (l.size() > r.size()+1){
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }
            return ;
        }
    }
    if (l.find(v) != l.end()){
        if (*l.find(v) == v){
            l.erase(l.find(v));
            if (r.size() > l.size()){
                l.insert(*r.begin());
                r.erase(r.begin());
            }
            return;
        }
    }
}
 
void solve(){
    ll n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, 0, k-1){
        cin >> arr[i];
        insert(arr[i]);
    }
    forn(i, k-1, n){
        if (i >= k) remove(arr[i-k]);
        cin >> arr[i];
        cout << insert(arr[i]) << ' ';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    solve();
}