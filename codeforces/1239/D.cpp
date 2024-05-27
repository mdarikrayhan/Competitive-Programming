// LUOGU_RID: 160026471
#include<bits/stdc++.h>
using namespace std;
int T,n,m;
const int maxn=1e6+10;
struct node{
    int to,nxt;
};
node e[maxn];
int head[maxn],tot;
void add(int u,int v){
    ++tot;
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}
int dfn[maxn],low[maxn],q[maxn];
bool vis[maxn];
int sz[maxn],scc[maxn];
int res,tp,cnt;
void tarjan(int u){
    dfn[u]=low[u]=++res;
    q[++tp]=u;
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++cnt;
        while(q[tp]!=u){
            sz[cnt]++;
            scc[q[tp]]=cnt;
            vis[q[tp]]=0;
            --tp;
        }
        sz[cnt]++;
        scc[q[tp]]=cnt;
        vis[q[tp]]=0;
        --tp;
    }
}
void clear(){
    for(int i=1;i<=n;i++){
        head[i]=dfn[i]=sz[i]=0;
    }
    tot=res=tp=cnt=0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            if(u==v){
                continue;
            }
            add(u,v);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        if(cnt==1){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        printf("%d %d\n",sz[1],n-sz[1]);
        for(int i=1;i<=n;i++){
            if(scc[i]==1){
                printf("%d ",i);
            }
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            if(scc[i]!=1){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}