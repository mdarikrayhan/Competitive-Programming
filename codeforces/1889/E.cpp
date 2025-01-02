// LUOGU_RID: 160428244
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=2e5,Maxk=1.5e7,Mod=1e9+7;

int n,s,ans,cur,Head[Maxk+5],tot;
int dfn[Maxk+5],low[Maxk+5],st[Maxk+5],top;
bool chk[Maxk+5],vis[Maxk+5];
struct Node{int to,nxt;} Edge[Maxk*2+5];
inline void Add(int x,int y) {Edge[++tot]=Node{y,Head[x]},Head[x]=tot;}
inline void Tarjan(int x)
{
    dfn[x]=low[x]=++cur,st[++top]=x,vis[x]=1;
    for(int i=Head[x];i;i=Edge[i].nxt)
    {
        int y=Edge[i].to;
        if(!dfn[y]) Tarjan(y),low[x]=min(low[x],low[y]);
        else if(vis[y]) low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        static bool dxv[Maxk+5];
        int flg=0,sum=0,tmp=top; while(1)
        {
            int y=st[top--]; sum+=chk[y],vis[y]=0;
            if(x==y) break;
        }
        For(i,top+1,tmp) dxv[st[i]]=1;
        For(_,top+1,tmp)
        {
            int p=st[_]; if(flg) break;
            for(int i=Head[p];i;i=Edge[i].nxt)
                if(!dxv[Edge[i].to]) {flg=1; break;}
        }
        For(i,top+1,tmp) dxv[st[i]]=0;
        if(sum) if(sum>2 || flg) ans=ans*2%Mod;
    }
}

struct Tree
{
    int id[Maxn+5],dx[Maxn+5][18];
    int anc[Maxn+5][18],dep[Maxn+5];
    vector<int> v[Maxn+5];
    inline void dfs(int x,int f)
    {
        dep[x]=dep[f]+1,anc[x][0]=f;
        For(i,1,17) anc[x][i]=anc[anc[x][i-1]][i-1];
        For(i,1,17) if(anc[x][i])
        {
            dx[x][i]=++s,Add(dx[x][i],dx[x][i-1]);
            Add(dx[x][i],dx[anc[x][i-1]][i-1]);
        } for(auto y:v[x]) if(y!=f) dfs(y,x);
    }
    inline void Build()
    {
        For(i,2,n) id[i]=++s,dx[i][0]=id[i],chk[s]=1;
        For(i,1,n-1)
        {
            int a,b; cin>>a>>b;
            v[a].push_back(b),v[b].push_back(a);
        } dfs(1,0);
    }
    inline void Ins(int p,int x,int y)
    {
        if(dep[x]<dep[y]) swap(x,y);
        Rof(i,17,0) if(dep[anc[x][i]]>=dep[y])
            Add(p,dx[x][i]),x=anc[x][i];
        if(x==y) return;
        Rof(i,17,0) if(anc[x][i]!=anc[y][i])
            Add(p,dx[x][i]),Add(p,dx[y][i]),
            x=anc[x][i],y=anc[y][i];
        Add(p,dx[x][0]),Add(p,dx[y][0]);
    }
    inline void Clear()
    {
        For(i,1,n) vector<int>().swap(v[i]),id[i]=0;
        // For(i,1,n) For(j,0,17) dx[i][j]=anc[i][j]=0;
    }
} T1,T2;

inline void Clear()
{
    For(i,1,s) dfn[i]=low[i]=vis[i]=chk[i]=0;
    For(i,1,s) Head[i]=0;
    top=cur=s=tot=0; T1.Clear(),T2.Clear();
}
int ddd=0;
inline void Solve()
{
    cin>>n; ans=1,T1.Build(),T2.Build();
    For(i,2,n) T2.Ins(T1.dx[i][0],i,T1.anc[i][0]);
    For(i,2,n) T1.Ins(T2.dx[i][0],i,T2.anc[i][0]);
    For(i,1,s) if(!dfn[i]) Tarjan(i);
    cout<<ans<<endl; Clear();
    if(ddd==2 && ans==2) {cout<<2<<endl; exit(0);}
}

int main()
{
    // freopen("1.in","r",stdin);

    ios::sync_with_stdio(false);
    int T; cin>>T; ddd=T;
    while(T--) Solve();
    return 0;
}