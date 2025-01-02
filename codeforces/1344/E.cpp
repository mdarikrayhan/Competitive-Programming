// LUOGU_RID: 160545921
#include<bits/stdc++.h>
#define il inline
using namespace std;
il int read()
{
    int xr=0,F=1; char cr;
    while(cr=getchar(),cr<'0'||cr>'9') if(cr=='-') F=-1;
    while(cr>='0'&&cr<='9') 
        xr=(xr<<3)+(xr<<1)+(cr^48),cr=getchar();
    return xr*F;
}
#define int long long
const int N=1e5+5,inf=1e18;
int n,m;
struct edge{int v,w;};
vector<edge> e[N];
int dep[N];
struct node
{
    int key,fa,lz;
    int s[2];
    node() {key=fa=lz=s[0]=s[1]=0;}
}tr[N];
void init(int u,int fa)
{
    tr[u].fa=fa;
    for(auto [v,w]:e[u]) if(v^fa)
    {
        dep[v]=dep[u]+w;
        init(v,u);
    }
}
#define pir pair<int,int>
#define fi first
#define se second
vector<pir> Q;
pir a[N];
struct lctqwq
{
    #define ls(x) tr[(x)].s[0]
    #define rs(x) tr[(x)].s[1]
    #define fa(x) tr[(x)].fa
    il bool get(int x) {return rs(fa(x))==x;}
    il bool isroot(int x) {return ls(fa(x))!=x&&rs(fa(x))!=x;}
    il void pushdown(int x)
    {
        if(!tr[x].lz) return;
        tr[ls(x)].lz=tr[rs(x)].lz=tr[x].lz;
        tr[ls(x)].key=tr[rs(x)].key=tr[x].lz;
        tr[x].lz=0;
    }
    il void update(int x)
    {
        if(!isroot(x)) update(fa(x));
        pushdown(x);
    }
    il void rotate(int x)
    {
        int y=fa(x),z=fa(y),c=get(x);
        if(!isroot(y)) tr[z].s[get(y)]=x;
        fa(tr[x].s[c^1])=y,tr[y].s[c]=tr[x].s[c^1],tr[x].s[c^1]=y;
        fa(y)=x,fa(x)=z;
    }
    il void splay(int x)
    {
        update(x);
        for(int f=fa(x);f=fa(x),!isroot(x);rotate(x))
            if(!isroot(f)) rotate(get(f)==get(x)?f:x);
    }
    il void access(int x,int tim)
    {
        // cout<<"access "<<x<<" "<<tim<<endl;
        int qwq=x;
        for(int p=0;x;p=x,x=fa(x))
        { 
            splay(x);
            if(p)
            {
                // cout<<"qwq"<<" "<<x<<" "<<p<<endl;
                rs(x)=p;
                if(!tr[x].key) Q.push_back(pir(1,tim+dep[x]));
                else Q.push_back(pir(tr[x].key+dep[x]+1,tim+dep[x]));
            }
        }
        splay(qwq);
        if(ls(qwq)) tr[ls(qwq)].key=tr[ls(qwq)].lz=tim;
    }
}lct;
signed main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w}),e[v].push_back({u,w});
    }
    init(1,0);
    for(int i=1;i<=n;i++) if(e[i].size())
    {
        int v=e[i].back().v;
        if(v==fa(i)&&e[i].size()>1) v=e[i][e[i].size()-2].v;
        // cout<<"? "<<i<<" "<<v<<endl;
        if(v!=fa(i)) 
        {
            // cout<<"edge "<<i<<" "<<v<<endl;
            rs(i)=v;
        }
    }
    for(int i=1;i<=m;i++) a[i].se=read(),a[i].fi=read();
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++) lct.access(a[i].se,a[i].fi);
    sort(Q.begin(),Q.end());
    priority_queue<int,vector<int>,greater<int> >nw;
    vector<int> ans;
    int t=0,cnt=0;
    for(int i=0;i<Q.size();i++)
    {
        int l=Q[i].fi,r=Q[i].se; int nl=(i+1==Q.size())?inf:Q[i+1].fi;
        // cout<<"QWQ "<<l<<" "<<r<<endl;
        nw.push(r);
        t=l;
        while(!nw.empty()&&t<nl)
        {
            if(nw.top()<t) {
                for(auto x:ans) if(x>=nw.top()) cnt--;
                printf("%lld %lld\n",nw.top(),cnt);return 0;}
            ans.push_back(nw.top()),nw.pop(),cnt++,t++;
        }
    }
    printf("-1 %lld\n",cnt);
    return 0;
}