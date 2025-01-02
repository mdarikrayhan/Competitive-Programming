#include<bits/stdc++.h>

#define ll long long
using namespace std;

int a[200010][35], b[200010][35];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 29; j >= 0; j--) {
            int A = 0, B = 0;
            if (y & (1 << j)) {
                if (x < ((y >> j) << j))A++;
                else B++;
            }
            a[i][j] = a[i - 1][j] + A;
            b[i][j] = b[i - 1][j] + B;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int lb, rb;
        cin >> lb >> rb;
        int res = 0;
        for (int i = 29; i >= 0; i--) {
            int num = a[rb][i] - a[lb - 1][i] + (b[rb][i] - b[lb - 1][i] > 0);
            if (num == 1)res |= (1 << i);
            if (num > 1) {
                res |= (2 << i) - 1;
                break;
            }
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}