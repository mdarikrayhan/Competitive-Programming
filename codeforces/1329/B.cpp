#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int d, m;
        cin >> d >> m;
        ll ans = 2;
        for (int i = 1; i < 32; i++) {
            if (!(d >> i)) break;
            int bruh = (1 << i);
            if ((d >> i) == 1) {
                bruh = d - (1 << i) + 1;
            }
            ans *= bruh + 1;
            ans %= m;
        }
        cout << (ans - 1 + m) % m << "\n";
    }
}