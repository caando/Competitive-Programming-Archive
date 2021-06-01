#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k=0;k<t;k++){
        long long n;
        cin >> n;
        long long total = 0;
        int arr[n];
        for (long long j=0;j<n;j++){
            cin >> arr[j];
            total += arr[j];
        }
        if (total % n != 0) cout << -1 << "\n";
        else {
            vector<vector<int>> steps;
            for (int i=1;i<n;i++){
                if (arr[i] % (i+1) > 0){
                    int change = (i+1) - arr[i] % (i+1);
                    arr[0] -= change;
                    arr[i] += change;
                    vector <int> step;
                    step.push_back(1);
                    step.push_back(i+1);
                    step.push_back(change);
                    steps.push_back(step);
                }
                if (arr[i] > 0){
                    int change = arr[i];
                    arr[0] += change;
                    arr[i] -= change;
                    vector <int> step;
                    step.push_back(i+1);
                    step.push_back(1);
                    step.push_back(change/(i+1));
                    steps.push_back(step);
                }
            }
            for (int i=1;i<n;i++){
                vector <int> step;
                step.push_back(1);
                step.push_back(i+1);
                step.push_back(total/n);
                steps.push_back(step);
            }
            cout << steps.size() << '\n';
            for (int i=0;i<steps.size();i++){
                cout << steps[i][0] << ' ' << steps[i][1] << ' ' << steps[i][2] << "\n";
            }
        }
    }
}