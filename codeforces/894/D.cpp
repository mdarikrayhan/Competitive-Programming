// LUOGU_RID: 158953291
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=1000010;
int n,m,deep[N],len[N];
vector<int> a[N];
vector<int> sum[N];
int calc(int u,int h)
{
    if(h<=0||!a[u].size())
        return 0;
    int s=lower_bound(a[u].begin(),a[u].end(),h)-a[u].begin();
    return s?s*h-sum[u][s-1]:0;
}
signed main()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)
        scanf("%d",len+i);
    for(int u=1;u<=n/2;u++)
    {
        int L=u*2;
        int R=u*2+1;
        if(L<=n)
            deep[L]=deep[u]+len[L];
        if(R<=n)
            deep[R]=deep[u]+len[R];
    }
    for(int u=n;u;u--)
    {
        int L=u*2;
        int R=u*2+1;
        a[u].emplace_back(deep[u]);
        if(R<=n)
            merge(a[L].begin(),a[L].end(),a[R].begin(),a[R].end(),back_inserter(a[u]));
        else if(L<=n)
            a[u].insert(a[u].end(),a[L].begin(),a[L].end());
        sum[u].resize(a[u].size());
        sum[u][0]=a[u][0];
        for(int i=1;i<(int)sum[u].size();i++)
            sum[u][i]=sum[u][i-1]+a[u][i];
    }
    for(int u,h;m--;)
    {
        cin>>u>>h;
        int ans=calc(u,h+deep[u]);
        for(h=h-len[u];h>0&&u!=1;h=h-len[u>>=1])
            ans+=h+calc(u^1,h-len[u^1]+deep[u^1]);
        cout<<ans<<endl;
    }
}