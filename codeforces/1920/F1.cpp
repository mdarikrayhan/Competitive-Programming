// LUOGU_RID: 160070739
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=6e5+5;
int n,m,q,f[N],ans[N];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
vector<char>ch[N];
vector<int>dis[N];
struct Node{int x,y,z;};
vector<Node>cur;
set<int>S[N];
inline bool check(int a,int b){return a>0&&a<=n&&b>0&&b<=m;}
inline int id(int x,int y,int z){return z*n*m+(x-1)*m+y;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y,int z){
	if((x=find(x))==(y=find(y))) return;
	if(S[x].size()<S[y].size()) swap(x,y);
	for(auto id:S[y]){
		if(S[x].count(id)) ans[id]=z,S[x].erase(id);
		else S[x].insert(id);
	}
	f[y]=x,S[y].clear();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	int kx=0,ky=0;
	for(int i=1;i<=n;++i)
		ch[i].resize(m+1),dis[i].resize(m+1),
		fill(dis[i].begin(),dis[i].end(),1e9);
	queue<pair<int,int>>Q;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>ch[i][j];
			if(ch[i][j]=='v') dis[i][j]=0,Q.push({i,j});
			else if(ch[i][j]=='#') kx=i,ky=j;
		}
	for(int i=1,x,y;i<=q;++i)
		cin>>x>>y,S[id(x,y,1)].insert(i),S[id(x,y,0)].insert(i);
	while(Q.size()){
		pair<int,int>x=Q.front();Q.pop();
		for(int i=0;i<4;++i){
			int xx=x.fi+dx[i],yy=x.se+dy[i];
			if(check(xx,yy)&&dis[xx][yy]>dis[x.fi][x.se]+1)
				dis[xx][yy]=dis[x.fi][x.se]+1,Q.push({xx,yy});
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=0;k<=1;++k){
				int x=i+dx[k],y=j+dy[k];
				f[id(i,j,k)]=id(i,j,k);
				if(!check(x,y)||ch[x][y]=='#'||ch[i][j]=='#') continue;
				int op=i==kx&&x==kx-1&&y>ky,val=min(dis[i][j],dis[x][y]);
				cur.pb({id(i,j,0),id(x,y,op),val}),cur.pb({id(i,j,1),id(x,y,!op),val});
			}
	sort(cur.begin(),cur.end(),[&](Node a,Node b){return a.z>b.z;});
	for(auto v:cur) merge(v.x,v.y,v.z);
	for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
}