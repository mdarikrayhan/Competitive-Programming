#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> PII;

const int N = 110;
const int mod = 998244353;

int a[N][N], f[N][N];

void Solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++ i )
		for (int j = i; j <= n; j ++ )
			cin >> a[i][j];
	
	f[1][1] = 2;
	
	for (int i = 1; i <= n; ++ i )
	{
		for (int j = 1; j <= i; j ++ )
		{
			bool st = true;
			for (int k = 1; k <= i; k ++ )
			{
				if(a[k][i] == 2 && k >= j)  st = false;
				if(a[k][i] == 1 && k < j)  st = false;
			}
			
			if(!st)  f[i][j] = 0;
			
			f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
			f[i + 1][i + 1] = (f[i + 1][i + 1] + f[i][j]) % mod;
		}
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i ++ )	
		sum = (sum + f[n][i]) % mod;

	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	while(T --)  Solve();
	return 0;
} 