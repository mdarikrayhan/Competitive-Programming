// LUOGU_RID: 160086502
#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,tot=1,flow,maxflow,es[1001],a[1001],b[1001],g[1001],vis[301],dep[301],head[301],now[301],nex[30001],edge[30001],ver[30001];
queue <int> q;
void add(int u,int v,int w){
    ver[++tot]=v,edge[tot]=w,nex[tot]=head[u],head[u]=tot;
    ver[++tot]=u,edge[tot]=0,nex[tot]=head[v],head[v]=tot;
}
bool bfs(){
    memset(dep,0,sizeof(dep));
    while(q.size()) q.pop();
    q.push(s);
    dep[s]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=nex[i]){
            if(edge[i]&&!dep[ver[i]]){
                q.push(ver[i]);
                dep[ver[i]]=dep[x]+1;
                if(ver[i]==t) return true;
            }
        }
    }
    return false;
}
int dinic(int x,int flow){
    if(x==t) return flow;
    int rest=flow,k;
    for(int i=now[x];i&&rest;i=nex[i]){
        now[x]=i;
        if(edge[i]&&dep[ver[i]]==dep[x]+1){
            k=dinic(ver[i],min(edge[i],rest));
            if(!k) dep[ver[i]]=0;
            rest-=k;
            edge[i]-=k;
            edge[i^1]+=k;
        }
    }
    return flow-rest;
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=nex[i]) if(!vis[ver[i]]&&edge[i]) dfs(ver[i]);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i],&b[i],&g[i]);
		if(g[i]) add(a[i],b[i],1),add(b[i],a[i],1e6);
		else add(a[i],b[i],1e6);
	}
	while(bfs()){
		for(int i=1;i<=n;i++) now[i]=head[i];
		while(flow=dinic(s,1e6)) maxflow+=flow;
	}
	dfs(s);
	printf("%d\n",maxflow);
	for(int i=1;i<=n;i++) head[i]=maxflow=0,tot=1;
	add(t,s,1e6);
	s=0,t=n+1;
	for(int i=1;i<=m;i++){
		if(g[i]){
			add(a[i],b[i],(1e6-1));
			add(s,b[i],1);
			add(a[i],t,1);
			es[i]=tot-4;
		}
	}
	while(bfs()){
		for(int i=0;i<=n+1;i++) now[i]=head[i];
		while(flow=dinic(s,1e6)) maxflow+=flow;
	}
	for(int i=1;i<=m;i++){
		if(g[i]){
			if(vis[a[i]]!=vis[b[i]]) printf("%d %d\n",edge[es[i]]+1,edge[es[i]]+1);
			else printf("%d 1000000\n",edge[es[i]]+1);
		}
		else printf("0 1000000\n");
	}
	return 0;
}
