// LUOGU_RID: 159784561
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define int ll
#define maxn 1000005
#define mod 1000000007
using namespace std;
int re()
{
    int x=0;
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int n,m,ans;
int a[maxn],b[maxn],fa[maxn],f[maxn],g[maxn];
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=re();
    for(int i=1;i<=n;i++)
        a[i]=re();
    for(int i=2;i<=n;i++)
        fa[i]=re();
    for(int i=n;i>1;i--)
        a[fa[i]]+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])
            b[m]++;
        else
            a[++m]=a[i],b[m]=1;
    }
    swap(n,m);
    for(int i=1;i<=n;i++)
    {
        int x=a[n]/__gcd(a[n],a[i]);
        if(x<=m)
            g[x]+=b[i];
    }
    for(int i=m;i;i--)
        for(int j=i<<1;j<=m;j+=i)
            g[j]+=g[i];
    f[1]=1;
    for(int i=n;i;i--)
    {
        if(a[n]%a[i])continue;
        int x=a[n]/a[i];
        if(x>m||g[x]!=x)continue;
        upd(ans,f[x]);
        for(int j=x<<1;j<=m;j+=x)
            upd(f[j],f[x]);
    }
    printf("%lld",ans);
    return 0;
}