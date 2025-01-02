#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define maxn 200005
#define min(x,y) (x<y?x:y)
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
int T,n;
int a[maxn],f[maxn][2];
vector<int>e[maxn];
void dfs(int pos,int fa,int mx)
{
    int mx1=0,cmx1=0,mx2=0,cmx2=0;
    for(int v:e[pos])
    {
        if(v==fa)continue;
        dfs(v,pos,mx);
        int t=min(f[v][0],f[v][1]+1);
        if(t>mx1)
            cmx1=mx1,mx1=t;
        else if(t>cmx1)
            cmx1=t;
        t=min(f[v][0]+1,f[v][1]);
        if(t>mx2)
            cmx2=mx2,mx2=t;
        else if(t>cmx2)
            cmx2=t;
    }
    if(a[pos]!=2&&mx1+cmx1<=mx)
        f[pos][0]=mx1;
    else
        f[pos][0]=1e9;
    if(a[pos]!=1&&mx2+cmx2<=mx)
        f[pos][1]=mx2;
    else
        f[pos][1]=1e9;
}
int solve()
{
    n=re();
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<=n;i++)
        a[i]=re();
    for(int i=1;i<n;i++)
    {
        int u=re(),v=re();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int l=0,r=n,ret=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        dfs(1,0,mid);
        if(f[1][0]<=n||f[1][1]<=n)
            ret=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ret+3>>1;
}
signed main()
{
    T=re();
    while(T--)
        printf("%d\n",solve());
    return 0;
}
				 				 	  	 		 	  		 	  	 	