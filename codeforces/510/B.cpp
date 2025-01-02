#include <bits/stdc++.h>

using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define watch(x) cout << #x << " = " << x << endl;
#define endl "\n"
typedef long long ll;

void Open() {
#ifndef ONLINE_JUDGE
    freopen("standard.in", "r", stdin);
    freopen("standard.out", "w", stdout);
#endif
}

const int mod = ll(1e8), N = 1e6 + 5 + 2, oo = 0x3f3f3f3f;

vector<vector<int>> get_b(vector<vector<int>> &a);

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j) {
    return i < n && j < m && i >= 0 && j >= 0;
}

int vis[100][100], T = 0;
vector<vector<char>> v;

bool dfs(int i, int j, int i1, int j1, char &ch) {
    if (!valid(i, j))return 0;
    if (vis[i][j] == T)return 1;
    vis[i][j] = T;
    for (int id = 0; id < 4; ++id) {
        int x = i + dx[id];
        int y = j + dy[id];
        if (valid(x, y) && !((x == i1) && (y == j1)) && v[x][y] == ch) {
            if (dfs(x, y, i, j, ch))return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    v = vector<vector<char>> (n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++T;
            if (dfs(i, j, -1, -1, v[i][j])) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}


int main() {
    Ma7moud_7amdy;
    Open_Sesame;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}