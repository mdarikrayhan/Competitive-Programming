#include <bits/stdc++.h>

#define int int64_t
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << (n - n / 10 * 10 > n / 10 * 10 + 10 - n ? n / 10 * 10 + 10 : n / 10 * 10);

    return 0;
}
