#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if(n < m) {
        swap(n, m);
    }

    if((m == 1 || n == 1) && m != n) {
        cout << n << '\n';
    } else if(n == m && n == 1){
        cout << 0 << '\n';
    } else {
        cout << n + (m - 1) * 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}