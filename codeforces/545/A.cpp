#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
int main() {
    int n;
    cin >> n;
    vector<vector<int>>cars(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cars[i][j];
        }
    }
    vector<int>v;
    for (int i = 0; i < n; i++) {
        bool ans = true;
        for (int j = 0; j < n; j++) {
            if (i != j && (cars[i][j] == 1 || cars[i][j] == 3)) {
                ans = false;
                break;
            }
        }
        if (ans) {
            v.push_back(i + 1);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

