// LUOGU_RID: 160012178
#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
const int maxn=2e4+10;
const int maxm=4e4+10;
const int inf=0x3f3f3f3f;
int S[maxn],a[maxn];
int u1[maxn],v1[maxn];
struct node{
    int to,nxt,w;
};
node e[maxm<<1];
int head[maxn],tot=1;
void add(int u,int v,int w){
    ++tot;
    e[tot].to=v;
    e[tot].nxt=head[u];
    e[tot].w=w;
    head[u]=tot;
}
int dis[maxn],step[maxn];
bool bfs(){
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].w&&dis[v]==inf){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int u,int sum){
    if(u==t){
        return sum;
    }
    int res=0,k;
    for(int &i=step[u];i!=0;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].w&&dis[v]==dis[u]+1){
            k=dfs(v,min(e[i].w,sum));
            e[i].w-=k;
            e[i^1].w+=k;
            res+=k;
            sum-=k;
            if(!sum){
                break;
            }
        }
    }
    return res;
}
int dinic(){
    int ans=0;
    while(bfs()){
        memcpy(step,head,sizeof(step));
        ans+=dfs(s,inf);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    s=0;
    t=n+m+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&S[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u1[i],&v1[i]);
        a[u1[i]]++;
        a[v1[i]]++;
        add(s,i,1),add(i,s,0);
        add(i,u1[i]+m,1),add(u1[i]+m,i,0);
        add(i,v1[i]+m,1),add(v1[i]+m,i,0);
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(!S[i]){
            continue;
        }
        if(a[i]<0||a[i]&1){
            printf("NO\n");
            return 0;
        }
        a[i]>>=1;
        add(i+m,t,a[i]),add(t,i+m,0);
        num+=a[i];
    }
    int ans=dinic();
    if(ans<num){
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!S[i]){
            add(i+m,t,inf),add(t,i+m,0);
        }
    }
    ans=dinic();
    if(ans+num<m){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=m;i++){
        for(int j=head[i];j!=0;j=e[j].nxt){
            int v=e[j].to;
            if(v!=s&&!e[j].w){
                if(v-m==u1[i]){
                    printf("%d %d\n",v1[i],u1[i]);
                }
                else{
                    printf("%d %d\n",u1[i],v1[i]);
                }
            }
        }
    }
    return 0;
}