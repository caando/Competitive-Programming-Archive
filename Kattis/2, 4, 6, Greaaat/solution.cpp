#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    int S[N], D[N];
    for (int i = 0; i < N; i++){
        cin >> S[i] >> D[i];
    }
    int table[T * 2 + 1];
    int parent[T * 2 + 1];
    for (int i = 0; i < T * 2 + 1; i++){
        table[i] = i;
        parent[i] = -1;
    }
    for (int i = 0; i < T * 2 + 1; i++ ){
        for (int j = 0; j < N; j++){
            if (i + S[j] > 0 && i + S[j] < 2 * T + 1){
                if (table[i + S[j]] > table[i] + D[j]) {
                    table[i + S[j]] = table[i] + D[j];
                    parent[i + S[j]] = j;
                }
            }
        }
    }
    for (int i = T * 2; i >= 0; i-- ){
        for (int j = 0; j < N; j++){
            if (i + S[j] > 0 && i + S[j] < 2 * T + 1){
                if (table[i + S[j]] > table[i] + D[j]) {
                    table[i + S[j]] = table[i] + D[j];
                    parent[i + S[j]] = j;
                }
            }
        }
    }
    int sum = 0, num = 0, curr = T;
    vector<int> tracker;
    while (parent[curr] != -1){
        tracker.push_back(parent[curr] + 2);
        num++;
        sum += D[parent[curr]];
        curr = curr - S[parent[curr]];
    }

    cout << num + table[T] - sum << '\n';
    for (int i = 0; i < table[T] - sum; i++){
        cout << 1 << ' ';
    }
    
    for (int i = 0; i < tracker.size(); i++){
        cout << tracker[i] << ' ';
    }
    
}