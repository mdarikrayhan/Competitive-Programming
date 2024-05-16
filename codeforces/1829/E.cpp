#include<iostream>
#include<algorithm>
using namespace std;
int all[1010][1010];
int f[1010][1010];
int maxans = 0;
int ans = 0;
void dfs(int p1, int p2, int n, int m)
{
	f[p1][p2] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			if (p2 + 1 <= m - 1 and all[p1][p2 + 1] != 0 and f[p1][p2 + 1] !=1 )
			{
				ans += all[p1][p2 + 1];
				dfs(p1, p2 + 1, n, m);
			}
		}
		if (i == 1)
		{
			if (p1 + 1 <= n - 1 and all[p1+1][p2] != 0 and f[p1 + 1][p2] != 1)
			{
				ans += all[p1+1][p2];
				dfs(p1+1, p2, n, m);
			}
		}
		if (i == 2)
		{
			if (p2-1>=0 and all[p1][p2 - 1] != 0 and f[p1][p2 - 1] != 1)
			{
				ans += all[p1][p2 - 1];
				dfs(p1, p2 - 1, n, m);
			}
		}
		if (i == 3)
		{
			if (p1 - 1 >=0 and all[p1-1][p2] != 0 and f[p1 - 1][p2] != 1)
			{
				ans += all[p1-1][p2];
				dfs(p1-1, p2, n, m);
			}
		}
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	int n, m;
	int kk;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> kk;
				all[j][k] = kk;
				f[j][k] = 0;
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (all[j][k] != 0 and f[j][k]!=1)
				{
					ans = all[j][k];
					dfs(j, k, n, m);
					if (ans > maxans) maxans = ans;
				}
			}
		}
		cout << maxans << endl;
		maxans = 0;
	}
}
  	 	 	 	  		  		    					  	