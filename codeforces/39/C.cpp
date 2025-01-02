#include<bits/stdc++.h>
using namespace std;
int n,c,r,x[4010],y[4010],d[5000],g[4010][4010],f[4010][4010],s[4010][4010],t;
vector<int>b[5000];
int dp(int l,int r)
{
	if(l>r)
	  return 0;
	if(f[l][r]!=-1)
	  return f[l][r];
	f[l][r]=dp(l+1,r);
	for(int k=0;k<b[l].size();++k)
	  if(y[b[l][k]]<r&&dp(l,y[b[l][k]])+dp(y[b[l][k]],r)>f[l][r])
		f[l][r]=f[l][y[b[l][k]]]+f[y[b[l][k]]][r],s[l][r]=y[b[l][k]];
	f[l][r]+=!!g[l][r];
	return f[l][r];
}
void dfs(int l,int r)
{
	if(l>r)
	  return;
	if(s[l][r])
	  dfs(l,s[l][r]),dfs(s[l][r],r);else
	  dfs(l+1,r);
	if(g[l][r])
	  cout<<g[l][r]<<' '; 
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>c>>r;
		x[i]=c-r;
		y[i]=c+r;
		d[i]=x[i];
		d[i+n]=y[i];
	}
	sort(d,d+n*2);
	t=unique(d,d+n*2)-d;
	for(int i=0;i<n;++i)
	{
		x[i]=upper_bound(d,d+t,x[i])-d;
		y[i]=upper_bound(d,d+t,y[i])-d;
		b[x[i]].push_back(i);
		g[x[i]][y[i]]=i+1;
	}
	memset(f,-1,sizeof(f));
	cout<<dp(1,t)<<'\n';
	dfs(1,t);
	return 0;
}