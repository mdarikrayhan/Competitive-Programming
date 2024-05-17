#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string a[m];
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << a[j][i] << a[j][i];
        cout << '\n';
        for (int j = 0; j < m; ++j) cout << a[j][i] << a[j][i];
        cout << '\n';
    }
    return 0;
}