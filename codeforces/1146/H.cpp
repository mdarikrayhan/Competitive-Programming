// LUOGU_RID: 159929968
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define int ll
#define maxn 305
using namespace std;
int re()
{
    int x=0;
    #ifndef ONLINE_JUDGE
    scanf("%lld",&x);
    return x;
    #endif
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
struct node
{
    int x,y;
}a[maxn];
int n,ans;
int up[maxn][4],dw[maxn][4],f[maxn][4][maxn];
struct Segment
{
    int x,y;
    bool operator < (const Segment t) const
    {
        return (a[y].y-a[x].y)*(a[t.y].x-a[t.x].x)<(a[t.y].y-a[t.x].y)*(a[y].x-a[x].x);
    }
}id[maxn],g[maxn][maxn];
bool cmp(node x,node y)
{
    return x.x==y.x?x.y<y.y:x.x<y.x;
}
double get(Segment x)
{
    return 1.0*(a[x.y].y-a[x.x].y)/(a[x.y].x-a[x.x].x);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=re();
    for(int i=1;i<=n;i++)
        a[i]={re(),re()};
    sort(a+1,a+1+n,cmp);
    for(int k=1;k<n;k++)
    {
        for(int i=k+1;i<=n;i++)
        {
            for(int j=k+1;j<i;j++)
                id[j-k]={j,i};
            sort(id+1,id+i-k);
            dw[i][0]=1;
            for(int j=1;j<i-k;j++)
            {
                int x=id[j].x;
                f[i][1][j]=f[i][1][j-1];
                g[i][j]=id[j];
                if((Segment){k,x}<id[j])
                    f[i][1][j]++;
            }
            for(int t=2;t<=3;t++)
            {
                for(int j=1;j<i-k;j++)
                {
                    int x=id[j].x;
                    int l=lower_bound(g[x]+1,g[x]+x-k,id[j])-g[x]-1;
                    f[i][t][j]=f[x][t-1][l]+f[i][t][j-1];
                }
            }
            for(int t=1;t<=3;t++)
                dw[i][t]=f[i][t][i-k-1];
        }
        for(int i=k+1;i<=n;i++)
        {
            for(int j=k+1;j<i;j++)
                id[j-k]={j,i};
            sort(id+1,id+i-k);
            up[i][0]=1;
            f[i][1][i-k]=0;
            for(int j=i-k-1;j;j--)
            {
                int x=id[j].x;
                f[i][1][j]=f[i][1][j+1];
                g[i][j]=id[j];
                if(id[j]<(Segment){k,x})
                    f[i][1][j]++;
            }
            for(int t=2;t<=3;t++)
            {
                f[i][t][i-k]=0;
                for(int j=i-k-1;j;j--)
                {
                    int x=id[j].x;
                    int l=lower_bound(g[x]+1,g[x]+x-k,id[j])-g[x];
                    f[i][t][j]=f[x][t-1][l]+f[i][t][j+1];
                }
            }
            for(int t=1;t<=3;t++)
                up[i][t]=f[i][t][1];
        }
        for(int i=k+1;i<=n;i++)
            for(int t=0;t<=3;t++)
                ans+=up[i][t]*dw[i][3-t];
    }
    printf("%lld",ans);
    return 0;
}