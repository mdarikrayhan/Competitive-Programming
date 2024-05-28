// LUOGU_RID: 159490445
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
#include <functional>
#include <unordered_set>
#include <numeric>
#include <fstream>
#include <cstring>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

#include <iostream>
#include <set>
#include <vector>

int visited[5000];
int g[5000][5000];

bool check(int target, vector<PII> &towers) {
    int n = towers.size();
    memset(g, 0, sizeof g);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (abs(towers[i].first - towers[j].first) + abs(towers[i].second - towers[j].second) > target) {
                g[i][j] = true;
                g[j][i] = true;
            }
        }
    }
    memset(visited, 0, sizeof visited);
    function<bool(int, int)> bigraph = [&] (int i, int col) {
        visited[i] = col;
        for (int next = 0; next < n; ++next) {
            if (!g[i][next]) {
                continue;
            }
            if (visited[next] == col || (visited[next] == 0 && !bigraph(next, -col))) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !bigraph(i, 1)) {
            return false;
        }
    }
    return true;
}

LL expo(int i) {
    LL M = 1e9+7;
    if (i == 0) {
        return 1;
    }
    LL res = expo(i / 2);
    res = res * res;
    if (i % 2 == 1) {
        res *= 2;
    }
    return res % M;
}

void solve(vector<PII> &towers) {
    int n = towers.size();
    int left = 0, right = 10000;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid, towers)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    int len = right;
    if (check(left, towers)) {
        len = left;
    }

    memset(g, 0, sizeof g);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (abs(towers[i].first - towers[j].first) + abs(towers[i].second - towers[j].second) > len) {
                g[i][j] = true;
                g[j][i] = true;
            }
        }
    }
    memset(visited, 0, sizeof visited);
    function<bool(int, int)> dfs = [&] (int pa, int i) {
        visited[i] = true;
        int res = 1;
        for (int next = 0; next < n; ++next) {
            if (!g[i][next] || next == pa || visited[next]) {
                continue;
            }
            res += dfs(i, next);
        }
        return res;
    };
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            count++;
        }
        dfs(-1, i);
    }
    cout << len << endl;
    cout << expo(count) << endl;
}

int main() {
    int n;
    cin >> n;
    vector<PII> towers(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        towers[i] = {x, y};
    }
    solve(towers);
    return 0;
}
