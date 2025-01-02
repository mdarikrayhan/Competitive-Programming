// LUOGU_RID: 160595429
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+5,INF=1e9+7;
int T,n,q,k,a[N],b[N];
#define ls p<<1
#define rs p<<1|1
#define mid ((l+r)>>1)
struct node{vector<pii> pre,suf;int res,mx;}tr[N<<2];
node operator +(const node&a,const node&b){
    node c;c.pre=a.pre;c.suf=b.suf;c.res=min(a.res,b.res);
    c.mx=max(a.mx,b.mx);int mx=a.mx;
    for(auto x:b.pre){
        auto y=c.pre.back();
        if((x.fi|y.fi)!=y.fi)
            c.pre.emplace_back(x.fi|y.fi,mx=max(x.se,mx));
    }
    mx=b.mx;
    for(auto x:a.suf){
        auto y=c.suf.back();
        if((x.fi|y.fi)!=y.fi)
            c.suf.emplace_back(x.fi|y.fi,mx=max(x.se,mx));
    }
    for(int i=0,j=b.pre.size()-1;i<a.suf.size();i++){
        while(j>=0&&(a.suf[i].fi|b.pre[j].fi)>=k)--j;
        if(j+1!=b.pre.size()&&(a.suf[i].fi|b.pre[j+1].fi)>=k)
            c.res=min(c.res,max(a.suf[i].se,b.pre[j+1].se));
    }
    return c;
}
void build(int p,int l,int r){
    if(l==r){
        tr[p].pre=tr[p].suf={make_pair(b[l],a[l])};tr[p].mx=a[l];
        if(b[l]>=k)tr[p].res=a[l];else tr[p].res=INF;return;
    }
    build(ls,l,mid);build(rs,mid+1,r);tr[p]=tr[ls]+tr[rs];
}
void modify(int p,int l,int r,int x,int v){
    if(l==r){
        tr[p].pre=tr[p].suf={make_pair(b[l]=v,a[l])};tr[p].mx=a[l];
        if(b[l]>=k)tr[p].res=a[l];else tr[p].res=INF;return;
    }
    if(x<=mid)modify(ls,l,mid,x,v);
    else modify(rs,mid+1,r,x,v);tr[p]=tr[ls]+tr[rs];
}
node query(int p,int l,int r,int L,int R){
    if(l>=L&&r<=R)return tr[p];
    if(L>mid)return query(rs,mid+1,r,L,R);
    if(R<=mid)return query(ls,l,mid,L,R);
    return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)scanf("%d",b+i);
        build(1,1,n);scanf("%d",&q);
        while(q--){
            int op,x,y;scanf("%d%d%d",&op,&x,&y);
            if(op==1)modify(1,1,n,x,y);
            else{
                int ans=query(1,1,n,x,y).res;
                if(ans==INF)printf("-1 ");else printf("%d ",ans);
            }
        }
        printf("\n");
    }
    return 0;
}