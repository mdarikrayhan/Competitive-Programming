#include <bits/stdc++.h>
using namespace std;

// Check if all characters in the string are the same
bool allsameinastrong(string s) {
    if (s.empty()) return true; // Edge case: empty string
    for (int i = 0; i < s.size() - 1; i++) { // Fix: s.size() - 1 to prevent out-of-bounds access
        if (s[i] != s[i + 1]) {
            return false;
        }
    }
    return true;
}

// Find the index of the minimum element in a vector
int minelementindex(vector<int> v) {
    if (v.empty()) return -1; // Handle empty vector case
    int minIndex = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    a[1] = sqrt(1LL * m[1][2] * m[1][3] / m[2][3]);
    for (int i = 2; i <= n; i++) {
        a[i] = m[1][i] / a[1];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
   
   
   
   
   

   
   
   







   
   
   
   

    return 0;
}
