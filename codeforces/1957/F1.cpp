// LUOGU_RID: 160451816
#include<bits/stdc++.h>
#define ULL unsigned long long 
#define LL long long 
using namespace std;
const int N=1e5+1;
const ULL mul=123;
const LL mod=998244353;
int n,m,tot,cnt,a[N+5],root[N+5],fa[N+5],dep[N+5],siz[N+5],son[N+5],top[N+5],dfn[N+5],rnk[N+5];
int g,h,ph,da,k;
ULL lg[N+5];
LL lgsp[N+5];
vector <int > e[N+5];
void add(int u,int v) { e[u].push_back(v),e[v].push_back(u); }
struct segment_tree{
    int ls,rs;
    ULL dat;
    LL spare;
}t[N*32+5];
void insert(int &p,int hv,int l,int r,int k){
    p=++tot;
    t[p]=t[hv],t[p].dat+=lg[k],(t[p].spare+=lgsp[k])%=mod;
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(k<=mid) insert(t[p].ls,t[hv].ls,l,mid,k);
    else insert(t[p].rs,t[hv].rs,mid+1,r,k);
}
ULL query(int p,int hv,int l,int r,int k){  
    if(!p) return 0ull;
    if(r<=k) return t[p].dat-t[hv].dat; 
    int mid=(l+r)>>1;ULL val=t[t[p].ls].dat-t[t[hv].ls].dat;
    if(k<=mid) return query(t[p].ls,t[hv].ls,l,mid,k);
    else return query(t[p].rs,t[hv].rs,mid+1,r,k)+val;
}
LL querysp(int p,int hv,int l,int r,int k){
    if(!p) return 0ll;
    if(r<=k) return (t[p].spare-t[hv].spare+mod)%mod;
    int mid=(l+r)>>1;LL val=(t[t[p].ls].spare-t[t[hv].ls].spare+mod)%mod;
    if(k<=mid) return querysp(t[p].ls,t[hv].ls,l,mid,k);
    else return (querysp(t[p].rs,t[hv].rs,mid+1,r,k)+val)%mod;
}
void dfs1(int now,int father){
    fa[now]=father,dep[now]=dep[father]+1;
    siz[now]=1;
    for(int to:e[now]){
        if(to==father) continue;
        dfs1(to,now);
        siz[now]+=siz[to];
        if(siz[to]>siz[son[now]]) son[now]=to;
    }
}
void dfs2(int x,int y){
    top[x]=y;
    dfn[x]=++cnt,rnk[cnt]=x;
    if(son[x]) dfs2(son[x],y);
    for(int to:e[x]){
        if(fa[x]==to||son[x]==to) continue;
        dfs2(to,to);
    }
}
ULL query_on_link(int x,int y,int k){
    ULL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res+=query(root[dfn[x]],root[dfn[top[x]]-1],1,N,k);
        x=fa[top[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    res+=query(root[dfn[y]],root[dfn[x]-1],1,N,k);
    return res;
}
LL querysp_on_link(int x,int y,int k){
    LL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        (res+=querysp(root[dfn[x]],root[dfn[top[x]]-1],1,N,k))%=mod;
        x=fa[top[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    (res+=querysp(root[dfn[y]],root[dfn[x]-1],1,N,k))%=mod;
    return res;
}
void solve(){
    int l=1,r=N;
    while(l<r){
        int mid=(l+r)>>1;
        if((query_on_link(g,h,mid)!=query_on_link(ph,da,mid))||(querysp_on_link(g,h,mid)!=querysp_on_link(ph,da,mid))) r=mid;
        else l=mid+1;
    }
    if(l==N) cout<<0<<'\n';
    else cout<<1<<" "<<l<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;lg[0]=lgsp[0]=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=N;i++) lg[i]=lg[i-1]*mul,lgsp[i]=lgsp[i-1]*mul%mod;
    for(int i=1;i<=n-1;i++) cin>>g>>h,add(g,h);
    dfs1(1,0),dfs2(1,1);
    for(int i=1;i<=n;i++) insert(root[i],root[i-1],1,N,a[rnk[i]]);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>g>>h>>ph>>da>>k;
        solve();
    }
    return 0;
}