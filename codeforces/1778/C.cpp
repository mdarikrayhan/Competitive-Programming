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
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    string t = a;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<string> v;
    auto combination = [&](auto &&self, int now, int rem, string s) {
        if (now == t.size() || rem == 0) {
            v.push_back(s);
            return;
        }
        self(self, now + 1, rem, s);
        self(self, now + 1, rem - 1, s + t[now]);
    };
    combination(combination, 0, k, "");
    int ans = 0;
    for (auto &it: v) {
        string tmp;
        for (int i = 0; i < n; ++i) {
            if (it.find(a[i]) != -1) tmp += b[i];
            else tmp += a[i];
        }
        int now = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (tmp[i] == b[i]) cnt++;
            else {
                now += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        now += (cnt * (cnt + 1)) / 2;
        ans = max(ans, now);
    }
    cout << ans << '\n';
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