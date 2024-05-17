#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <map>
#include <stack>
#include <set>

#define x first
#define y second
//#define int long long

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const LL INFF = 0x3f3f3f3f3f3f3f3f;

const int N = 10, INF = 0x3f3f3f3f, M = N << 1;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool vis[N][N];

inline void solve()
{
	string a, b;
	cin >> a >> b;
	int x1 = a[0] - 'a' + 1, y1 = a[1] - '0';
	int x2 = b[0] - 'a' + 1, y2 = b[1] - '0';
	vis[x1][y1] = vis[x2][y2] = true;
	int res = 0;
	for (int i = 1; i <= 8; i ++ ) {
		for (int j = 1; j <= 8; j ++ ) {
			if (vis[i][j] || i == x1 || j == y1) continue;
			bool flag = true;
			for (int k = 0; k < 8; k ++ ) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
					if (vis[nx][ny]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) res ++;
		}
	}
	cout << res << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t -- )
	{
//		init();
		solve();
	}
	return 0;
}

