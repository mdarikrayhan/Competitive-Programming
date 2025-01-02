// LUOGU_RID: 160506758
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#define double long double
using namespace std;
const int MAXN=1e5+10;
int n,m;double p[MAXN],a[MAXN];
struct Tree{double sum,prod;}t[MAXN<<2];
inline Tree merge(Tree ls,Tree rs)
{
    Tree p;p.prod=ls.prod*rs.prod;
    p.sum=ls.sum+ls.prod*rs.sum;return p;
}
void build(int l,int r,int p)
{
    if(l==r){t[p].sum=t[p].prod=a[l];return ;}
    int mid=(l+r)>>1;
    build(l,mid,p<<1),build(mid+1,r,p<<1|1);
    t[p]=merge(t[p<<1],t[p<<1|1]);
}
void change(int l,int r,int p,int x,double z)
{
    if(l==r){t[p].sum=t[p].prod=z;return ;}
    int mid=(l+r)>>1;
    if(x<=mid) change(l,mid,p<<1,x,z);
    else change(mid+1,r,p<<1|1,x,z);
    t[p]=merge(t[p<<1],t[p<<1|1]);
}
Tree query(int l,int r,int p,int x,int y)
{
    if(x<=l&&y>=r) return t[p];int mid=(l+r)>>1;
    if(y<=mid) return query(l,mid,p<<1,x,y);
    if(x>mid) return query(mid+1,r,p<<1|1,x,y);
    Tree ls=query(l,mid,p<<1,x,y),rs=query(mid+1,r,p<<1|1,x,y);
    return merge(ls,rs);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;a[0]=1;
    for(int i=1,A,B;i<=n;++i)
        cin>>A>>B,p[i]=A*1.0/B,a[i]=(1-p[i])/p[i];
    build(1,n,1);while(m--)
    {
        int opt,i,A,B,l,r;cin>>opt;
        if(opt==1)
        {
            cin>>i>>A>>B;p[i]=A*1.0/B;
            change(1,n,1,i,a[i]=(1-p[i])/p[i]);
        }
        else
        {
            cin>>l>>r;double ans=query(1,n,1,l,r).sum;
            ans=1.0/(ans+1),cout<<fixed<<setprecision(10)<<ans<<'\n';
        }
    }
    return 0;
}