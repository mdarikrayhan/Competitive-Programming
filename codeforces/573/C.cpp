// LUOGU_RID: 160096117
// LUOGU_RID: 160092032
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
int n,deg[N],s;
vector<int>to[N];
int vis[N],flag=1;
int dep[N],vis2[N];
void dfs(int u,int fa)
{
    int cnt=0;
    if(vis[u]==1)vis2[u]=1;
    if(vis[u]==2)dep[u]=1;
    for(int v:to[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        if(dep[v]>1||vis2[v])cnt++;
        vis2[u]|=vis2[v];
        if(dep[v])dep[u]=max(dep[u],dep[v]+1);
    }
    if((fa&&cnt>1)||(!fa&&cnt>2))flag=0;
}
void dfs2(int u,int fa)
{
    if(vis[u]==2)s=(fa?fa:u);
    for(int v:to[u])
    {
        if(v==fa)continue;
        dfs2(v,u);
    }
}
int main()
{
    scanf("%d",&n);
    // bool flag2=0;
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        // if(i==1&&a==65456)flag2=1;
        to[a].push_back(b);
        to[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    for(int i=1;i<=n;i++)
        if(deg[i]>=4)vis[i]=1,s=i;
        else if(deg[i]==3)vis[i]=2;
    if(!s)dfs2(1,0);
    // if(flag2)cout<<s<<" ";
    if(s)dfs(s,0);
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
}