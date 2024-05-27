// LUOGU_RID: 159327057
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pp;
const int N=310;
int n,m,p,a[N][N],dis[N][N],d[N][N],dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},edx,edy;
struct node{
	pp x;
	int dis;
};
vector<pp>v[N*N];
vector<node>us;
bool cmp(node x,node y)
{
	return x.dis<y.dis;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,63,sizeof(dis));
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			v[a[i][j]].push_back(make_pair(i,j));	
			if(a[i][j]==1)
			{
				dis[i][j]=i+j-2;
			}
			if(a[i][j]==p)
			edx=i,edy=j;
		}
	}
	for(int i=1;i<=p;i++)
	{
		if(v[i].size()*v[i-1].size()<=n*m)
		{
			for(int j=0;j<v[i-1].size();j++)
			{
				pp x=v[i-1][j];
				for(int k=0;k<v[i].size();k++)
				{
					pp y=v[i][k];
					dis[y.first][y.second]=min(dis[y.first][y.second],dis[x.first][x.second]+abs(x.first-y.first)+abs(x.second-y.second));
				}
			}
		}
		else
		{
			us.clear();
			for(int j=0;j<v[i-1].size();j++)
			{
				pp x=v[i-1][j];
				us.push_back(node{x,dis[x.first][x.second]});
			}
			sort(us.begin(),us.end(),cmp);
			int z=0;
			queue<pp>q;
			memset(d,63,sizeof(d));
			d[us[0].x.first][us[0].x.second]=us[0].dis;
			q.push(us[0].x);
			while(!q.empty())
			{
				pp x=q.front();
				q.pop();
				while(z+1!=us.size()&&us[z+1].dis==d[x.first][x.second])
				{
					d[us[z+1].x.first][us[z+1].x.second]=us[z+1].dis;
					q.push(us[++z].x);
				}
				for(int j=1;j<=4;j++)
				{
					int nx=x.first+dx[j],ny=x.second+dy[j];
					if(nx<1||nx>n||ny<1||ny>m||d[nx][ny]!=d[0][0])
					continue;
					d[nx][ny]=d[x.first][x.second]+1;
					q.push(make_pair(nx,ny));
				}
			}
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=m;k++)
				{
					if(a[j][k]==i)
					{
						dis[j][k]=d[j][k];
					}
				}
			}
		}
	}
	cout<<dis[edx][edy]<<'\n';
	return 0;
} 