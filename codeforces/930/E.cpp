// LUOGU_RID: 158138218
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 400005
#define int ll
#define mod 1000000007
#define Fi(x) lower_bound(tmp+1,tmp+1+n,x)-tmp
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t==1?x:-x;
}
int n,m,n1,n2;
int ql[maxn],qr[maxn],tmp[maxn],lim1[maxn],lim2[maxn];
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
}
struct Segtree
{
    int smt[maxn<<2],tag[maxn<<2];
    void update(int pos)
    {
        smt[pos]=(smt[pos<<1]+smt[pos<<1|1])%mod;
    }
    void build_tree(int pos,int l,int r)
    {
        if(l==r)
            return smt[pos]=l==n,void();
        int mid=l+r>>1;
        build_tree(pos<<1,l,mid);
        build_tree(pos<<1|1,mid+1,r);
        update(pos);
    }
    void clr(int pos)
    {
        smt[pos]=0;
        tag[pos]=1;
    }
    void pushtag(int pos)
    {
        if(!tag[pos])return;
        clr(pos<<1);
        clr(pos<<1|1);
        tag[pos]=0;
    }
    void clear(int pos,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R)
            return clr(pos);
        pushtag(pos);
        int mid=l+r>>1;
        if(L<=mid)
            clear(pos<<1,l,mid,L,R);
        if(R>mid)
            clear(pos<<1|1,mid+1,r,L,R);
        update(pos);
    }
    void cha(int pos,int l,int r,int x,int y)
    {
        if(l==r)
            return upd(smt[pos],y);
        pushtag(pos);
        int mid=l+r>>1;
        if(x<=mid)
            cha(pos<<1,l,mid,x,y);
        else
            cha(pos<<1|1,mid+1,r,x,y);
        update(pos);
    }
    int fi(int pos,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R)
            return smt[pos];
        pushtag(pos);
        int mid=l+r>>1,ret=0;
        if(L<=mid)
            upd(ret,fi(pos<<1,l,mid,L,R));
        if(R>mid)
            upd(ret,fi(pos<<1|1,mid+1,r,L,R));
        return ret;
    }
    void print(int pos=1,int l=1,int r=n)
    {
        if(l==r)
            return printf("%lld ",smt[pos]),void();
        pushtag(pos);
        int mid=l+r>>1;
        print(pos<<1,l,mid);
        print(pos<<1|1,mid+1,r);
    }
}smt1,smt2;
int ksm(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod,y>>=1;
    }
    return ret;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    m=re()+1,n1=re(),n2=re();
    for(int i=1;i<=n1;i++)
        ql[i]=re(),qr[i]=re()+1,tmp[++n]=ql[i],tmp[++n]=qr[i];
    for(int i=n1+1;i<=n1+n2;i++)
        ql[i]=re(),qr[i]=re()+1,tmp[++n]=ql[i],tmp[++n]=qr[i];
    tmp[++n]=m,tmp[++n]=1;
    sort(tmp+1,tmp+1+n);
    n=unique(tmp+1,tmp+1+n)-tmp-1;
    for(int i=1;i<=n;i++)
        lim1[i]=lim2[i]=n;
    for(int i=1;i<=n1;i++)
    {
        int l=Fi(ql[i]),r=Fi(qr[i])-1;
        lim1[l]=min(lim1[l],r);
    }
    for(int i=n1+1;i<=n1+n2;i++)
    {
        int l=Fi(ql[i]),r=Fi(qr[i])-1;
        lim2[l]=min(lim2[l],r);
    }
    smt1.build_tree(1,1,n);
    for(int i=1;i<n;i++)
    {
        int x=smt1.fi(1,1,n,i,n),y=smt2.fi(1,1,n,i,n),t=x+y;
        if(lim2[i]<n)
        {
            upd(x,smt2.fi(1,1,n,lim2[i]+1,n));
            smt2.clear(1,1,n,lim2[i]+1,n);
        }
        if(lim1[i]<n)
        {
            upd(y,smt1.fi(1,1,n,lim1[i]+1,n));
            smt1.clear(1,1,n,lim1[i]+1,n);
        }
        smt1.cha(1,1,n,lim1[i],y);
        smt2.cha(1,1,n,lim2[i],x);
        smt1.cha(1,1,n,n,t*(ksm(2,tmp[i+1]-tmp[i])-2)%mod);
    }
    printf("%lld",(smt1.fi(1,1,n,n,n)+smt2.fi(1,1,n,n,n))%mod);
    return 0;
}