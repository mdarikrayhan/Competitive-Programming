// LUOGU_RID: 159214447
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n - i * p; i++) {
        if (__builtin_popcount(n - i * p) <= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}