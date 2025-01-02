#include <bits/stdc++.h>

using namespace std;
const int N = 505;
char g[N][N];
int comp[N][N], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, sz[N * N], n, k, cc, cur;
#define uni(vec) vec.erase(unique(vec.begin(), vec.end()), vec.end())
bool valid(int x, int y) { return x < n && x >= 0 && y < n && y >= 0; }

void bfs(int stx, int sty) {
    cc++;
    vector<pair<int, int>> q = {{stx, sty}};
    comp[stx][sty] = cc;
    for (int v = 0; v < q.size(); v++) {
        auto [x, y] = q[v];
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (valid(nx, ny) && !comp[nx][ny] && g[nx][ny] == '.')
                comp[nx][ny] = cc, q.push_back({nx, ny});
        }
    }
    sz[cc] = q.size();
}

int fq[N * N];

void add(int x) {
    if (!fq[x])
        cur += sz[x];
    fq[x]++;
}
void rem(int x) {
    fq[x]--;
    if (!fq[x])
        cur -= sz[x];
}

void addStrip(int i, int j) {
    for (int l = 0; l < k; l++) {
        cur += g[i + l][j] == 'X';
        if (comp[i + l][j])
            add(comp[i + l][j]);
        for (int d = 0; d < 4; d++) {
            int nx = i + l + dx[d], ny = j  + dy[d];
            if (valid(nx, ny) && comp[nx][ny])
                add(comp[nx][ny]);
        }
    }
}
void removeStrip(int i, int j) {
    for (int l = 0; l < k; l++) {
        cur -= g[i + l][j] == 'X';
        if (comp[i + l][j])
            rem(comp[i + l][j]);
        for (int d = 0; d < 4; d++) {
               int nx = i + l + dx[d], ny = j  + dy[d];
            if (valid(nx, ny) && comp[nx][ny])
                rem(comp[nx][ny]);
        }
    }
}
void tc() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '.' && !comp[i][j]) {
                bfs(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j < k; j++)
            addStrip(i, j);
        ans = max(ans, cur);
        for (int j = 0; j + k < n; j++) {
            removeStrip(i, j);
            addStrip(i, j + k);
            ans = max(ans, cur);
        }
        for (int j = n - k; j < n; j++)
            removeStrip(i, j);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;

    //    cin >> t;

    while (t--) {
        tc();
    }

    return 0;
}
  			  			    				    	 			  		