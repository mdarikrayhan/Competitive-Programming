#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;
const int mod = 998244353;
const int N = 2e6 + 1000;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;

int n, m, k;
int a[110][31][31];

struct Tarjan {
    std::stack<int> stk;
    std::vector<std::vector<int>> scc, go;
    int idx = 0, cnt = 0, n;

    std::vector<int> bel, dfn, low;
    std::vector<bool> ins;

    explicit Tarjan(const std::vector<std::vector<int> > &g) : go(g){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        bel.assign(n, -1);
        ins.assign(n, false);
        while (!stk.empty()) stk.pop();
        idx = 0;
        build();
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++idx;
        ins[u] = true;
        stk.push(u);
        for (auto v: go[u]) {
            if (!dfn[v]) dfs(v);
            if (ins[v]) low[u] = std::min(low[u], low[v]);
        }

        if (dfn[u] == low[u]) {
            ++cnt;
            std::vector<int> c;
            while (true) {
                int v = stk.top();
                stk.pop();
                bel[v] = cnt;
                ins[v] = false;
                c.push_back(v);
                if (u == v) break;
            }
            std::sort(c.begin(), c.end());
            scc.push_back(c);
        }
    }

    void build(){
        for(int i = 1; i < n; i++)
            if (!dfn[i])
                dfs(i);
    }
};

bool equ(int x, int y) {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (a[x][i][j] != a[y][i][j])
                return false;
    return true;
}

bool check(int x, int i, int j) {
    if (a[x][i + 1][j] == a[x][i][j]) return false;
    if (a[x][i][j + 1] == a[x][i][j]) return false;
    if (a[x][i - 1][j] == a[x][i][j]) return false;
    if (a[x][i][j - 1] == a[x][i][j]) return false;
    return true;
}

int differ(int x) {
    int cnt = 0;
    for (int i = 2; i < n; i ++)
        for (int j = 2; j < m; j ++)
            if (check(x, i, j))
                cnt ++;
    return cnt;
}

void solve() {
    std::cin >> n >> m >> k;
    k ++;
    std::vector<std::vector<int>> go(k + 1);
    std::vector<int> next(n + 1);
    for (int i = 1; i <= k; i ++) {
        for (int r = 1; r <= n; r ++) {
            std::string s;
            std::cin >> s;
            s = "?" + s;
            for (int c = 1; c <= m; c ++)
                a[i][r][c] = s[c] - '0';
        }
    }

    std::vector<PII> b(k + 1);
    for (int i = 1; i <= k; i ++) {
        b[i].first = differ(i);
        b[i].second = i;
    }
    std::sort(b.begin() + 1, b.end(), std::greater<>());

    std::cout << b[1].second << "\n";
    std::vector<std::array<int, 3>> ans;
    for (int i = 2; i <= k; i ++) {
        if (b[i].first == b[i - 1].first)
            ans.push_back({2, b[i].second, 0});
        else {
            int x = b[i - 1].second, y = b[i].second;
            for (int r = 2; r < n; r ++)
                for (int c = 2; c < m; c ++)
                    if (a[x][r][c] != a[y][r][c])
                        ans.push_back({1, r, c});
            ans.push_back({2, b[i].second, 0});
        }
    }

    std::cout << ans.size() << "\n";
    for (auto [ty, x, y] : ans) {
        std::cout << ty << " ";
        if (ty == 2) std::cout << x << "\n";
        else std::cout << x << " " << y << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();
    return 0;
}