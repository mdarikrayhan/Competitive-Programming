#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int rem = n % 3;
        if (rem == 0)
            cout << n / 3 << " " << n / 3 << "\n";
        else if (rem == 1)
            cout << n / 3 + 1 << " " << n / 3 << "\n";
        else
            cout << n / 3 << " " << n / 3 + 1 << "\n";
    }
    return 0;
}