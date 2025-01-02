#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

using Long = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lim = 0;
    for (int i = a.size() - 1; i >= 1; i--) {
        if (a[i] != a[i - 1]) {
            lim = i;
            break;
        }
    }
    if (lim > k - 1) {
        cout << -1;
    } else {
        cout << lim;
    }

    return 0;
}