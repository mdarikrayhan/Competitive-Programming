// LUOGU_RID: 160318001
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e3 + 5;
int n, q, opt, x1, x2, y1, y2, k, t[2][2][N<<1][N<<1];

int lowbit(int x){return x & -x;}

void update(int x, int y, int val)
{
	for(int i = x;i <= n;i += lowbit(i))
		for(int j = y;j <= n;j += lowbit(j))
			t[x%2][y%2][i][j] ^= val;
}

int query(int x, int y)
{
	int res = 0;
	for(int i = x;i;i -= lowbit(i))
		for(int j = y;j;j -= lowbit(j))
			res ^= t[x%2][y%2][i][j];
	return res;
}

signed main()
{
	scanf("%d %d", &n, &q);
	while(q--)
	{
		scanf("%d", &opt);
		if(opt == 1)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", query(x1-1, y1-1) ^ query(x1-1, y2) ^ query(x2, y1-1) ^ query(x2, y2));
		}
		else
		{
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
			update(x1, y1, k);
			update(x1, y2+1, k);
			update(x2+1, y1, k);
			update(x2+1, y2+1, k);
		}
	}
	return 0;
}