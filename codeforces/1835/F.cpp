// LUOGU_RID: 160625943
#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int,int>
#define mkp make_pair
#define fr first
#define sc second
const int N=1001, M=2005;

int n,m; vector<int> E[N];

struct edge {int nex,to,f;} a[M*M];
int h[M],tot=1,S=0,T=M-1;
void add(int x,int y,int f)
{
    a[++tot]=(edge){h[x],y,f}, h[x]=tot;
    a[++tot]=(edge){h[y],x,0}, h[y]=tot;
}
int dep[M];
bool bfs()
{
    memset(dep,0,sizeof dep); dep[S]=1;
    queue<int> q; q.push(S);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=h[u];i;i=a[i].nex)
        {
            int v=a[i].to;
            if(!dep[v] && a[i].f)
                dep[v]=dep[u]+1, q.push(v);
        }
    } return dep[T];
}
int cur[M],mflow;
int dfs(int u,int flow)
{
    if(u==T) return flow;
    int used=0;
    for(int &i=cur[u];i;i=a[i].nex)
    {
        int v=a[i].to;
        if(dep[v]==dep[u]+1 && a[i].f)
        {
            int pla = dfs(v, min(flow-used,a[i].f));
            a[i].f-=pla, a[i^1].f+=pla, used+=pla;
            if(used==flow) break;
        }
    }
    if(!used) dep[u]=0;
    return used;
}

int mch[M],vis[N],bj[N];
bitset<N> A[N],B[N],C[N];
vector<pii> Ans;
void add(int x,int y) {Ans.pb(mkp(x,y+n));}

int dfn[N],low[N],ti,st[N],tp,in[N],col[N],Col,rep[N];
void tarjan(int u)
{
    dfn[u]=low[u]=++ti, st[++tp]=u, in[u]=1;
    for(int v=1;v<=n;++v) if(A[u][v])
    {
        if(!dfn[v]) tarjan(v), low[u]=min(low[u],low[v]);
        else if(in[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int x, lst=u;
        rep[++Col]=u;
        do
        {
            x=st[tp--], in[x]=0, col[x]=Col;
            if(lst!=x) add(lst,x);
            lst=x;
        } while(x!=u);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1,x,y;i<=m;++i)
        scanf("%d %d",&x,&y), add(x,y,1), E[x].pb(y);
    for(int i=1;i<=n;++i) add(S,i,1), add(i+n,T,1);
    while(bfs())
        memcpy(cur,h,sizeof cur), mflow+=dfs(S,N);
    for(int u=1;u<=n;++u)
    for(int i=h[u];i;i=a[i].nex)
    {
        int v=a[i].to;
        if(v>n && v<=n*2 && !a[i].f) mch[v]=u, bj[u]=1;
    }
    if(mflow<n)
    {
        puts("NO");
        for(int s=1;s<=n;++s) if(!bj[s])
        {
            queue<int> q; q.push(s);
            vector<int> Ans;
            while(!q.empty())
            {
                int u=q.front(); q.pop();
                Ans.pb(u);
                for(int v:E[u]) if(!vis[mch[v]])
                    vis[mch[v]]=1, q.push(mch[v]);
            }
            printf("%d\n",(int)Ans.size());
            for(int x:Ans) printf("%d ",x); putchar('\n');
            break;
        }
        exit(0);
    }
    puts("YES");
    for(int u=1;u<=n;++u)
    for(int v:E[u]) if(mch[v]!=u) A[u][mch[v]]=1;
    for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i) if(A[i][k]) A[i]|=A[k];
    
    for(int i=1;i<=n;++i) A[i][i]=0;

    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);

    for(int u=1;u<=n;++u)
    for(int v=1;v<=n;++v) if(col[u]!=col[v] && A[u][v])
        B[col[u]][col[v]] = C[col[v]][col[u]]=1;
    for(int u=1;u<=Col;++u)
    for(int v=1;v<=Col;++v) if(B[u][v] && (B[u]&C[v]).none()) add(rep[u], rep[v]);
    for(int i=1;i<=n;++i) add(i,i);
    printf("%d\n",(int)Ans.size());
    for(auto p:Ans) printf("%d %d\n",p.fr,p.sc);
}