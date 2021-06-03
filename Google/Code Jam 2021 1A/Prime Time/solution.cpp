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

int main(){
    int t;
    cin >> t;
    ll sieve[499*100];
    sieve[0] = 1;
    sieve[1] = 1;
    sieve[2] = 2;
    vector<ll> prime;
    prime.pb(2);
    forn(i, 3, 499*100){
        sieve[i] = i;
        forn(j, 0, prime.size()){
            if (i % prime[j] == 0){
                sieve[i] = prime[j];
                break;
            }
        }
        if (sieve[i] == i){
            prime.pb(i);
        }
    }
    forn(T, 0, t){
        int m, n=0;
        cin >> m;
        ll primes[m], counter[m];
        ll total = 0, ans = 0;
        forn(i, 0, m){
            cin >> primes[i];
            cin >> counter[i];
            total += primes[i] * counter[i];
            n += counter[i];
        }
        forn(i, 2, n*primes[m-1]){
            ll temp_counter[m];
            forn(j, 0, m) temp_counter[j] = counter[j];
            ll temp = total, curr = i;
            forn(j, 0, m){
                while(sieve[curr] == primes[j] && temp_counter[j] > 0){
                    temp_counter[j]--;
                    temp -= sieve[curr];
                    curr = curr / sieve[curr];
                }
            }
            if (temp == i && curr == 1){
                if (i > ans) ans = i;
            }
        }
        cout << "Case #" << T+1  << ": " << ans << '\n';
    }
}
