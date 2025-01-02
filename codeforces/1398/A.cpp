#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b;
    int i = n - 2;
    while (i--)
        cin >> c;

    if (a + b <= c) cout << "1 2 " << n << endl;
    else cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}