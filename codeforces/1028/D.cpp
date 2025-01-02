#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int P = 1e9 + 7;
    auto gg = [&]() {
        cout << 0 << '\n';
        exit(0);
    };
    int n;
    cin >> n;
    set<int> buy;
    set<int> sell;
    set<int> idk;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        string type;
        int p;
        cin >> type >> p;
        if (type == "ADD") {
            if (!buy.empty() && p < *buy.rbegin()) {
                buy.insert(p);
            } else if (!sell.empty() && p > *sell.begin()) {
                sell.insert(p);
            } else {
                idk.insert(p);
            }
        }
        if (type == "ACCEPT") {
            if (idk.count(p)) {
                ans = 2 * ans % P;
                idk.erase(p);
            } else if (buy.count(p)) {
                if (*buy.rbegin() > p) gg();
                buy.erase(p);
            } else {
                if (*sell.begin() < p) gg();
                sell.erase(p);
            }
            for (int x : idk) {
                if (x < p) buy.insert(x);
                else sell.insert(x);
            }
            idk.clear();
        }
    }
    int L = buy.empty() ? 0 : *buy.rbegin();
    int R = sell.empty() ? 1e9 : *sell.begin();
    int cnt = 1;
    for (int x : idk) {
        if (L <= x && x <= R) {
            cnt++;
        }
    }
    ans = 1LL * ans * cnt % P;
    cout << ans << '\n';
}

