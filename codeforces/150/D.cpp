// LUOGU_RID: 159976273
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=155;
const int inf=5e16L;
int n,a[N],ans,dp[N][N][N],f[N][N],g[N];
int lzj[N],zeq,kong[N];
string s;
int check()
{
	for(int i=1;i<=zeq;i++)if(lzj[i]!=lzj[zeq-i+1])return 0;
	return 1;
}
void prepare()
{
	for(int l=1;l<=n;l++)
	{
		for(int r=1;r<=n;r++)
		{
			for(int k=0;k<=n+1;k++)
			{
				dp[l][r][k]=-inf;
				f[l][r]=-inf;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)kong[i]=a[i];
		else kong[i]=-inf;
		if(a[1]>=0)kong[i]=max(kong[i],a[1]+kong[i-1]);
		for(int j=i-2;j>=1;j-=2)if(a[j]>=0)kong[i]=max(kong[i],a[j]+kong[i-j]);
		// cout<<"kong: "<<i<<' '<<kong[i]<<'\n';
	}
}
void solve()
{
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			zeq=0;
			for(int k=l;k<=r;k++)lzj[++zeq]=s[k]-'a';
			if(check())
			{
				int flag=0;
				for(int kk=len;kk>=0;kk--)
				{
					flag^=1;
					// cout<<"sbsb: "<<l<<' '<<r<<' '<<kk<<' '<<kong[len-kk]<<' '<<kong[len-1-kk]<<'\n';
					if(flag)
					{
						if(kk==len)dp[l][r][kk]=0;
						else if(len%2==0)dp[l][r][kk]=kong[len-kk];
						else if(a[1]>=0)dp[l][r][kk]=kong[len-2-kk]+2*a[1];
					}
					else if(a[1]>=0)dp[l][r][kk]=a[1]+kong[len-1-kk];
				}
			}
			for(int kk=0;kk<=len;kk++)
			{
				for(int k=l;k<=r-1;k++)
				{
					if(f[l][k]!=-inf&&dp[k+1][r][kk]!=-inf)
					{
						dp[l][r][kk]=max(dp[l][r][kk],f[l][k]+dp[k+1][r][kk]);
						// cout<<"sbdyj: "<<l<<' '<<r<<' '<<kk<<' '<<k<<' '<<f[l][k]<<' '<<dp[k+1][r][kk]<<'\n';
					}
					if(f[k+1][r]!=-inf&&dp[l][k][kk]!=-inf)
					{
						dp[l][r][kk]=max(dp[l][r][kk],dp[l][k][kk]+f[k+1][r]);
						// cout<<"sblzj: "<<l<<' '<<r<<' '<<kk<<' '<<k<<' '<<f[k+1][r]<<' '<<dp[l][k][kk]<<'\n';
					}
				}
				// cout<<"syr: "<<l<<' '<<r<<' '<<kk<<' '<<dp[l][r][kk]<<'\n';
				if(s[l]==s[r]&&l+1<=r-1)
				{
					if(kk>0)
					{
						if(kk-2>=0)dp[l][r][kk]=max(dp[l][r][kk],dp[l+1][r-1][kk-2]);
					}
					else
					{
						for(int k=0;k<=(r-1)-(l+1)+1;k++)
						{
							if(dp[l+1][r-1][k]==-inf)continue;
							dp[l][r][0]=max(dp[l][r][0],dp[l+1][r-1][k]+kong[k+2]);
						}
					}
				}
				// cout<<"aminos; "<<l<<' '<<r<<' '<<kk<<' '<<dp[l][r][kk]<<'\n';
				// cout<<"---------------------\n";
				if(kong[kk]>=0)f[l][r]=max(f[l][r],dp[l][r][kk]+kong[kk]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		g[i]=g[i-1];
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<=i-j+1;k++)
			{
				if(dp[j][i][k]==-inf)continue;
				// if(dp[j][i][k]+max(0ll,kong[k]))cout<<"nmsl: "<<i<<' '<<j<<' '<<g[j-1]<<' '<<dp[j][i][k]+max(0ll,kong[k])<<'\n';
				g[i]=max(g[i],g[j-1]+dp[j][i][k]+max(0ll,kong[k]));
			}
		}
		// cout<<"wtf: "<<i<<' '<<g[i]<<'\n';
		// cout<<"----------------------\n";
	}
	ans=g[n];
}
signed main()
{
#ifdef LOCAL
	freopen("test.in", "r",stdin);
	freopen("test.out", "w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>s;
	s=' '+s;
	prepare();
	solve();
	cout<<ans<<'\n';
	return 0;
}
/*
dp[l][r][k]表示(l,r)区间删完之后只剩下长度为k的回文串
中间有断开不能继续匹配 g[i] DP区间隔开的情况
如果剩下的不是回文串一定会在某一个(L,R)中成为回文串的一部分因此不需要记录这种状态
*/