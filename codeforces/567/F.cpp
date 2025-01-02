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
#define int ll
const int N = 505;
int n, k, g[N][N], f[N][N];
map <string, int> mp;
bool chk(int x, int y, int t) {
    if (x < 0 || y < 0) return 0;
    if (!g[x][y]) return 1;
    return g[x][y] == t; 
}
bool func(int l, int r, int x) {
    // if (l > r) return 0;
    R(k, l, r) 
        if (!chk(k, x, 3) && !chk(k, x, 5)) return 0;
    return 1;
}
signed main() {
    cin >> n >> k;
    mp[">"] = 1, mp["="] = 2, mp["<"] = 3, mp[">="] = 4, mp["<="] = 5;
    R(i, 1, k) {
        int x, y; string op; cin >> x >> op >> y;
        g[x][y] = mp[op];
        if (g[x][y] == 1) g[y][x] = 3;
        else if (g[x][y] == 3) g[y][x] = 1;
        else if (g[x][y] == 4) g[y][x] = 5;
        else if (g[x][y] == 5) g[y][x] = 4;
        else if (g[x][y] == 2) g[y][x] = 2;
        // cout << g[x][y] << endl;
    }
    // cout << g[3][2] << ' ' << func(1, 2, 3) << endl;
    f[0][0] = 1;
    R(i, 1, n) {
        R(j, 0, 2 * i) {
            bool flg = 1;
            int p = 2 * i - j; // 右边放的数量
            flg = func(1, j - 2, j - 1); flg &= func(1, j - 2, j);
            flg &= func(2 * n - p + 1, 2 * n, j - 1); flg &= func(2 * n - p + 1, 2 * n, j);
            flg &= (chk(j - 1, j, 2) | chk(j - 1, j, 4) | chk(j - 1, j, 5));
            if (flg && j >= 2) f[j][p] += f[j - 2][p];
            flg = func(1, j - 1, j); flg &= func(1, j - 1, 2 * n - p + 1);
            flg &= func(2 * n - p + 2, 2 * n, 2 * n - p + 1); flg &= func(2 * n - p + 2, 2 * n, j);
            flg &= (chk(2 * n - p + 1, j, 2) | chk(2 * n - p + 1, j, 4) | chk(2 * n - p + 1, j, 5));
            if (flg && j > 0 && p > 0) f[j][p] += f[j - 1][p - 1];
            flg = func(1, j, 2 * n - p + 1); flg &= func(1, j, 2 * n - p + 2);
            flg &= func(2 * n - p + 3, 2 * n, 2 * n - p + 1); flg &= func(2 * n - p + 3, 2 * n, 2 * n - p + 2);
            flg &= (chk(2 * n - p + 1, 2 * n - p + 2, 2) | chk(2 * n - p + 1, 2 * n - p + 2, 4) | chk(2 * n - p + 1, 2 * n - p + 2, 5));
            if (flg && p >= 2) f[j][p] += f[j][p - 2];
            // cout << func(1, j, 2 * n - p + 1) << ' ' << 
            // cout << j << ' ' << p << ' ' << f[j][p] << '\n';
        }
    }
    int ans = 0;
    R(i, 0, 2 * n) ans += f[i][2 * n - i];
    cout << ans / 3 << endl;
    return 0;
}
 		 	 	 			 	  	  	 			  	  			