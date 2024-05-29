// LUOGU_RID: 156884962
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int n,m,d,cnt,pf[maxn][maxn],tim,use[maxn][maxn],dis[maxn][maxn];
char a[maxn][maxn];
bitset<300> vis,vis2;
vector<pair<int,int> > R;
queue<pair<int,int> > q;
void bfs(int x,int y)
{
	vis.reset(),tim++;
	q.push(make_pair(x,y)),use[x][y]=1,dis[x][y]=0;
	while(!q.empty())
	{
		pair<int,int> now=q.front();
		if(a[now.first][now.second]=='R') vis.set(pf[now.first][now.second]);
		q.pop();
		if(dis[now.first][now.second]<d)
		{
			for(int i=0;i<4;i++)
			{
				int nx=now.first+dx[i],ny=now.second+dy[i];
				if(a[nx][ny]!='X'&&use[nx][ny]<tim) use[nx][ny]=tim,dis[nx][ny]=dis[now.first][now.second]+1,q.push(make_pair(nx,ny));
			}
		}
	}
}
void ck(int ax,int ay)
{
	bfs(ax,ay),vis2=vis;
	if(int(vis.count())==cnt)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]!='X'&&(i!=ax||j!=ay)) printf("%d %d %d %d",ax,ay,i,j),exit(0);
		printf("-1"),exit(0);
	}
	for(int i=1;i<cnt;i++)
	{
		if(vis2[i]) continue;
		for(int x=max(1,R[i].first-d);x<=n&&x<=R[i].first+d;x++)
		{
			for(int y=max(1,R[i].second-d);y<=m&&y<=R[i].second+d;y++)
			{
				if(abs(x-R[i].first)+abs(y-R[i].second)>d||a[x][y]=='X') continue;
				bfs(x,y),vis|=vis2;
				if(int(vis.count())==cnt) printf("%d %d %d %d",ax,ay,x,y),exit(0);
			}
		}
		return;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++) scanf("%s",&a[i][1]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]=='R') R.push_back(make_pair(i,j)),pf[i][j]=cnt++;
	if(cnt>4*d*(d+1)+2)
	{
		printf("-1");
		return 0;
	}
	if(!cnt)
	{
		for(int i=1;i<=n&&R.size()<2;i++) for(int j=1;j<=m&&R.size()<2;j++) if(a[i][j]=='.') R.push_back(make_pair(i,j));
		if(R.size()==2) printf("%d %d %d %d",R[0].first,R[0].second,R[1].first,R[1].second);
		else printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(abs(i-R[0].first)+abs(j-R[0].second)<=d&&a[i][j]!='X') ck(i,j);
	printf("-1");
	return 0;
}