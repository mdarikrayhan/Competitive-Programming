#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,t,s,a[200001];
long long vis[200001],f[200001];
map<long long,long long>m[200001],p;
struct node{
	long long sum;
	long long id;
}x[200001];
void dfs(int i,int tip)
{
	for(int j=1;j<=p[i];j++)
	{
		if(f[m[i][j]]==0)
		{
			f[m[i][j]]=1;
			dfs(m[i][j],tip+1);
			x[m[i][j]].sum=tip+1;
			a[i]+=a[m[i][j]];
		}
	}
	a[i]++;
} 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>l>>r;
		p[l]++;
		p[r]++;
		m[l][p[l]]=r;
		m[r][p[r]]=l;
	}
	f[1]=1;
	dfs(1,0);
	f[1]=0;
	x[1].sum=0;
	for(int i=1;i<=n;i++)
	{
		x[i].id=i;
		vis[i]=x[i].sum;
	}
	s=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]+=1-a[i];
		//cout<<vis[i]<<" ";
	}
	sort(vis+1,vis+1+n);
	for(int i=n;i>=n-k+1;i--)
	{
		s+=vis[i];
	}
	cout<<s<<endl;
}
  	  	   	  	 	  				     				