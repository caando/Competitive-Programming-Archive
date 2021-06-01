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
int P = 998244353;

int main() {
    ll t;
    cin >> t;
    forn(i, 0, t){
        ll n, m;
        cin >> n >> m;
        char table[n][m];
        forn(j, 0, n){
            forn(k, 0, m) cin >> table[j][k];
        }
        int count[n][m];
        forn(j, 0, n){
            forn(k, 0, m) count[j][k] = 0;
        }
        vector<int> answer[6];
        forn(j, 0, n-2){
            forn(k, 0, m-2) {
                if (table[j][k] == '1'){
                    answer[0].pb(j);
                    answer[1].pb(k);
                    table[j][k] = '0';
                    answer[2].pb(j+1);
                    answer[3].pb(k);
                    if (table[j+1][k] == '0') table[j+1][k] = '1';
                    else table[j+1][k] = '0';
                    answer[4].pb(j);
                    answer[5].pb(k+1);
                    if (table[j][k+1] == '0') table[j][k+1] = '1';
                    else table[j][k+1] = '0';
                }
            }
        }
        forn(j, 0, n-2){
            if (table[j][m-1] == '1' && table[j][m-2] == '1'){
                answer[0].pb(j);
                answer[1].pb(m-1);
                table[j][m-1] = '0';
                answer[2].pb(j);
                answer[3].pb(m-2);
                table[j][m-2] = '0';
                answer[4].pb(j+1);
                answer[5].pb(m-1);
                if (table[j+1][m-1] == '0') table[j+1][m-1] = '1';
                else table[j+1][m-1] = '0';
            } else if (table[j][m-1] == '1'){
                answer[0].pb(j);
                answer[1].pb(m-1);
                table[j][m-1] = '0';

                answer[2].pb(j+1);
                answer[3].pb(m-2);
                if (table[j+1][m-2] == '0') table[j+1][m-2] = '1';
                else table[j+1][m-2] = '0';

                answer[4].pb(j+1);
                answer[5].pb(m-1);
                if (table[j+1][m-1] == '0') table[j+1][m-1] = '1';
                else table[j+1][m-1] = '0';
            } else if (table[j][m-2] == '1'){
                answer[0].pb(j);
                answer[1].pb(m-2);
                table[j][m-2] = '0';

                answer[2].pb(j+1);
                answer[3].pb(m-2);
                if (table[j+1][m-2] == '0') table[j+1][m-2] = '1';
                else table[j+1][m-2] = '0';
                answer[4].pb(j+1);
                answer[5].pb(m-1);
                if (table[j+1][m-1] == '0') table[j+1][m-1] = '1';
                else table[j+1][m-1] = '0';
            }
        }
        forn(k, 0, m-2){
            if (table[n-1][k] == '1' && table[n-2][k] == '1'){
                answer[0].pb(n-2);
                answer[1].pb(k);
                table[n-2][k] = '0';
                answer[2].pb(n-1);
                answer[3].pb(k);
                table[n-1][k] = '0';
                answer[4].pb(n-1);
                answer[5].pb(k+1);
                if (table[n-1][k+1] == '0') table[n-1][k+1] = '1';
                else table[n-1][k+1] = '0';
            } else if (table[n-2][k] == '1'){
                answer[0].pb(n-2);
                answer[1].pb(k);
                table[n-2][k] = '0';

                answer[2].pb(n-2);
                answer[3].pb(k+1);
                if (table[n-2][k+1] == '0') table[n-2][k+1] = '1';
                else table[n-2][k+1] = '0';

                answer[4].pb(n-1);
                answer[5].pb(k+1);
                if (table[n-1][k+1] == '0') table[n-1][k+1] = '1';
                else table[n-1][k+1] = '0';
            
            } else if (table[n-1][k] == '1'){
                answer[0].pb(n-1);
                answer[1].pb(k);
                table[n-1][k] = '0';

                answer[2].pb(n-2);
                answer[3].pb(k+1);
                if (table[n-2][k+1] == '0') table[n-2][k+1] = '1';
                else table[n-2][k+1] = '0';

                answer[4].pb(n-1);
                answer[5].pb(k+1);
                if (table[n-1][k+1] == '0') table[n-1][k+1] = '1';
                else table[n-1][k+1] = '0';
            }
        }
        int temp = (table[n-1][m-1] == '1') + (table[n-2][m-1]=='1') + (table[n-1][m-2]=='1') + (table[n-2][m-2]=='1');

            while (temp != 0){
                if (temp == 4){
                    answer[0].pb(n-1);
                    answer[1].pb(m-1);
                    answer[2].pb(n-2);
                    answer[3].pb(m-1);
                    answer[4].pb(n-1);
                    answer[5].pb(m-2);
                    answer[0].pb(n-2);
                    answer[1].pb(m-2);
                    answer[2].pb(n-2);
                    answer[3].pb(m-1);
                    answer[4].pb(n-1);
                    answer[5].pb(m-2);
                    answer[0].pb(n-2);
                    answer[1].pb(m-2);
                    answer[2].pb(n-1);
                    answer[3].pb(m-1);
                    answer[4].pb(n-1);
                    answer[5].pb(m-2);
                    answer[0].pb(n-2);
                    answer[1].pb(m-2);
                    answer[2].pb(n-1);
                    answer[3].pb(m-1);
                    answer[4].pb(n-2);
                    answer[5].pb(m-1);
                    table[n-1][m-1] = '0';
                    table[n-2][m-1] = '0';
                    table[n-1][m-2] = '0';
                    table[n-2][m-2] = '0';
                } else if (temp == 3){
                    int curr = 0;
                    if (table[n-1][m-1] == '1') {
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-1);
                        table[n-1][m-1] = '0';
                        curr += 2;
                    }
                    if (table[n-2][m-1] == '1') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-1);
                        table[n-2][m-1] = '0';
                        curr += 2;
                    }
                    if (table[n-1][m-2] == '1') {
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-2);
                        table[n-1][m-2] = '0';
                        curr += 2;
                    }
                    if (table[n-2][m-2] == '1') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-2);
                        table[n-2][m-2] = '0';
                    }
                } else if (temp == 2){
                    int curr = 0;
                    pair<int, int> two[2];
                    if (table[n-1][m-1] == '0'){
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-1);
                        table[n-1][m-1] = '1';
                        if (curr == 0) {
                            two[0].fi = n-1;
                            two[0].se = m-1;
                        } else {
                            two[1].fi = n-1;
                            two[1].se = m-1;
                        }
                        curr += 2;
                    }
                    if (table[n-2][m-1] == '0') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-1);
                        table[n-2][m-1] = '1';
                        if (curr == 0) {
                            two[0].fi = n-2;
                            two[0].se = m-1;
                        } else {
                            two[1].fi = n-2;
                            two[1].se = m-1;
                        }
                        curr += 2;
                    }
                    if (table[n-1][m-2] == '0') {
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-2);
                        table[n-1][m-2] = '1';
                        if (curr == 0) {
                            two[0].fi = n-1;
                            two[0].se = m-2;
                        } else {
                            two[1].fi = n-1;
                            two[1].se = m-2;
                        }
                        curr += 2;
                    }
                    if (table[n-2][m-2] == '0') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-2);
                        table[n-2][m-2] = '1';
                        if (curr == 0) {
                            two[0].fi = n-2;
                            two[0].se = m-2;
                        } else {
                            two[1].fi = n-2;
                            two[1].se = m-2;
                        }
                        curr += 2;
                    }
                    if (!(two[0].fi == n-1 && two[0].se == m-1) && !(two[1].fi == n-1 && two[1].se == m-1)){
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-1);
                        table[n-1][m-1] = '0';
                    } else if (!(two[0].fi == n-2 && two[0].se == m-1) && !(two[1].fi == n-2 && two[1].se == m-1)){
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-1);
                        table[n-2][m-1] = '0';
                    }else if (!(two[0].fi == n-2 && two[0].se == m-2) && !(two[1].fi == n-2 && two[1].se == m-2)){
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-2);
                        table[n-2][m-2] = '0';
                    } else {
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-2);
                        table[n-1][m-2] = '0';  
                    }

                } else if (temp == 1){
                    int curr = 0;
                    pair<int, int> one;
                    if (table[n-1][m-1] == '1'){
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-1);
                        table[n-1][m-1] = '0';
                        one.fi = n-1;
                        one.se = m-1;
                        curr += 2;
                    }
                    if (table[n-2][m-1] == '1') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-1);
                        table[n-2][m-1] = '0';
                        curr += 2;
                        one.fi = n-2;
                        one.se = m-1;
                    }
                    if (table[n-1][m-2] == '1') {
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-2);
                        table[n-1][m-2] = '0';
                        curr += 2;
                        one.fi = n-1;
                        one.se = m-2;
                    }
                    if (table[n-2][m-2] == '1') {
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-2);
                        table[n-2][m-2] = '0';
                        curr += 2;
                        one.fi = n-2;
                        one.se = m-2;
                    }
                    if (!(one.fi == n-1 && one.se == m-1) && curr != 6){
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-1);
                        table[n-1][m-1] = '1';
                        curr += 2;
                    }
                    if (!(one.fi == n-2 && one.se == m-1) && curr != 6){
                        answer[curr].pb(n-2);
                        answer[curr+1].pb(m-1);
                        table[n-2][m-1] = '1';
                        curr += 2;

                    }
                    if (!(one.fi == n-1 && one.se == m-2) && curr != 6){
                        answer[curr].pb(n-1);
                        answer[curr+1].pb(m-2);
                        table[n-1][m-2] = '1';
                        curr += 2;

                    }
                    if (!(one.fi == n-2 && one.se == m-2) && curr != 6){
                        answer[curr].pb(n-2);
                        answer[curr+2].pb(m-2);
                        table[n-2][m-2] = '1';
                        curr += 2;
                    }

                }
                temp = (table[n-1][m-1] == '1') + (table[n-2][m-1]=='1') + (table[n-1][m-2]=='1') + (table[n-2][m-2]=='1');
            }
        cout << answer[0].size() << '\n';
        forn(j, 0, n){
            forn(k, 0, m) count[j][k] = 0;
        }
        forn(j, 0, answer[0].size()){
            cout << answer[0][j] + 1 << ' ';
            cout << answer[1][j] + 1 << ' ';
            count[answer[0][j]][answer[1][j]]++;

            cout << answer[2][j] + 1 << ' ';
            cout << answer[3][j] + 1 << ' ';
            count[answer[2][j]][answer[3][j]]++;

            cout << answer[4][j] + 1 << ' ';
            cout << answer[5][j] + 1 << '\n';
            count[answer[4][j]][answer[5][j]]++;
        }
    }

}