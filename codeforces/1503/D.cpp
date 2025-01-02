// LUOGU_RID: 156664479
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 200005
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
int n,ans;
bool fl[maxn];
int a[maxn],mx[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=re();
    for(int i=1;i<=n;i++)
    {
        int x=re(),y=re();
        if(x<=n&&y<=n||x>n&&y>n)
            return puts("-1"),0;
        if(x>y)
        {
            swap(x,y);
            fl[x]=1;
        }
        a[x]=y-n;
    }
    for(int i=n;i;i--)
        mx[i]=max(mx[i+1],a[i]);
    int ma=n+1,mb=n+1,va=0,vb=0;
    for(int i=1;i<=n;i++)
    {
        if(mx[i]>ma&&mx[i]>mb)
            return puts("-1"),0;
        if(a[i]>ma)
            mb=a[i],va+=!fl[i],vb+=fl[i];
        if(a[i]>mb)
            ma=a[i],va+=fl[i],vb+=!fl[i];
        if(a[i]<ma&&a[i]<mb)
        {
            if(mx[i]>ma)
                ma=a[i],va+=fl[i],vb+=!fl[i];
            if(mx[i]>mb)
                mb=a[i],va+=!fl[i],vb+=fl[i];
            if(mx[i]<ma&&mx[i]<mb)
            {
                ans+=min(va,vb);
                ma=a[i],mb=n+1;
                va=fl[i],vb=!fl[i];
            }
        }
    }
    ans+=min(va,vb);
    printf("%d",ans);
    return 0;
}