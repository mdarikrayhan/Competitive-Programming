/*******************************
| Problem: G. wxhtzdy ORO Tree
| Contest: Codeforces - Codeforces Round 900 (Div. 3)
| URL:     https://codeforces.com/contest/1878/problem/G
*******************************/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define debug(x) cerr<<#x<<' '<<x<<endl;
typedef pair<int,int>PII;
typedef long long LL;
constexpr int N=200010,mod=1e9+7;
vector<int>e[N];
int f[N][40],v[N][40],d[N][40],dep[N],a[N];
void dfs(int x,int fa)
{
    for(auto y:e[x])
    {
        if(y==fa)continue;
        dep[y]=dep[x]+1;
        for(int i=30;i>=0;i--)
        {
            d[y][i]=d[x][i];
            if(a[y]>>i&1)d[y][i]=y;
        }
        f[y][0]=x;
        v[y][0]=a[y];
        dfs(y,x);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    int z=dep[x]-dep[y];
    for(int i=20;i>=0;i--)
        if(z>>i&1)x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int ask(int x,int lca)
{
    int z=dep[x]-dep[lca];
    int ans=0;
    for(int i=20;i>=0;i--)
    {
        if(z>>i&1)ans|=v[x][i],x=f[x][i];
    }
    return ans|v[lca][0];
}
signed main()
{
    //freopen(".in","r",stdin);freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=30;j++)
                f[i][j]=v[i][j]=d[i][j]=0;
        for(int i=1;i<=n;i++)cin>>a[i],e[i].clear(),dep[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for(int i=30;i>=0;i--)
        {
            if(a[1]>>i&1)d[1][i]=1;
        }
        v[1][0]=a[1];
        dfs(1,0);
        for(int i=1;i<=20;i++)
            for(int j=1;j<=n;j++)
            {
                if(f[j][i-1])
                {
                    f[j][i]=f[f[j][i-1]][i-1];
                    v[j][i]=v[j][i-1]|v[f[j][i-1]][i-1];
                }
            }
        int q;
        cin>>q;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            int lc=lca(x,y),vx=ask(x,lc),vy=ask(y,lc);
          //  cout<<vx<<" "<<vy<<' '<<lc<<endl;
            int ma=0;
            for(int i=0;i<=30;i++)
            {
                if(d[x][i]&&dep[d[x][i]]>=dep[lc])
                {
                    ma=max(ma,__builtin_popcount(ask(x,d[x][i]))+__builtin_popcount(ask(d[x][i],lc)|vy));
                }
            }
            for(int i=0;i<=30;i++)
            {
                if(d[y][i]&&dep[d[y][i]]>=dep[lc])
                {
                    ma=max(ma,__builtin_popcount(ask(y,d[y][i]))+__builtin_popcount(ask(d[y][i],lc)|vx));
                }
            }
            cout<<ma<<" ";

        }
        cout<<endl;
    }

}