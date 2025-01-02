#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> ans;

void mel(int l, int r, bool maju) {
    if (maju) {
        for (int i = l; i <= r; i++) {
            ans.push_back(i%n);
        }
    } else {
        for (int i = r; i >= l; i--) {
            ans.push_back(i%n);
        }
    }
}

void young(int l, int r) {
    int L = l, R = r - 1;
    bool maju = false;
    while (L <= R) {
        mel(L, R, maju);
        if (maju) R--;
        else L++;
        maju ^= 1;
    }
    int len = l + (r - l >> 1);
    for (int i = l; i < len; i++) {
        ans.push_back(i%n);
    }
}

void solve() {
    cin >> n;
    young(0, n - 1);
    young(n + 1 >> 1, (n + 1 >> 1) + n - 1 - (1 & n));
    young(0, n - 1);
    cout << (int) ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
