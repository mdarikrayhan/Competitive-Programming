#include <bits/stdc++.h>

using namespace std;

#define Fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define int ll
#define all(v) v.begin(), v.end()

signed main() {
    Fast
    int test_cases{1};
    cin >> test_cases;
    while (test_cases--) {
        int n, q, idx = 0;
        cin >> n >> q;
        vector<int> v(n);
        set<int> s;
        for (auto &item: v)cin >> item, s.insert(idx++);
        auto digitSum = [&](int x) {
            int res = 0;
            while (x) {
                res += x % 10;
                x /= 10;
            }
            return res;
        };
        while (q--) {
            int id;
            cin >> id;
            if (id == 1) {
                int l, r;
                cin >> l >> r, --l, --r;
                if (s.empty())continue;
                auto it = s.lower_bound(l);
                vector<int> er;
                while (it != s.end() and (*it) <= r) {
                    v[(*it)] = digitSum(v[*it]);
                    if (v[(*it)] <= 9)er.push_back((*it));
                    it++;
                }
                if (!er.empty()) {
                    for (auto &it: er) {
                        if (s.find(it) != s.end())s.erase(s.find(it));
                    }
                }
            } else {
                int pos;
                cin >> pos, --pos;
                cout << v[pos] << '\n';
            }
        }
    }
    return 0;
}