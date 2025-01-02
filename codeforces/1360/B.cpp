#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        int min_diff = 1e9;
        for (int i = 1; i < n; i++)
            min_diff = min(min_diff, abs(A[i] - A[i - 1]));
        cout << min_diff << "\n";
    }
    return 0;
}