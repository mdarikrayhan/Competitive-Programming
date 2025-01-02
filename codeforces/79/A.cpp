#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    bool Ciel = true;
    while (n * 100 + m * 10 >= 220 && (n > 0 || (n == 0 && m >= 22)) && m > 0) {
        if (Ciel) {
            if (n >= 2) {
                n -= 2;
                if (m >= 2) {
                    m -= 2;
                } else {
                    break;
                }
            } else if (n < 2) {
                int sm = n * 100;
                n = 0;
                m -= (220 - sm) / 10;
            }
        } else {
            if (m >= 22) {
                m -= 22;
            } else {
                if (m >= 12) {
                    if (n >= 1) {
                        --n;
                    } else {
                        break;
                    }
                    m -= 12;
                } else {
                    if (m >= 2) {
                        m -= 2;
                    } else {
                        break;
                    }
                    if (n >= 2) {
                        n -= 2;
                    } else {
                        break;
                    }
                }
            }
        }
        Ciel = !Ciel;
    }
    if (Ciel) {
        cout << "Hanako";
    } else {
        cout << "Ciel";
    }
}

int main() {
    auto t = 1ull;
    // cin >> t;
    while (t--) solve();
    return 0;
}