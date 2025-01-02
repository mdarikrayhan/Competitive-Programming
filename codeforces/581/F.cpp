#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ptc putchar
#define pb push_back
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("--------------------------------------------")
typedef long long ll;
typedef pair<int, int> PII;
namespace ZeroTwo {
    template <typename T>
    il void read(T &x) {
        x = 0; T f = 1; char ch;
        while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
        x *= f;
    }
    template <typename T, typename ...L>
    il void read(T &x, L &...y) {read(x); read(y...);}
    template <typename T>
    il void write(T x) {
        if (x < 0) ptc('-'), x = -x;
        if (x > 9) write(x / 10);
        ptc(x % 10 + '0');
    }
    template <typename T, typename ...L>
    il void write(T &x, L &...y) {write(x), ptc(' '); write(y...);}
}
using namespace ZeroTwo;
const int N = 5005;
int n, f[N][N][2]; // 以i为根的子树内，有j个点染成了黑色，当前点是(0/1)白黑，此时的最小两端不同色的边数
int g[N][N], tot, sz[N];
vector <int> E[N];
void init(int x, int fa) {
    sz[x] = 1;
    for (auto v : E[x]) {
        if (v == fa) continue;
        init(v, x);
        sz[x] += sz[v];
    }
}
void dfs(int x, int fa) {
    // cout << x << endl;
    if (E[x].size() == 1) {
        R(j, 0, sz[x]) 
            R(k, 0, 1) f[x][j][k] = INT_MAX / 2;
        f[x][1][1] = 0;
        f[x][0][0] = 0;
        return ;
    }
    bool flg = 0;
    for (int v : E[x]) {
        if (v == fa) continue;
        dfs(v, x);
        R(j, 0, sz[x]) 
            R(k, 0, 1) g[j][k] = f[x][j][k], f[x][j][k] = INT_MAX / 2;
        if (!flg) {
            R(j, 0, sz[x]) R(k, 0, 1) g[j][k] = INT_MAX / 2;
            g[0][0] = g[0][1] = 0;
            flg = 1;
        }
        R(j, 0, sz[x]) {
            R(k, 0, min(sz[v], tot / 2 - j)) {
                // cout << f[x][j + k][0] << endl;
                f[x][j + k][0] = min(g[j][0] + min(f[v][k][1] + 1, f[v][k][0]), f[x][j + k][0]);
                f[x][j + k][1] = min(g[j][1] + min(f[v][k][0] + 1, f[v][k][1]), f[x][j + k][1]);
                // if (x == 1) cout << j << ' '<< k << ' '<< g[j][0] << ' ' << f[v][k][1] << ' ' << f[v][k][0] << ' ' << f[x][j + k][0] << endl;
                // cout << f[x][j + k][0] << endl;
            }
        }
        // R(j, 0, tot / 2) cout << x << ' '<< j << ' '<< f[x][j][0] << endl;
    }
}
signed main() {
    cin >> n; 
    R(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }
    int root = 0;
    R(i, 1, n) {
        if (E[i].size() > 1) root = i;
        else ++tot;
    }
    init(root, 0);
    dfs(root, 0);
    cout << min(f[root][tot / 2][0], f[root][tot / 2][1]) << endl;
    return 0;
}
	  	  		 		  	   	  				 	 	 	