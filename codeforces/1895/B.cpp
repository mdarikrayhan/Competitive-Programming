#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n * 2);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> b(a.begin() + n, a.end());
        vector<int> c(a.begin(), a.begin() + n);
        int k = 0;
        if (n & 1) {
            reverse(c.begin(), c.end());
        }
        for (int i = 0; i < n - 1; i++) {
            k += abs(c[i] - c[i + 1]);
            k += abs(b[i] - b[i + 1]);
        }
        cout << k << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i] << " " << c[i] << endl;
        }
    }
    return 0;
}
