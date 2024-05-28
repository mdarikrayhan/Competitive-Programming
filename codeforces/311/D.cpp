// LUOGU_RID: 156293640
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 100005
#define mod 95542721
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
int n,Q;
int a[maxn],smt[maxn<<2][48],tag[maxn<<2],tmp[48];
int tri(int x)
{
    return (ll)x*x%mod*x%mod;
}
void update(int pos)
{
    for(int i=0;i<48;i++)
        smt[pos][i]=(smt[pos<<1][i]+smt[pos<<1|1][i])%mod;
}
void build_tree(int pos,int l,int r)
{
    if(l==r)
    {
        smt[pos][0]=a[l]%mod;
        for(int i=1;i<48;i++)
            smt[pos][i]=tri(smt[pos][i-1]);
        return;
    }
    int mid=l+r>>1;
    build_tree(pos<<1,l,mid);
    build_tree(pos<<1|1,mid+1,r);
    update(pos);
}
void turn(int pos,int x)
{
    if(x%48==0)return;
    tag[pos]+=x;
    for(int i=0;i<48;i++)
        tmp[i]=smt[pos][(i+x)%48];
    for(int i=0;i<48;i++)
        smt[pos][i]=tmp[i];
}
void pushtag(int pos)
{
    turn(pos<<1,tag[pos]);
    turn(pos<<1|1,tag[pos]);
    tag[pos]=0;
}
int fi(int pos,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return smt[pos][0];
    pushtag(pos);
    int mid=l+r>>1,ret=0;
    if(L<=mid)
        ret+=fi(pos<<1,l,mid,L,R);
    if(R>mid)
        ret+=fi(pos<<1|1,mid+1,r,L,R);
    if(ret>=mod)
        ret-=mod;
    return ret;
}
void cha(int pos,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return turn(pos,1);
    pushtag(pos);
    int mid=l+r>>1;
    if(L<=mid)
        cha(pos<<1,l,mid,L,R);
    if(R>mid)
        cha(pos<<1|1,mid+1,r,L,R);
    update(pos);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=re();
    for(int i=1;i<=n;i++)
        a[i]=re();
    build_tree(1,1,n);
    Q=re();
    while(Q--)
    {
        int op=re(),l=re(),r=re();
        if(op==1)
            printf("%d\n",fi(1,1,n,l,r));
        else
            cha(1,1,n,l,r);
    }
    return 0;
}