#include<bits/stdc++.h>
using namespace std;
namespace my_std
{
    typedef long long ll;
    const int inf=0x3f3f3f3f;
    #define fr(i,x,y) for(int i=(x);i<=(y);++i)
    #define pfr(i,x,y) for(int i=(x);i>=(y);--i)
    #define space putchar(' ')
    #define enter putchar('\n')
    inline int read()
    {
        int sum=0,f=1;char ch=0;
        while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
        while(isdigit(ch)) sum=sum*10+(ch^48),ch=getchar();
        return sum*f;
    }
    inline void write(int x)
    {
        if(x<0) putchar('-'),x=-x;
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    inline void writesp(int x){write(x),space;}
    inline void writeln(int x){write(x),enter;}
}
using namespace my_std;
const int N=1e5+50,mod=1e9+7;
int n,head[N],cnt,maxn,l[N],r[N],len[N],inv[N],mul=1,ans,pa[N],sz[N],son[N],top[N],dep[N],dfn[N],idx;
struct edge{int to,nxt;}e[N<<1];
inline void addedge(int u,int v){e[++cnt]=(edge){v,head[u]},head[u]=cnt;}
vector<int> vec1[N],vec2[N];
inline void add(int &a,int b){(a+=b)>mod?a-=mod:a;}
inline void sub(int &a,int b){(a-=b)<0?a+=mod:a;}
inline int subb(int a,int b){return (a-=b)<0?a+=mod:a;}
inline int ksmod(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=1ll*ans*a%mod;
        a=1ll*a*a%mod,b>>=1;
    }
    return ans;
}
struct Fenwick
{
    #define lowbit(x) (x&-x) 
    int t1[N],t2[N];
    inline void modify(int x,int dlt)
    {
        if(!x) return ;
        int cur=x;
        while(x<=n) add(t1[x],dlt),add(t2[x],1ll*cur*dlt%mod),x+=lowbit(x);
    }
    inline int query(int x)
    {
        if(!x) return 0;
        int ans1=0,ans2=0,cur=x;
        while(x) add(ans1,t1[x]),add(ans2,t2[x]),x-=lowbit(x);
        return ans1=1ll*ans1*(cur+1)%mod,sub(ans1,ans2),ans1;
    }
    inline void modify(int l,int r,int dlt){modify(l,dlt),modify(r+1,mod-dlt);}
    inline int query(int l,int r){return subb(query(r),query(l-1));}
}t;
void dfs1(int u,int fa)
{
    pa[u]=fa,dep[u]=dep[fa]+1,sz[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs1(v,u),sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int fa,int tp)
{
    top[u]=tp,dfn[u]=++idx;
    if(son[u]) dfs2(son[u],u,tp);
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,v);
    }
}
inline int query(int x)
{
    int ans=0;
    while(x) add(ans,t.query(dfn[top[x]],dfn[x])),x=pa[top[x]];
    return ans;
}
inline void modify(int x,int dlt){while(x)t.modify(dfn[top[x]],dfn[x],dlt),x=pa[top[x]];}
int main(void)
{
    n=read();int u,v;
    fr(i,1,n)
    {
        l[i]=read(),r[i]=read(),len[i]=r[i]-l[i]+1,inv[i]=ksmod(len[i],mod-2);
        vec1[l[i]].emplace_back(i),vec2[r[i]+1].emplace_back(i);
        mul=1ll*mul*len[i]%mod,maxn=max(maxn,r[i]);
    }
    fr(i,2,n) u=read(),v=read(),addedge(u,v),addedge(v,u);
    dfs1(1,0),dfs2(1,0,1);
    int sum1=0,sum2=0,sum3=0,sum4=0;
    fr(t,1,maxn)
    {
        int sz1=vec1[t].size(),sz2=vec2[t].size(),cur;
        fr(i,0,sz1-1)
        {
            cur=vec1[t][i],add(sum1,1ll*dep[cur]*inv[cur]%mod),add(sum2,inv[cur]);
            add(sum3,1ll*dep[cur]*inv[cur]%mod*inv[cur]%mod);
            add(sum4,1ll*query(cur)*inv[cur]%mod),modify(cur,inv[cur]);
        }
        fr(i,0,sz2-1)
        {
            cur=vec2[t][i],sub(sum1,1ll*dep[cur]*inv[cur]%mod),sub(sum2,inv[cur]);
            sub(sum3,1ll*dep[cur]*inv[cur]%mod*inv[cur]%mod);
            modify(cur,mod-inv[cur]),sub(sum4,1ll*query(cur)*inv[cur]%mod);
        }
        add(ans,1ll*mul*subb(subb(1ll*sum1*sum2%mod,sum3),2ll*sum4%mod)%mod);
    }
    return writeln(ans),0;
}