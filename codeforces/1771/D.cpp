// LUOGU_RID: 160355139
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e3 + 5;
int t, n;
string str;
vector<int> G[MAXN];
int fa[MAXN][MAXN], memo[MAXN][MAXN];

void dfs(int x, int father, int root){
    fa[root][x] = father;
    for (int i : G[x]){
        if (i != father)
            dfs(i, x, root);
    }
}

int calc(int x, int y){
    if (x == y) return 1;
    if (x == fa[1][y] || y == fa[1][x]) return 1 + (str[x] == str[y]);
    if (memo[x][y]) return memo[x][y];
    return memo[x][y] = max(calc(x, fa[x][y]), max(calc(y, fa[y][x]), calc(fa[x][y], fa[y][x]) + (str[x] == str[y] ? 2 : 0)));
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        str = " " + str;
        for (int i=1; i<=n; i++){
            G[i].clear();
            for (int j=1; j<=n; j++)
                fa[i][j] = memo[i][j] = 0;
        }
        for (int i=1, u, v; i<n; i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // 预处理
        for (int i=1; i<=n; i++) dfs(i, 0, i);
        int ans = 0;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                ans = max(ans, calc(i, j));
        cout << ans << endl;
    }
    
    return 0;
}