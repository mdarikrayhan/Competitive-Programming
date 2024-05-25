#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < i; j++) {
            int str;
            cin >> str;
            a.push_back({str ,i, j});
        }
    }
    sort(a.rbegin(), a.rend());
    vector<int> team(2*n, -1);
    for (auto [s, i, j]: a) {
        if (team[i] != -1 || team[j] != -1) continue;
        team[i] = j;
        team[j] = i;
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << team[i] + 1 << " \n"[i == 2 * n - 1];
    }
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