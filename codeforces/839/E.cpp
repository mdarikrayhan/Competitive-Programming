#include <bits/stdc++.h>
using namespace std;

long long int ne[50];
long long int p[50];
int dp1[(1 << 20)], dp2[(1 << 20)], dp3[(1 << 20)];

int main()
{
	p[0] = 1;
	for (int i = 1;i < 50;i++)
	{
		p[i] = 2LL * p[i-1];
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int t;
			cin >> t;
			ne[i] += t * p[j];
		}
	}
	
	
	for (int mask = 1;mask < (1 << (n/2)); mask++)
	{
		int maskp = mask - (mask & -mask);
		dp1[mask] = max(dp1[maskp], 1 + (dp1[ne[__builtin_ctz(mask)] & maskp]));
	}
	int ans = dp1[(1 << (n/2)) - 1];
	dp2[0] = 1;
	dp3[0] = (1 << (n/2)) - 1;
	for (int mask = 1;mask < (1 << (n - n/2));mask++)
	{
		long long int maskp = mask - (mask & -mask);
		dp3[mask] = (dp3[maskp] & ne[__builtin_ctz(mask) + n/2]) % (1 << (n/2));
		
		if (maskp == 0)
		{
			ans = max(ans, 1 + dp1[dp3[mask]]);
			dp2[mask] = 1;
		}
		if (dp2[maskp] and dp2[mask - (maskp & -maskp)] and ( ne[__builtin_ctz(mask) + n/2] & ((maskp & -maskp) << (n/2)) ))
		{
			ans = max(ans, __builtin_popcount(mask) + dp1[dp3[mask]]);
			dp2[mask] = 1;
		}
	}
	double a = k * k * (ans - 1);
	cout << fixed << setprecision(20) << a / (2LL * ans) ;
	
}