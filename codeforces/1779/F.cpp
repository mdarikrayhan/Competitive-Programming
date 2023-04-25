#include<cstdio>
#include<cstring>
unsigned dp[200001];
int a[200001],c[200001],f[200001],l[200001][32],v[200001];
int main()
{
	int n,i,x,y,p=0;unsigned t;
	scanf("%d",&n);
	memset(l,-1,sizeof(l));
	for(i=1;i<=n;i++)scanf("%d",a+i),dp[i]=1<<a[i],c[i]=1;
	for(i=2;i<=n;i++)scanf("%d",f+i);
	for(i=n;i;i--)
	{
		c[f[i]]+=c[i];
		if(~c[i]&1)dp[i]|=1;
		t=0;
		for(x=0;x<32;x++)
			if(dp[f[i]]&(1<<x))
				for(y=0;y<32;y++)
					if(dp[i]&(1<<y))
					{
						t|=1<<(x^y);
						l[i][x^y]=x;
					}
		dp[f[i]]=t;
	}
	if(!(dp[1]&1))return puts("-1"),0;

	dp[1]=1,v[p++]=1;
	for(i=2;i<=n;i++)
	{
		x=__builtin_ctz(dp[f[i]]),t=0;
		if(x<32&&~l[i][x])
		{
			dp[f[i]]=1<<l[i][x];
			t=1<<(x^l[i][x]);
		}
		if(t==1&&(~c[i]&1))t=0,v[p++]=i;
		dp[i]=t;
	}
	printf("%d\n",p*2);
	while(p--)printf("%d %d%c",v[p],v[p]," \n"[!p]);
}