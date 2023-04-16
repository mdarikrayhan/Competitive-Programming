#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T;
int n,cnt;
bool book[N];
long long sum,w,h,answ[3];
long long a[N],b[N];
struct Node
{
    long long val;
    int id;
}x[N],y[N];
bool cmp(Node x,Node y)
{
    return x.val>y.val;
}
void check()
{
    int p=1,q=1;
    long long w1=w;
    while(w&&h)
    {
        while(p<=n&&book[x[p].id]) p++;
        while(q<=n&&book[y[q].id]) q++;
        if(x[p].val==w) h-=b[x[p].id],book[x[p].id]=1,p++;
        else if(y[q].val==h) w-=a[y[q].id],book[y[q].id]=1,q++;
        else break;
    }
    while(p<=n&&book[x[p].id]) p++;
    while(q<=n&&book[y[q].id]) q++;
    if(p==n+1&&q==n+1) answ[++cnt]=w1;
    for(int i=1;i<=n;i++) book[i]=0;
}
void solve()
{
    cnt=sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]),sum+=a[i]*b[i],x[i].id=y[i].id=i,x[i].val=a[i],y[i].val=b[i];
    sort(x+1,x+n+1,cmp);
    sort(y+1,y+n+1,cmp);
    int p=1,q=1;
    w=x[1].val;
    if(sum%w==0) h=sum/w,check();
    h=y[1].val;
    if(sum%h==0) w=sum/h,check();
    if(cnt==2&&answ[1]==answ[2]) cnt--;
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%lld %lld\n",answ[i],sum/answ[i]);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}