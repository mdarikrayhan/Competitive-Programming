// LUOGU_RID: 160291371
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define sort stable_sort 
#define endl '\n'
struct node
{
    ll nxt,to;
}e[200010];
ll head[200010],c[200010],cc[200010],siz[200010],fa[200010],dep[200010],son[200010],top[200010],dfn[200010],out[200010],cnt=0,tot=0;
struct SegmentTree
{
    ll l,r,sum,lazy;
}tree[800010];
ll lson(ll x)
{
    return x*2;   
}
ll rson(ll x)
{
    return x*2+1;
}
void pushup(ll rt)
{
    tree[rt].sum=tree[lson(rt)].sum+tree[rson(rt)].sum;
}
void build(ll rt,ll l,ll r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].sum=cc[l];
        tree[rt].lazy=0;
        return;
    }
    int mid=(l+r)/2;
    build(lson(rt),l,mid);
    build(rson(rt),mid+1,r);
    pushup(rt);
}
void pushdown(ll rt)
{
    if(tree[rt].lazy!=0)
    {
        tree[lson(rt)].sum+=tree[rt].lazy*(tree[lson(rt)].r-tree[lson(rt)].l+1);
        tree[rson(rt)].sum+=tree[rt].lazy*(tree[rson(rt)].r-tree[rson(rt)].l+1);
        tree[lson(rt)].lazy+=tree[rt].lazy;
        tree[rson(rt)].lazy+=tree[rt].lazy;
        tree[rt].lazy=0;
    }
}
void update(ll rt,ll x,ll y,ll val)
{
    if(x<=tree[rt].l&&tree[rt].r<=y)
    {
        tree[rt].sum+=val*(tree[rt].r-tree[rt].l+1);
        tree[rt].lazy+=val;
        return;
    }
    pushdown(rt);
    ll mid=(tree[rt].l+tree[rt].r)/2;
    if(x<=mid)
    {
        update(lson(rt),x,y,val);
    }
    if(y>mid)
    {
        update(rson(rt),x,y,val);
    }
    pushup(rt);
}
ll query(ll rt,ll x,ll y)
{
    if(x<=tree[rt].l&&tree[rt].r<=y)
    {
        return tree[rt].sum;
    }
    pushdown(rt);
    ll mid=(tree[rt].l+tree[rt].r)/2,ans=0;
    if(x<=mid)
    {
        ans+=query(lson(rt),x,y);
    }
    if(y>mid)
    {
        ans+=query(rson(rt),x,y);
    }
    return ans;
}
void add(ll u,ll v)
{
    cnt++;
    e[cnt].nxt=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
void dfs1(ll x,ll father)
{
    siz[x]=1;
    fa[x]=father;
    dep[x]=dep[father]+1;
    for(ll i=head[x];i!=0;i=e[i].nxt)
    {
        if(e[i].to!=father)
        {
            dfs1(e[i].to,x);
            siz[x]+=siz[e[i].to];
            son[x]=(siz[e[i].to]>siz[son[x]])?e[i].to:son[x];
        }
    }
}
void dfs2(ll x,ll father,ll id)
{
    top[x]=id;
    tot++;
    dfn[x]=tot;
    cc[tot]=c[x];
    if(son[x]!=0)
    {
        dfs2(son[x],x,id);
        for(ll i=head[x];i!=0;i=e[i].nxt)
        {
            if(e[i].to!=father&&e[i].to!=son[x])
            {
                dfs2(e[i].to,x,e[i].to);
            }
        }
    }
    out[x]=tot;
}
ll lca(ll u,ll v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]])
        {
            u=fa[top[u]];
        }
        else
        {
            v=fa[top[v]];
        }
    }
    return (dep[u]<dep[v])?u:v;
}
ll lca_reroot(ll u,ll v,ll rt)
{
    ll lca1=lca(u,v),lca2=lca(u,rt),lca3=lca(v,rt),ans;
    ans=(dep[lca1]>=dep[lca2])?lca1:lca2;
    ans=(dep[ans]>=dep[lca3])?ans:lca3;
    return ans;
}
ll dirson(ll u,ll v)
{
    if(dep[u]>dep[v])
    {
        swap(u,v);
    }
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]])
        {
            if(fa[top[u]]==v)
            {
                return top[u];
            }
            u=fa[top[u]];
        }
        else
        {
            if(fa[top[v]]==u)
            {
                return top[v];
            }
            v=fa[top[v]];
        }
    }
    return (dep[u]<dep[v])?son[u]:son[v];
}
void update1(ll pos,ll val)
{
    update(1,dfn[pos],out[pos],val);
}
void update_reroot1(ll x,ll rt,ll val)
{
    if(x==rt)
    {
        update1(1,val);
    }
    else
    {
        if(dfn[x]<=dfn[rt]&&dfn[rt]<=out[x])
        {
            update1(1,val);
            update1(dirson(x,rt),-val);
        }
        else
        {
            update1(x,val);
        }
    }
}
void update2(ll u,ll v,ll val,ll rt)
{
    update_reroot1(lca_reroot(u,v,rt),rt,val);
}
ll query1(ll pos)
{
    return query(1,dfn[pos],out[pos]);
}
ll query_reroot1(ll x,ll rt)
{
    if(x==rt)
    {
        return query1(1);
    }
    else
    {
        if(dfn[x]<=dfn[rt]&&dfn[rt]<=out[x])
        {
            return query1(1)-query1(dirson(x,rt));
        }
        else
        {
            return query1(x);
        }
    }
}
int main()
{
    ll n,m,pd,u,v,w,rt=1,i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    build(1,1,n);
    for(i=1;i<=m;i++)
    {
        cin>>pd;
        if(pd==1)
        {
            cin>>rt;
        }
        if(pd==2)
        {
            cin>>u>>v>>w;
            update2(u,v,w,rt);
        }
        if(pd==3)
        {
            cin>>u;
            cout<<query_reroot1(u,rt)<<endl;
        }
    }
    return 0;
}