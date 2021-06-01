#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int n;
    cin >> n;
    long long a[n];
    long long b[n], c[n];
    long long change[n];
    long long zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
        c[i] = 0;
    }
    long long diff = a[0];
    change[0] = a[0];
    for (int i = 1; i < n; i++) change[i] = a[i] - a[i-1];
    b[0] = a[0];
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            diff += a[i] - a[i-1];
            b[i] = a[i] - a[i-1] + b[i-1];
            c[i] = c[i-1];
        } else if (a[i] < a[i-1]) {
            c[i] = a[i] - a[i-1] + c[i-1];
            b[i] = b[i-1];
        } else {
            b[i] = b[i-1];
            c[i] = c[i-1];
        }
    }
    if (b[n-1] >= 0) cout << b[n-1] / 2 + b[n-1] % 2 << '\n';
    else cout << b[n-1] / 2 << '\n';
    int q;
    cin >> q;
    for (int t = 0; t < q; t++){
        long long l, r, x;
        cin >> l >> r >> x;
        long long initial_diff = diff;
        if (l == 1){
            diff += x;
            change[0] += x;
        } else {
            long long temp = change[l-1];
            change[l-1] += x;
            diff += max(zero, change[l-1]) - max(temp, zero);
        }
        if (r < n) {
            long long temp = change[r];
            change[r] -= x;
            diff += max(zero , change[r]) - max(temp, zero);
        }
        b[n-1 ] += diff - initial_diff;
        if (b[n-1 ] >= 0) cout << b[n-1 ] / 2 + b[n-1 ] % 2 << '\n';
        else cout << b[n-1 ] / 2 << '\n';
    }
}