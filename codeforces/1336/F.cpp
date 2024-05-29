#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.5e5+10;
int n,m,k,idx,pos,res,dep[N],siz[N],son[N];
int tp[N],dfn[N],chk[N][2],st[20][N];
int fi[N],se[N],th[N],fa[20][N];
vector<int>g[N],gr[N],qr[N];

struct BIT {
    int t[N];
    #define lb(x) (x&-x)
    void upd(int x,int v) { for(;x<=n;x+=lb(x)) t[x]+=v; }
    int qry(int l,int r,int v=0) {
        if(l>r) return 0;
        for(;r;r-=lb(r)) v+=t[r];
        for(--l;l;l-=lb(l)) v-=t[l];
        return v;
    }
} tr;

int id(int u,int v) { return dfn[u]<dfn[v]?u:v; }
int lca(int u,int v) {
    if(u==v) return u;
    if((u=dfn[u])>(v=dfn[v])) swap(u,v);
    int lg=__lg(v-u++);
    return id(st[lg][u],st[lg][v-(1<<lg)+1]);
}

int getd(int u,int v) {
    return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
}

int kth(int x,int rk) {
    for(int i=17;~i;--i) if(rk>>i&1) x=fa[i][x];
    return x;
}

int get(int u,int v,int rk) {
    int lc=lca(u,v);
    if(dep[u]-dep[lc]>=rk) return kth(u,rk);
    return kth(v,dep[u]+dep[v]-(dep[lc]<<1)-rk);
}

void dfs1(int x,int f) {
    dep[x]=dep[fa[0][x]=f]+(siz[x]=1);
    for(int i=1;i<18;++i) fa[i][x]=fa[i-1][fa[i-1][x]];
    for(int to: g[x]) {
        if(to==f) continue;
        dfs1(to,x),siz[x]+=siz[to];
        son[x]=(siz[to]>siz[son[x]]?to:son[x]);
    }
}

void dfs2(int x,int pt) {
    st[0][dfn[x]=++idx]=fa[0][x],tp[x]=pt;
    if(son[x]) dfs2(son[x],pt);
    for(int to: g[x]) if(to!=fa[0][x]&&to!=son[x]) dfs2(to,to);
}

int solve(int x,int id,int p) {
    int y=fi[id]^se[id]^x,lc=lca(x,y);
    if(getd(p,y)<k) return 0;
    int fir=get(p,y,k-1),sec=get(p,y,k);
    if(fa[0][fir]==sec) {
        int ret=tr.qry(1,dfn[fir]-1)+tr.qry(dfn[fir]+siz[fir],n);
        if(dfn[x]<dfn[y]&&y!=lc) {
            int now=kth(y,dep[y]-dep[lc]-1);
            ret-=tr.qry(dfn[now],dfn[now]+siz[now]-1);
        }
        return ret;
    } else {
        if(dfn[x]<dfn[y]) return 0;
        return tr.qry(dfn[sec],dfn[sec]+siz[sec]-1);
    }
}

void add(int x,int id,int val) {
    int y=fi[id]^se[id]^x,op=(y==se[id]);
    if(val==1) {
        if(dfn[y]>=dfn[pos]&&dfn[y]<dfn[pos]+siz[pos]) return;
        if(!chk[id][op]) chk[id][op]=true,tr.upd(dfn[y],1);
    } else if(val==-1&&chk[id][op]) chk[id][op]=false,tr.upd(dfn[y],-1);
}

void dfs3(int x,int pt) {
    for(int to: gr[x]) {
        if(pt>0) res+=solve(x,to,pt);
        else add(x,to,(pt==-1?1:-1));
    }
    for(int to: g[x]) if(to!=fa[0][x]) dfs3(to,pt);
}

void dsu(int x,int pt) {
    for(int to: g[x]) if(to!=fa[0][x]&&to!=son[x]) dsu(to,0);
    if(son[x]) dsu(son[x],1); pos=x;
    for(int v: qr[x]) add(fi[v],v,-1),add(se[v],v,-1);
    for(int to: g[x]) if(to!=fa[0][x]&&to!=son[x]) dfs3(to,x),dfs3(to,-1);
    for(int to: gr[x]) res+=solve(x,to,x),add(x,to,1);
    if(!pt) dfs3(x,-2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1,u,v;i<n;++i)
        cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
    dfs1(1,0),dfs2(1,1);
    for(int i=1;i<18;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=id(st[i-1][j],st[i-1][j+(1<<i-1)]);
    for(int i=1;i<=m;++i) {
        cin>>fi[i]>>se[i],th[i]=lca(fi[i],se[i]);
        gr[fi[i]].push_back(i),gr[se[i]].push_back(i),qr[th[i]].push_back(i);
    }
    return dsu(1,1),cout<<res,0;
}
// ?
	 			     	  	  	  	      	 		