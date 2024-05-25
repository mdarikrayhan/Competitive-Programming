// LUOGU_RID: 160240539
// CF768D Jon and Orbs
#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;
int k, q;
double f[MAXN * 10][MAXN]; // f[i][j]: 第i天拥有j种物品的概率 

void init()
{
	f[0][0] = 1;
	for(int i = 1; i <= k * 10; i++)
	{
		for(int j = 1; j <= min(i, k); j++)
			f[i][j] = f[i-1][j-1] * (k-j+1) / k + f[i-1][j] * j / k;
	}
}

int main()
{
	cin >> k >> q;
	init();
	for(int i = 1, p; i <= q; i++)
	{
		cin >> p;
		int ans;
		for(ans = 1; ; ans++)
			if(f[ans][k] >= p / 2000.0) break;
		cout << ans << endl;
	}
	return 0;
}