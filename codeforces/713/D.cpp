#include<bits/stdc++.h>
using namespace std;

const bool multiTest = false;
#define task ""
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define BIT(mask, i) ((mask) >> (i) & 1)

const int MAX = 1001;
int nRow;
int nCol;
int nQuery;
int a[MAX][MAX];
int dp[10][MAX][10][MAX];

int getMax(int u, int v, int x, int y) {
    int k = __lg(x - u + 1), l = __lg(y - v + 1);
    return max({
               dp[k][u][l][v],
               dp[k][u][l][y - (1 << l) + 1],
               dp[k][x - (1 << k) + 1][l][v],
               dp[k][x - (1 << k) + 1][l][y - (1 << l) + 1],
    });
}

bool ok(int u, int v, int x, int y, int value) {
    return getMax(u, v, x, y) >= value;
}

void process(void) {
    cin >> nRow >> nCol;
    for (int i = 1; i <= nRow; ++i) {
        for (int j = 1; j <= nCol; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= nRow; ++i) {
        for (int j = 1; j <= nCol; ++j)
            if (a[i][j]) a[i][j] = min({a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]}) + 1;
    }
    for (int u = 0; (1 << u) <= nRow; ++u) for (int i = 1; i + (1 << u) - 1 <= nRow; ++i) {
        for (int v = 0; (1 << v) <= nCol; ++v) for (int j = 1; j + (1 << v) - 1 <= nCol; ++j){
            if (u == 0 && v == 0) {
                dp[u][i][v][j] = a[i][j];
                continue;
            }
            if (u == 0) {
                dp[u][i][v][j] = max(dp[u][i][v - 1][j], dp[u][i][v - 1][j + (1 << v - 1)]);
                continue;
            }
            if (v == 0) {
                dp[u][i][v][j] = max(dp[u - 1][i][v][j], dp[u - 1][i + (1 << u - 1)][v][j]);
                continue;
            }
            dp[u][i][v][j] = max(dp[u - 1][i][v][j], dp[u - 1][i + (1 << u - 1)][v][j]);
        }
    }
    cin >> nQuery; while (nQuery--) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        int lf = 0, rg = min(x - u + 1, y - v + 1) + 1;
        while (rg - lf > 1) {
            int mid = lf + rg >> 1;
            if (ok(u + mid - 1, v + mid - 1, x, y, mid)) lf = mid; else rg = mid;
        }
        cout << lf << '\n';
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r",  stdin);
		freopen(task".out", "w", stdout);
	}

	int nTest = 1; if (multiTest) cin >> nTest;
	while (nTest--) {
		process();
	}

	return 0;
}

 		 		    				  			 		 	 	