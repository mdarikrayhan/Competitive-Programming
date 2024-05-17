#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] == 'B' ? 1 : 0);
    }

    auto check = [&](int col) -> bool {
        vector<int> operations;
        auto tmp = a;
        for (int iter = 0; iter < 3; iter++) {
            for (int i = 0; i < n - 1; i++) {
                if (tmp[i] != col) {
                    operations.push_back(i + 1);
                    tmp[i] ^= 1;
                    tmp[i + 1] ^= 1;
                }
            }
        }
        if (all_of(tmp.begin(), tmp.end(), [&](int x) {return x == col;})) {
            cout << operations.size() << endl;
            for (auto &op: operations) {
                cout << op << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    };

    if (check(0)) {
        return;
    }

    if (check(1)) {
        return;
    }

    cout << -1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}