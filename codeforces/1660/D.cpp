#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include "template.cpp.h"

#else
#define debug(...)
#endif
#define int long long
using namespace std;
#define cinv(v) for (auto &it:v) cin>>it;
#define coutv(v) for (auto &it:v) cout<< it<<" "; cout<<'\n';


void shelby() {
    int n;
    cin >> n;
    vector<int> v(n);
    cinv(v)
    vector<pair<int, int>> vp;
    for (int i = 0, j = 0; j < n; ++j) {
        if (v[j] == 0) {
            if (j - 1 >= i) vp.push_back({i, j - 1});
            i = j + 1;
        }
        else if (j == n - 1) vp.push_back({i, j});
    }

    int ans = 0, f = n, b = 0;
    for (auto &it: vp) {
        int now = 1, cnt = 0;
        for (int i = it.first; i <= it.second; ++i) {
            now *= v[i] / abs(v[i]);
            if (abs(v[i]) == 2) cnt++;
        }
        int f1 = it.first, b1 = n - it.second - 1;
        if (now > 0) {
            if (cnt > ans) ans = cnt, f = f1, b = b1;
        }
        else {
            int tmp = now, cnt1 = cnt;
            for (int i = it.first; i <= it.second; ++i) {
                tmp /= v[i] / abs(v[i]);
                if (abs(v[i]) == 2) cnt1--;
                if (v[i] < 0) {
                    f1 = i + 1;
                    break;
                }
            }
            if (f1 + b1 < n && cnt1 > ans) ans = cnt1, f = f1, b = b1;
            tmp = now, f1 = it.first, cnt1 = cnt;
            for (int i = it.second; i >= it.first; --i) {
                tmp /= v[i] / abs(v[i]);
                if (abs(v[i]) == 2) cnt1--;
                if (v[i] < 0) {
                    b1 = n - i;
                    break;
                }
            }
            if (f1 + b1 < n && cnt1 > ans) ans = cnt1, f = f1, b = b1;
        }
    }
    cout << f << ' ' << b << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int _ = 1; _ <= t; ++_) {
//        cout << "Case " << _ << ": ";
        shelby();
    }
}