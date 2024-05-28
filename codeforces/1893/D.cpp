#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

mt19937 gen(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

const int maxn = 2e5 + 1, mod = 1e9 + 7;

int a[maxn], s[maxn], d[maxn];
vector<int> g[maxn];

bool cmp(int x, int y) {
    return d[x] > d[y];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    vector<int> q(m);
    iota(all(q), 0);
    sort(all(q), cmp);
    set<pair<int, int>> available;
    for (int i = 1; i <= n; i++) {
        available.insert({-cnt[i], i});
    }
    for (int i : q) {
        g[i].clear();
        for (int j = 0; j < s[i]; j++) {
            auto gg = *available.begin();
            if (!gg.first) {
                cout << "-1\n";
                return;
            }
            available.erase(gg);
            g[i].push_back(gg.second);
            --cnt[gg.second];
            if (j >= d[i] - 1) {
                int x = g[i][j - d[i] + 1];
                available.insert({-cnt[x], x});
            }
        }
        for (int j = s[i] - d[i] + 1; j < s[i]; j++) {
            available.insert({-cnt[g[i][j]], g[i][j]});
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s[i]; j++) {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}