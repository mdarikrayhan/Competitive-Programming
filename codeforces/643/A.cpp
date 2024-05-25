// LUOGU_RID: 160141750
#include<bits/stdc++.h>
using namespace std;
int n,a[5001],bj[5001],sum[5001],id;
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)bj[j]=0;
		id=0;
		for(int j=i;j<=n;++j)
		{
			++bj[a[j]];
			if(bj[a[j]]>bj[id])id=a[j];
			else if(bj[a[j]]==bj[id])id=id<a[j]?id:a[j];
			++sum[id];
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",sum[i]);
	return 0;
}