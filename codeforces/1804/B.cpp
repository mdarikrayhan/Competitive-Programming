#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int left = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (left == 0 || (prev != -1 && a[i] - prev > d + w)) {
                ans++;
                left = k;
                prev = a[i];
            }
            left--;
        }
        cout << ans << endl;
    }
    return 0;
}