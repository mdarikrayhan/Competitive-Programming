// LUOGU_RID: 160359495
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s*w;
}
inline void print(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
int T,n,pre[2010][4010],suf[2010][4010];
string a,b;
const int mod=1e9+7;
inline int check(char ch,int x)
{
	if(ch=='?'||ch==x+48)return 1;
	return 0;
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				if(a[i]!='?')a[i]=49-a[i]+48;
				if(b[i]!='?')b[i]=49-b[i]+48;
			}
		}
		pre[0][2000]=1;
		suf[n+1][2000]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=4000;j++)
			{
				for(int k=0;k<=1;k++)
				{
					for(int l=0;l<=1;l++)
					{
						if(check(a[i],k)&&check(b[i],l))
						{
//							puts("dggdgdgd");
							if(j-k+l>=0)
							{
								pre[i][j]+=pre[i-1][j-k+l],pre[i][j]%=mod;
//								cout<<i-1<<' '<<j<<" "<<j-k+l<<' '<<pre[i][j]<<'\n';
							}
						}
					}
				}
			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<=4000;j++)
			{
				for(int k=0;k<=1;k++)
				{
					for(int l=0;l<=1;l++)
					{
						if(check(a[i],k)&&check(b[i],l))
						{
							if(j-k+l>=0)
							suf[i][j]+=suf[i+1][j-k+l],suf[i][j]%=mod;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				ans=(ans+abs(j)*pre[i][2000+j]%mod*suf[i+1][2000-j]%mod)%mod;
			}
		}
		suf[n+1][2000]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=4000;j++)pre[i][j]=suf[i][j]=0;
		}
		print(ans);
		puts("");
	}
}