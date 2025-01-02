 #include <bits/stdc++.h>
using namespace std;
#define lli long long int  

const int maxn = 6e1 + 5;
const int mod = 998244353;

int n, m, a[maxn][maxn][maxn], dis[maxn][maxn][maxn][maxn], dp[maxn][maxn][maxn], q;

int main (){
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				cin >> dis[i][j][k][0];
				//dis[i][u][v][0] = a[i][u][v];
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int k = 1; k <= n; k++)
   		for (int u = 0; u < n; u++){
   			for (int v = 0; v < n; v++){
   					dis[i][u][v][k] = min(dis[i][u][v][k - 1], dis[i][u][k - 1][k - 1] + dis[i][k - 1][v][k - 1]);
   			}
   		}
	}
	for (int u = 0; u < n; u++){
		for (int v = 0; v < n; v++){
			int mn = 1e9;
			for (int i = 0; i < m; i++){
				mn = min(mn, dis[i][u][v][n]);
			}
			dp[u][v][0] = mn;
		}
	}
	for (int r = 1; r < n; r++)
   	for (int u = 0; u < n; u++){
   		for (int v = 0; v < n; v++){
   				int mn = 1e9;
   				for (int x = 0; x < n; x++){
   					mn = min(mn, dp[u][x][0] + dp[x][v][r - 1]);
   				}
   				dp[u][v][r] = mn;
   		}
   	}
	for (int i = 0, u, v, r; i < q; i++){
		cin >> u >> v >> r;
		r = min(r, n - 1);
		u--;
		v--;
		cout << dp[u][v][r] << '\n';
	}
}