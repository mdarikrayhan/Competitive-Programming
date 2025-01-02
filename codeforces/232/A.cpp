// Problem: Cycles
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF232A
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(ll n,ll m)
{
	if(m==2) return n*(n-1)/2;
	if(m==3) return n*(n-1)*(n-2)/6;
}
ll n=1,m;
ll g[105][105];
int main()
{
	cin>>m;
	while(C(n,3)<=m)
	{
		++n;
	}
	--n;
	for(ll i=1;i<=n;++i)
	{
		for(ll j=1;j<i;++j)
		{
			g[i][j]=g[j][i]=1;
		}
	}
	m-=C(n,3);
	for(ll i=n-1;i>1;--i)
	{
		while(m>=C(i,2))
		{
			++n;
			for(ll j=1;j<=i;++j)
			{
				g[j][n]=g[n][j]=1;
			}
			m-=C(i,2);
		}
	}
	cout<<n<<endl;
	for(ll i=1;i<=n;++i)
	{
		for(ll j=1;j<=n;++j)
		{
			cout<<g[i][j];
		}
		cout<<endl;
	}
	return 0;
}
		       	 		   		   		   	  		