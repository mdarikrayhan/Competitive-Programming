// LUOGU_RID: 160006672
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N=200010;
int f[N],b[N],w[N];
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=2*n;i++)
    {
        cin>>w[i];
        if (w[i]==1) w[i]=-1;
        else w[i]=1;
    }
    for (int i=1;i<=n;i++) f[i]=f[i-1]+w[i];
    b[2*n+1]=0;
    for (int i=2*n;i>=n;i--) b[i]=b[i+1]+w[i];
    map<int,int> mp;
    for (int i=2*n+1;i>n;i--) mp[b[i]]=i;
    int ans=1e9;
    for (int i=n;i>=0;i--)
    {
        int t=n-i;
        if (mp.find(-f[i])!=mp.end()) ans=min(ans,t+mp[-f[i]]-n-1);
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}