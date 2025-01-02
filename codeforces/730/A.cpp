#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> ans;
    while (*max_element(a, a + n) != *min_element(a, a + n)) {
        string out = "";
        int num = count(a, a + n, *max_element(a, a + n));
        int lim = min(num, 5);
        int mx = *max_element(a, a + n);
        if (num == 6) {
            lim = 4;
        }
        else if (num == 1) {
            int mxind = 0;
            if (a[0] == mx) mxind = 1;
            for (int i = 0; i < n; i++) {
                if (a[i] == mx) continue;
                if (a[i] > a[mxind]) mxind = i;
            }
            for (int i = 0; i < n; i++) {
                if (a[i] == mx) {
                    out += '1';
                    --a[i];
                }
                else if (i == mxind) {
                    out += '1';
                    --a[i];
                    a[i] = max(a[i], 0);
                }
                else
                    out += '0';
            }
            ans.push_back(out);
            continue;

        }
        for (int i = 0; i < n; i++) {
            if (a[i] == mx && lim) {
                --lim, --a[i];
                a[i] = max(a[i], 0);
                out += '1';
            }
            else {
                out += '0';
            }
        }
        ans.push_back(out);
    }
    cout << a[0] << '\n';
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << '\n';
    }
}