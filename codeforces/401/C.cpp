#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m + 1 < n || m > 2 * (n + 1)) {
        cout << -1;
    } else {
        if (m + 1 == n) {
            cout << 0;
            for (int i = 0; i < m; i++) {
                cout << 10;
            }
        } else {
            int x = (m - n);
            for (int i = 0; i < min(x,n); i++) {
                cout << 110;
            }
            if (x == n + 1 || x == n + 2) {
                for (int i = 0; i < x - n; i++) {
                    cout << 1;
                }
            } else {
                for (int i = 0; i < n - x; i++) {
                    cout << 10;
                }
            }
        }
    }
    return 0;
}
