#include<bits/stdc++.h>
#define int long long
#define N 200007
#pragma GCC optimize(2)
using namespace std;
int n,m,x,k,y;
int a[N],b[N];
int ID[N];
int st[N][22];
void init()
{
    for(int i=1;i<=n;i++)
    {
        st[i][0]=a[i];
    }
    for(int j=1;j<22;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int qur(int l,int r)
{
    int j=log2(r-l+1);
    return max(st[l][j],st[r-(1<<j)+1][j]);
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    scanf("%lld%lld%lld",&x,&k,&y);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&b[i]);
    }
    b[0]=b[m+1]=0;
    for(int i=1;i<=n;i++)
    {
        ID[a[i]]=i;
    }
    init();
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        int l=ID[b[i]],r=ID[b[i+1]];
        if(i==0)
        {
            l=0;
        }
        if(i==m)
        {
            r=n+1;
        }
        if(l>=r)
        {
            printf("-1\n");
            return ;
        }
        l++,r--;
        if(l<=r)
        {
            int mx=qur(l,r);
            if(b[i]<mx&&b[i+1]<mx)
            {
                if(r-l+1>=k)
                {
                    ans+=min(y*((r-l+1)%k)+x*((r-l+1)/k),y*((r-l+1)-k)+x);
                }
                else
                {
                    printf("-1\n");
                    return ;
                }
            }
            else
            {
                ans+=min(y*((r-l+1)%k)+x*((r-l+1)/k),y*(r-l+1));
            }
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    solve();
    return 0;
}