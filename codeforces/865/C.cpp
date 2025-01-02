// LUOGU_RID: 158745595
#include<bits/stdc++.h>
#define cint const int
#define iint inline int
#define ll long long
#define cll const long long
#define ill inline long long
#define ldb long double
using namespace std;
iint read()
{
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		num=(num<<1)+(num<<3)+(ch-'0');
		ch=getchar();
	}
	return num;
}
const ldb eps=0.000000001;
int n,m,a[51],b[51],p[51];
ldb dp[51][5005];
bool check(const ldb v)
{
	dp[n][0]=0;
	for(int i=n-1;i>=0;--i)
	{
		for(int j=m+1;j<=5002;++j)
		{
			dp[i+1][j]=v;
		}
		for(int j=0;j<=m;++j)
		{
			dp[i][j]=min(v,(dp[i+1][j+a[i+1]]+a[i+1])*p[i+1]/100+(dp[i+1][j+b[i+1]]+b[i+1])*(100-p[i+1])/100);
		}
	}
	return dp[0][0]<v;
}
ldb find(const ldb l,const ldb r)
{
	const ldb mid=(l+r)/2;
	if(r-l<=eps)return mid;
	if(check(mid))return find(l,mid);
	return find(mid,r);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=read();
		p[i]=read();
	}
	printf("%.9Lf",find(0,1e9));
	return 0;
}
