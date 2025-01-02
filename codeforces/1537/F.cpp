#include<bits/stdc++.h>
using namespace std;
const int M=2e6+100;
vector<int> e[M];//建图 
typedef long long ll;
long long col[M],a[M],b[M],n,m;
long long sum=0;
bool dfs(int u,int c)
{
	col[u]=c;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(!col[v])
		{
			if(dfs(v,3-c)) return 1;
		}
		else if(col[v]==c) return 1;
	}
	return 0;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>m;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			col[i]=0;
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			a[i]-=b[i];
			sum+=a[i];
		}
		int u,v;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(sum%2==1||sum%2==-1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int flag=0;
		if(dfs(1,1)) flag++;
		if(flag) 
		{
			cout<<"YES"<<endl;
			continue;
		}
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(col[i]==1) sum+=a[i];
			else sum-=a[i];
		}
		if(sum==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}