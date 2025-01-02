#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a[1000005],tans[1000005][2],tt;
ll ans=0;
void getswap(int x,int y)
{
	swap(a[x],a[y]);
	tans[++tt][0]=x;
	tans[tt][1]=y;
	ans+=1ll*(x-y)*(x-y);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=tt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=i;
		getswap(1,n);
		for(int i=n/2+1;i<n;i++)
			getswap(1,i);
		for(int i=2;i<=n/2;i++)
			getswap(n,i);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n%d\n",tt);
		for(int i=tt;i;i--)
			printf("%d %d\n",tans[i][1],tans[i][0]);
	}
	return 0;
}
