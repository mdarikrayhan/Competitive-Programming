#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d %d",&n,&k);
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=a[n-i+1][n-j+1]) ans++;
		}
		ans/=2;
		if(k>=ans&&((k-ans)%2==0||n%2==1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}