// LUOGU_RID: 160428827
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=1e5+10;
int const inf=1e18;
int n,m,q,G[N];
vector<int>a[N];
namespace Tree_Cut{
    int dfn[N],heavy[N],dep[N],Fa[N],top[N],siz[N],R[N];
    vector<int>V[N];
    struct node{int id,val,jd;};
    inline node operator + (node a,node b){
        if (b.val<a.val) a=b;
        else if (b.val==a.val && b.jd<a.jd) a=b;
        return a;
    }
    struct Segment_Tree{
        #define ls (x<<1)
        #define rs (x<<1|1)
        node c[N<<2];int lazy[N<<2];
        inline void build(int x,int l,int r){
            if (l==r){
                if (!V[l].size()) c[x]=(node){inf,inf,inf};
                else c[x]=(node){V[l].back(),V[l].back(),R[l]};
                return;
            }
            build(ls,l,mid),build(rs,mid+1,r);
            c[x]=c[ls]+c[rs];
        }
        inline void push(int x,int y){
            lazy[x]+=y,c[x].val+=y;
        }
        inline void pushdown(int x){
            if (!lazy[x]) return;
            push(ls,lazy[x]),push(rs,lazy[x]);
            lazy[x]=0;
        }
        inline void update(int x,int l,int r,int ll,int rr,int v){
            if (ll<=l && r<=rr) return push(x,v),void();
            pushdown(x);
            if (ll<=mid) update(ls,l,mid,ll,rr,v);
            if (mid<rr) update(rs,mid+1,r,ll,rr,v);
            c[x]=c[ls]+c[rs];
        }
        inline void del(int x,int l,int r,int p){
            if (l==r){
                V[l].pop_back();
                if (!V[l].size()) c[x]=(node){inf,inf,inf};
                else c[x]=(node){V[l].back(),V[l].back()+lazy[x],R[l]};
                return;
            }
            pushdown(x);
            if (p<=mid) del(ls,l,mid,p);
            else del(rs,mid+1,r,p);
            c[x]=c[ls]+c[rs];
        }
        inline node query(int x,int l,int r,int ll,int rr){
            if (ll<=l && r<=rr) return c[x];
            node res=(node){inf,inf,inf};
            pushdown(x);
            if (ll<=mid) res=res+query(ls,l,mid,ll,rr);
            if (mid<rr) res=res+query(rs,mid+1,r,ll,rr);
            return res;
        }
    }T;
    inline void dfs1(int x,int fa){
        Fa[x]=fa,siz[x]=1,dep[x]=dep[fa]+1;
        for (auto v:a[x])
            if (v^fa){
                dfs1(v,x),siz[x]+=siz[v];
                if (siz[v]>siz[heavy[x]]) heavy[x]=v;
            }
    }
    inline void dfs2(int x,int fa,int tp){
        top[x]=tp,dfn[x]=++dfn[0],R[dfn[0]]=x;
        if (heavy[x]) dfs2(heavy[x],x,tp);
        for (auto v:a[x]){
            if (v==fa) continue;
            if (v==heavy[x]) continue;
            dfs2(v,x,v);
        }
    }
    inline void init(){
        dfs1(1,0),dfs2(1,0,1);
        rep(i,1,m) cin>>G[i];
        per(i,m,1) V[dfn[G[i]]].emplace_back(i);
        T.build(1,1,n);
    }
    inline node Qry(int x,int y){
        node res=(node){inf,inf,inf};
        while (top[x]^top[y]){
            if (dep[top[x]]<dep[top[y]]) swap(x,y);
            res=res+T.query(1,1,n,dfn[top[x]],dfn[x]),x=Fa[top[x]];
        }
        if (dep[x]>dep[y]) swap(x,y);
        res=res+T.query(1,1,n,dfn[x],dfn[y]);
        return res;
    }
    inline void add(int x,int y){
        T.update(1,1,n,dfn[x],dfn[x]+siz[x]-1,y);
    }
    inline void del(int id){
        T.del(1,1,n,dfn[G[id]]);
    }
}
void solve(){
    cin>>n>>m>>q;
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    Tree_Cut::init();
    while (q--){
        int tp;cin>>tp;
        switch (tp){
            case 1:{
                int u,v,k;cin>>u>>v>>k;
                vector<int>ans;
                while (k--){
                    auto it=Tree_Cut::Qry(u,v);
                    if (it.id==inf) break;
                    ans.push_back(it.id);
                    Tree_Cut::del(it.id);
                }
                cout<<ans.size()<<' ';
                for (auto i:ans) cout<<i<<' ';
                cout<<'\n';
                break;
            }
            case 2:{
                int x,y;cin>>x>>y;
                Tree_Cut::add(x,y);
                break;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}