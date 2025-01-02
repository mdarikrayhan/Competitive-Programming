#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e7+5,M=755,inf=0x3f3f3f3f;
int n,S,T,idx,num=1,flow,maxflow;string str[M];bitset<M>g[M];
int fail[N],ance[N],tr[N][2],dis[M<<1],head[M<<1],Head[M<<1];
struct node{int to,next,flow;}edge[M*M];
bool bfs(){
	for (int i=1;i<=T;i++) dis[i]=-1,Head[i]=head[i];
	queue<int>q;q.push(T);dis[T]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x],y;i;i=edge[i].next)
			if (edge[i^1].flow&&!~dis[y=edge[i].to])
				dis[y]=dis[x]+1,q.push(y);
	}
	return ~dis[S];
}
int dfs(int x,int flow){
	if (x==T) return flow; int used=0,tmp;
	for (int &i=Head[x],y;i;i=edge[i].next){
		if (!edge[i].flow||dis[y=edge[i].to]+1!=dis[x]) continue;
		if (tmp=dfs(y,min(flow-used,edge[i].flow))){
			edge[i].flow-=tmp;edge[i^1].flow+=tmp;
			if ((used+=tmp)==flow) break;
		}
	}
	return used;
}
void insert(int x,string str){
	int len=str.length(),p=0;
	for (int i=0,ch;i<len;i++){
		if (!tr[p][ch=str[i]-'a']) tr[p][ch]=++idx;
		p=tr[p][ch];
	} ance[p]=x;
}
void build(){ queue<int>q;
	for (auto i:{0,1})
		if (tr[0][i]) q.push(tr[0][i]);
	while (!q.empty()){
		int x=q.front(),y;q.pop();
		if (ance[x]) g[ance[fail[x]]][ance[x]]=1;
		else ance[x]=ance[fail[x]];
		for (auto i:{0,1}){ int y=tr[x][i];
			if (y) fail[y]=tr[fail[x]][i],q.push(y);
			else tr[x][i]=tr[fail[x]][i];
		}
	}
	for (int i=1;i<=n;i++){
		int len=str[i].length(),p=0;
		for (int j=0;j<len;j++){
			p=tr[p][str[i][j]-'a'];
			if (ance[p]) g[ance[p]][i]=1;
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			if (g[i][k]) g[i]|=g[k];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;S=n<<1|1;T=S+1;
	auto addedge=[&](auto u,auto v,auto w){edge[++num]={v,head[u],w};head[u]=num;};
	auto link=[&](auto u,auto v){addedge(u,v,1);addedge(v,u,0);};
	for (int i=1;i<=n;i++) link(S,i),link(i+n,T);
	for (int i=1;i<=n;i++) cin>>str[i],insert(i,str[i]); build();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (g[i][j]&&i!=j) link(i,j+n);
	while (bfs()) while (flow=dfs(S,inf)) maxflow+=flow;
	printf("%d\n",n-maxflow);
	for (int i=1;i<=n;i++)
		if (!~dis[i]&&~dis[i+n])
			printf("%d ",i);
	return 0;
}