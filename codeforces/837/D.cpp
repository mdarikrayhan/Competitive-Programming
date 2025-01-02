// LUOGU_RID: 160092636
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 205;
const int MAXM = 6205;
int n, k;
int hav2[MAXN], hav5[MAXN];
int DP[MAXM][MAXN];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++)
	{
		long long x;
		scanf("%lld", &x);
		while(x % 2 == 0) 
		{
			hav2[i] ++;
			x /= 2;
		}
		while(x % 5 == 0)
		{
			hav5[i] ++;
			x /= 5;
		}
	}
	memset(DP, -0x3f, sizeof(DP));
	DP[0][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j >= 1; j --)
		{
			for(int g = MAXM - 1; g >= hav5[i]; g --)
			{	
				DP[g][j] = max(DP[g][j], DP[g - hav5[i]][j - 1] + hav2[i]);
			}		
		}
	}
	int ans = 0;
	for(int i = 1; i < MAXM; i ++) 
	{
		ans = max(ans, min(i, DP[i][k]));
		// cout << i << " " << DP[i][k] << endl; 
	}
	printf("%d\n", ans);
	return 0;
}