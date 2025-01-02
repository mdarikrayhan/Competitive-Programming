// LUOGU_RID: 160031038
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>p;
const int N=1e6+10;
int T,n,a[N];
bool f[N];
struct node{
	int pre;
	p nw;
};
vector<node>v[N];
void dfs(node x,int nw)
{
	if(nw==0)
	return;
	node y=v[nw-1][x.pre];
	if(x.nw.first!=y.nw.first)
	a[nw]=x.nw.first;
	else
	a[nw]=x.nw.second;
	dfs(y,nw-1);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<=n;i++)
		{
			v[i].clear();
		}
		v[0].push_back(node{-1,make_pair(INT_MIN,INT_MIN)});
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v[i-1].size();j++)
			{
				node x=v[i-1][j];
				if(-a[i]>x.nw.first)
				v[i].push_back(node{j,make_pair(-a[i],x.nw.second)});
				if(-a[i]>x.nw.second)
				v[i].push_back(node{j,make_pair(x.nw.first,-a[i])});
				if(a[i]>x.nw.first)
				v[i].push_back(node{j,make_pair(a[i],x.nw.second)});
				if(a[i]>x.nw.second)
				v[i].push_back(node{j,make_pair(x.nw.first,a[i])});
			}
			for(int j=0;j<v[i].size();j++)
			{
				f[j]=0;	
			}	
			for(int j=0;j<v[i].size();j++)
			{
				for(int k=0;k<v[i].size();k++)
				{
					if(j==k)
					continue;
					node x,y;
					x=v[i][j],y=v[i][k];
					if(x.nw.first>x.nw.second)
					swap(x.nw.first,x.nw.second);
					if(y.nw.first>y.nw.second)
					swap(y.nw.first,y.nw.second);
					if(x.nw.first==y.nw.first&&x.nw.second==y.nw.second)
					f[min(j,k)]=1;
					else if(x.nw.first<=y.nw.first&&x.nw.second<=y.nw.second)
					f[k]=1;
				}
			}
			vector<node>us;
			for(int j=0;j<v[i].size();j++)
			{
				if(f[j]==0)
				us.push_back(v[i][j]);
			}
//			for(int j=0;j<us.size();j++)
//			{
//				cout<<us[j].nw.first<<" "<<us[j].nw.second<<'\n';
//			}
			assert(us.size()<=2);
			v[i]=us;
		}		
		if(v[n].size()==0)
		{
			cout<<"NO"<<'\n';
		}
		else
		{
			cout<<"YES"<<'\n';
			dfs(v[n][0],n);
			for(int j=1;j<=n;j++)
			{
				cout<<a[j]<<" ";
			}
			cout<<'\n';
		}
	}
	return 0;
} 