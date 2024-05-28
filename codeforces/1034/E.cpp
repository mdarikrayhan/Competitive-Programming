#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
using namespace std;
using namespace tr2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int64_t> a(1 << n), b(1 << n);
    for (int msk = 0; msk < (1 << n); msk++) {
        a[msk] = (1LL * (s[msk] - '0')) << (2 * __builtin_popcount(msk));
        b[msk] = (1LL * (t[msk] - '0')) << (2 * __builtin_popcount(msk));
    }
    for (int bit = 0; bit < n; bit++) {
        for (int msk = 0; msk < (1 << n); msk++) {
            if (msk >> bit & 1) {
                a[msk] += a[msk ^ (1 << bit)];
                b[msk] += b[msk ^ (1 << bit)];
            }
        }
    }
    vector<int64_t> ans(1 << n);
    for (int msk = 0; msk < (1 << n); msk++) {
        ans[msk] += a[msk] * b[msk];
    }
    for (int bit = n - 1; bit >= 0; bit--) {
        for (int msk = 0; msk < (1 << n); msk++) {
            if (msk >> bit & 1) {
                ans[msk] -= ans[msk ^ (1 << bit)];
            }
        }
    }
    string ret;
    for (int msk = 0; msk < (1 << n); msk++) {
        ret += (char)((ans[msk] >> ((2 * __builtin_popcount(msk))) & 3) + '0');
    }
    cout << ret;
}