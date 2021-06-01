#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        for (int i=0;i<n;i++) cin >> arr[i];

        int leftCummulative[3010];
        for (int i=0; i < 3010; i++) leftCummulative[i] = 0;
        leftCummulative[arr[0]]++;
        int rightCummulative[3010];
        long long result = 0;
        for (int i=1; i<n-2; i++){
            for (int j=0; j < 3010; j++) rightCummulative[j] = 0;
            rightCummulative[arr[n-1]]++;
            for (int j = n-2; j>i; j--){
                result += leftCummulative[arr[j]] * rightCummulative[arr[i]];
                rightCummulative[arr[j]]++;
            }
            leftCummulative[arr[i]]++;
        }
        cout << result << '\n';
    }
}