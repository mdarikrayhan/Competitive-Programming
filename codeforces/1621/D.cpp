#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
typedef long long ll;

int T, n;
int a[MAXN][MAXN];

void solve() {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 1; j <= 2 * n; j++) {
            scanf("%d", &a[i][j]);
            if (i > n && j > n) sum += a[i][j];
        }
    int mn = 2e9;
    for (int x : {1, n, n + 1, 2 * n})
        for (int y : {1, n, n + 1, 2 * n}) {
            if ((x <= n && y <= n) || (x > n && y > n)) continue;
            mn = min(mn, a[x][y]);
        }
    printf("%lld\n", sum + mn);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) solve();
}
		   		 	   	    			 		 			  		