#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define N 116
#define EPS 1e-20
#define eps 1e-2
using namespace std;
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9') c=getchar();
	while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();
	return sum;
}
bool op,used[N+1],vis[N+1];
long long n,q,v,b[N+1],r[N+1],K[N+1],cnt;
__float128 c[N+1],d[N+1],X[N+1],Y[N+1],Z[N+1],E[N+1][N+1],F[N+1][N+1];
vector<int>p1[N+1];
vector<int>p2[N+1];
__float128 abs(__float128 x)
{
	return (x>=0)?x:-x;
}
__float128 floor(__float128 x)
{
	return floor((long double)(x));
}
__float128 ceil(__float128 x)
{
	return ceil((long double)(x));
}
void Adder()
{
	__float128 rst;
	for (int i=1;i<=n-1;++i)
		if (abs(c[i])>EPS)
		{
			if (abs(E[i][i])<EPS)
			{
				for (int j=1;j<=n-1;++j) E[i][j]=c[j],F[i][j]=d[j];
				break;
			}
			else
			{
				rst=c[i]/E[i][i];
				for (int j=1;j<=n-1;++j) c[j]-=rst*E[i][j],d[j]-=rst*F[i][j];
			}
		}
	return;
}
void dfs(int x)
{
	if (x==v) return;
	used[x]=1;
	if ((K[x]+K[x+n-1])&1)
	{
		if (!used[r[x]]) dfs(r[x]);
		else if (r[x]!=v) op=0;
	}
	else
	{
		if (!used[b[x]]) dfs(b[x]);
		else if (b[x]!=v) op=0;
	}
	return;
}
int main()
{
	//freopen("transfer.in","r",stdin);
	//freopen("transfer.out","w",stdout);
	__float128 res;
	string s;
	n=read();
	for (int i=1;i<=n-1;++i) b[i]=read(),r[i]=read(),p1[b[i]].push_back(i),p2[r[i]].push_back(i);
	for (int i=1;i<=n-1;++i)
	{
		for (int j=1;j<=n-1;++j) c[j]=d[j]=0;
		for (int j=0;j<p1[i].size();++j) c[p1[i][j]]++;
		for (int j=0;j<p2[i].size();++j) c[p2[i][j]]++;
		c[i]-=2,d[i]=1;
		Adder();
	}
	q=read();
	while (q--)
	{
		v=read(),cin>>s;
		for (int i=1;i<=n-1;++i)
		{
			if (s[i-1]=='R') Y[i]=1+(i==v)-(i==1);
			else Y[i]=(i==v)-(i==1);
		}
		for (int i=1;i<=n-1;++i)
			for (int j=0;j<p2[i].size();++j)
				Y[i]-=(s[p2[i][j]-1]=='R');
		for (int i=1;i<=n-1;++i)
		{
			Z[i]=0;
			for (int j=1;j<=n-1;++j) Z[i]+=Y[j]*F[i][j];
		}
		for (int i=n-1;i>=1;--i)
		{
			res=Z[i];
			for (int j=i+1;j<=n-1;++j) res-=X[j]*E[i][j];
			X[i]=res/E[i][i];
		}
		op=1,cnt=0;
		for (int i=1;i<=n-1;++i) X[i+n-1]=X[i]+(s[i-1]=='R');
		for (int i=1;i<=2*n-2;++i) op&=(X[i]+eps>=0&&(abs(X[i]-floor(X[i]))<eps||abs(X[i]-ceil(X[i]))<eps)),K[i]=(long long)(X[i]+eps),cnt+=K[i];
		for (int i=1;i<=n;++i) vis[i]=0;
		for (int i=1;i<=n-1;++i)
		{
			if (K[i]) vis[i]=vis[b[i]]=1;
			if (K[i+n-1]) vis[i]=vis[r[i]]=1;
		}
		for (int i=1;i<=n;++i)
			if (vis[i])
			{
				for (int j=1;j<=n;++j) used[j]=0;
				dfs(i);
			}
		printf("%lld\n",op?cnt:-1);
	}
	return 0;
}