// LUOGU_RID: 160422794
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=2e5+10;
int a[maxn],lst[maxn];
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
int scc[maxn];
bool vis[maxn];
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
            scc[q[tp]]=cnt;
            vis[q[tp]]=0;
            --tp;
        }
        scc[q[tp]]=cnt;
        vis[q[tp]]=0;
        --tp;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int len=0;
    bool flag=0;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j=1;j<=num;j++){
            scanf("%d",&a[j]);
        }
        for(int j=1;j<=min(num,len);j++){
            if(a[j]<lst[j]){
                add(a[j],a[j]+m);
                add(lst[j]+m,lst[j]);
                break;
            }
            if(a[j]>lst[j]){
                add(a[j],lst[j]);
                add(lst[j]+m,a[j]+m);
                break;
            }
            if(j==min(num,len)&&len>num){
                flag=1;
            }
        }
        len=num;
        for(int j=1;j<=len;j++){
            lst[j]=a[j];
        }
    }
    if(flag){
        printf("No\n");
        return 0;
    }
    for(int i=1;i<=2*m;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(scc[i]==scc[i+m]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    int ans=0;
    for(int i=1;i<=m;i++){
        if(scc[i]<scc[i+m]){
            ans++;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=m;i++){
        if(scc[i]<scc[i+m]){
            printf("%d ",i);
        }
    }
    return 0;
}