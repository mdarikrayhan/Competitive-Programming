#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        {
            auto count = [&](vector<int> &a) -> long long {
                long long ans = 0;
                vector<int> mx;
                for (int i = 0; i < n; i++) {
                    while (!mx.empty() && mx.back() <= a[i]) mx.pop_back();
                    mx.push_back(a[i]);
                    ans += mx.size();
                }
                return ans;
            };

            long long x = count(a);
            reverse(a.begin(), a.end());
            if (count(a) > x) reverse(a.begin(), a.end());
        }

        auto possible = [n](int test, vector<int> b) {
            bool ans = false;
            vector<pair<int, set<int>>> mx;

            vector<int> pref(n + 1);
            for (int i = 0; i < n; i++) pref[i + 1] = pref[i] ^ b[i];

            for (int i = 0; i < n; i++) {
                set<int> cur = { pref[i] };
                while (!mx.empty() && mx.back().first <= b[i]) {
                    if (cur.size() < mx.back().second.size()) swap(cur, mx.back().second);
                    for (auto e : mx.back().second) cur.insert(e);
                    mx.pop_back();
                }

                mx.push_back({ b[i], move(cur) });

                for (auto &[ m, s ] : mx) if (s.count(test ^ m ^ pref[i + 1]) == 1) ans = true;
            }

            return ans;
        };

        int ans = 0;
        int mask = 0;

        for (int i = 30; i >= 0; i--) {
            int test = ans | (1 << i);
            mask |= 1 << i;

            vector<int> b(n);
            for (int i = 0; i < n; i++) b[i] = a[i] & mask;

            if (possible(test, b)) ans = test;
        }

        cout << ans << "\n";
    }

    return 0;
}
