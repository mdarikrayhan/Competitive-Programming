// LUOGU_RID: 156686251
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 4005
#define Fi(x) lower_bound(tmp+1,tmp+1+N,x)-tmp
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t==1?x:-x;
}
struct node
{
    int x,y;
}a1[maxn],b1[maxn];
struct qz
{
    int x,l,r;
}a[maxn],b[maxn],c[maxn];
int n,m,n1,m1,N;
int tmp[maxn];
struct BIT
{
    int tree[maxn];
    void cha(int x,int y)
    {
        for(int i=x;i<=N;i+=i&-i)
            tree[i]+=y;
    }
    int fi(int x)
    {
        int ret=0;
        for(int i=x;i;i-=i&-i)
            ret+=tree[i];
        return ret;
    }
    int fi(int l,int r)
    {
        return fi(r)-fi(l-1);
    }
}bit;
bool cmp1(node x,node y)
{
    if(x.x==y.x)
        return x.y<y.y;
    return x.x<y.x;
}
bool cmp2(node x,node y)
{
    if(x.y==y.y)
        return x.x<y.x;
    return x.y<y.y;
}
bool cmp3(qz x,qz y)
{
    return x.l<y.l;
}
bool check(int len)
{
    n=m=0;
    for(int i=1;i<=n1;i++)
    {
        if(a1[i].x==a1[i-1].x&&a1[i-1].y+2*len>=a1[i].y)
            a[n].r=Fi(a1[i].y+len+1)-1;
        else
            a[++n]={a1[i].x,Fi(a1[i].y-len),Fi(a1[i].y+len+1)-1};
    }
    for(int i=1;i<=m1;i++)
    {
        if(b1[i].y==b1[i-1].y&&b1[i-1].x+2*len>=b1[i].x)
            b[m].r=b1[i].x+len;
        else
            b[++m]={b1[i].y,b1[i].x-len,b1[i].x+len};
    }
    sort(b+1,b+1+m,cmp3);
    for(int i=2;i<=n;i++)
    {
        int cnt=0;
        mclear(bit.tree);
        for(int j=1;j<=m;j++)
        {
            if(a[i].l<=b[j].x&&b[j].x<=a[i].r&&b[j].l<=a[i].x&&a[i].x<=b[j].r)
            {
                c[++cnt]=b[j];
                bit.cha(b[j].x,1);
            }
        }
        for(int j=i;j;j--)
        {
            if(a[j].x==a[i].x)continue;
            while(cnt&&a[j].x<c[cnt].l)
            {
                bit.cha(c[cnt].x,-1);
                cnt--;
            }
            if(cnt<2)break;
            if(bit.fi(a[j].l,a[j].r)>=2)return 1;
        }
    }
    return 0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n1=re(),m1=re();
    a1[0].x=b1[0].y=-1e9;
    for(int i=1;i<=n1;i++)
    {
        int x=re(),y=re();
        a1[i]={y+x,y-x};
        tmp[++N]=a1[i].y;
    }
    for(int i=1;i<=m1;i++)
    {
        int x=re(),y=re();
        b1[i]={y+x,y-x};
        tmp[++N]=b1[i].y;
    }
    sort(tmp+1,tmp+1+N);
    sort(a1+1,a1+1+n1,cmp1);
    sort(b1+1,b1+1+m1,cmp2);
    for(int i=1;i<=m1;i++)
        b1[i].y=Fi(b1[i].y);
    int l=0,r=1e6,ans=-1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid<<1))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    if(~ans)
        printf("%d",ans);
    else
        puts("Poor Sereja!");
    return 0;
}