#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 105
#define maxm 10005
#define N 10000
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
int n,Q,tans;
int a[maxn],b[maxn],f[maxm],g[maxm];
unordered_map<int,int>ans;
void upd(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
    if(x<0)x+=mod;
}
int solve()
{
    int x=re();
    mclear(f);
    f[0]=1;
    int l=0,r=0;
    bool fl=0;
    for(int i=1;i<=n;i++)
    {
        l+=x+b[i],r+=a[i];
        if(l>r)
            return 0;
        if(l>0)
            fl=1;
    }
    if(!fl)
        x=-1e4;
    if(ans.count(x))
        return ans[x];
    l=r=0;
    for(int i=1;i<=n;i++)
    {
        l+=x+b[i],r+=a[i];
        for(int j=0;j<=r;j++)
        {
            g[j]=f[j];
            if(j)
                upd(g[j],g[j-1]);
            f[j]=g[j];
            if(j>a[i])
                upd(f[j],-g[j-a[i]-1]);
        }
        for(int j=0;j<l;j++)
            f[j]=0;
    }
    int ret=0;
    for(int i=0;i<=r;i++)
        upd(ret,f[i]);
    return ans[x]=ret;
}
signed main()
{
    n=re();
    for(int i=1;i<=n;i++)
        a[i]=re();
    for(int i=2;i<=n;i++)
        b[i]=b[i-1]+re();
    Q=re();
    while(Q--)
        printf("%d\n",solve());
    return 0;
}
   	 		   	        	  				 	  	