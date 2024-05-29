#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,k,Max,res;
int d[N];
bool vis[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		Max+=n/i-1;
	if(k>Max)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i=2;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j*j<=i;j++)
		if(i%j==0)
		{
			if(j*j==i)d[j]++,cnt++;
			else d[j]++,d[i/j]++,cnt+=2;
		}
		d[i]=cnt-1;
		res+=d[i];
		if(res>=k)
		{
			int ans=i,rmin=res-k,sum=0,p=0;
			for(int j=1;j<=i;j++)
			{
				if(d[j]<=res-k)
				{
					if(d[j]>sum)
					sum=d[j],p=j;
				}
			}
			vis[p]=1;rmin-=sum;
			if(p>0)ans--;
			for(int j=1;j<=i;j++)
			{
				if(d[j]==1&&rmin)
					rmin--,vis[j]=1,ans--;
			}
			printf("%d\n",ans);
			for(int j=1;j<=i;j++)	
				if(!vis[j])
					printf("%d ",j);
			return 0;
		}
	}
	return 0;
}
     	 	 	 				    	 		      		