#include<bits/stdc++.h>
using namespace std;


vector<bool> v;
vector<vector<int>> adj;
vector<bool> s;

void dfs(int c, int origin){
    v[c] = true;
    for(int i : adj[c]){
        if (!v[i]) dfs(i, origin);
        else if (s[i] && i != origin) {
            s[i] = false;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    v = vector<bool>(n, false);
    s = vector<bool>(n, true);
    adj = vector<vector<int>>(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        s[b-1] = false;
    }
    for(int i = 0;i < n; i++){
        if (s[i]) {
            dfs(i, i);
        }
    }
    for(int i = 0;i < n; i++){
        if (!v[i]) {
            s[i] = true;
            dfs(i, i);
        }
    }
    int ans=0;
    for(int i = 0;i < n; i++) ans+=s[i];
    cout << ans<< '\n';

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12) << fixed;
    int t;
    cin >> t;
    while(t--) solve();
}