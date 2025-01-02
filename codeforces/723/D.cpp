#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9 + 2;

const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

#define DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    auto border = [&](int x, int y) -> bool {
        return x == 0 || y == 0 || x == n - 1 || y == m - 1;
    };

    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1;
    };

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    auto dfs = [&](auto dfs, int x, int y, bool fill) -> ll {
        if (!valid(x, y) || visited[x][y] || grid[x][y] == '*') {
            return 0;
        }
        visited[x][y] = true;
        if (border(x, y)) {
            return inf;
        }
        if (fill) {
            grid[x][y] = '*';
        }
        ll total_cells = 1;
        for (auto [dx, dy]: DIRECTIONS) {
            int nx = x + dx;
            int ny = y + dy;
            total_cells += dfs(dfs, nx, ny, fill);
        }
        return total_cells;
    };

    vector<array<ll, 3>> lakes;
    int lakes_count = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                ll cells = dfs(dfs, i, j, false);
                if (cells < inf) {
                    lakes_count += 1;
                }
                lakes.push_back({cells, i, j});
            }
        }
    }
    sort(lakes.begin(), lakes.end());
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < lakes.size() && lakes_count > k; i++) {
        auto [cells, x, y] = lakes[i];
        ans += cells;
        lakes_count--;
        dfs(dfs, x, y, true);
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
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