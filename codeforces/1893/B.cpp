#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);
    int p = m - 1;
    for (int i = 0; i < n; i++) {
        while (p >= 0 && b[p] >= a[i]) {
            cout << b[p--] << " ";
        }
        cout << a[i] << " ";
    }
    while (p >= 0) {
        cout << b[p--] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}