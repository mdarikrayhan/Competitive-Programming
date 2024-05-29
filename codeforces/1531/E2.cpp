#include <bits/stdc++.h>
#define int long long
using namespace std;
string ss;
int ind;


bool merge_sort(vector<int> &aa, int l, int r) {
    if (r - l == 1) return 1;
    int m = l + r >> 1;
    if (!merge_sort(aa, l, m)) return 0;
    if (!merge_sort(aa, m, r)) return 0;
    vector<int> bb(r - l, -1);
    int i = l, j = m, k = 0;
    while (i < m && j < r) {
        if (ind == ss.size()) return 0;
        if (ss[ind] == '0') {
            bb[k] = aa[i];
            ++i;
        } else {
            bb[k] = aa[j];
            ++j;
        }
        ++k;
        ++ind;
    }
    for (; i < m; ++i, ++k) bb[k] = aa[i];
    for (; j < r; ++j, ++k) bb[k] = aa[j];
    for (int c = l; c < r; ++c) aa[c] = bb[c - l];
    return 1;
}

void solve() {
    cin >> ss;
    vector<int> aa;
    for (int l = 1; ; ++l) {
        ind = 0;
        aa.resize(l);
        for (int i = 0; i < l; ++i) aa[i] = i;
        if (merge_sort(aa, 0, l) && ind == ss.size()) break;
    }
    int n = aa.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[aa[i]] = i + 1;
    cout << n << "\n";
    for (auto el : ans) cout << el << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}






