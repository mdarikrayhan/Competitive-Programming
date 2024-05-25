// LUOGU_RID: 160125060
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn];
int s1[maxn],s2[maxn];
signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n,i,ans=0,cnt=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        s1[i]=s1[i-2]+a[i];
    }
    for(i=n;i>=1;i--)
    {
        s2[i]=s2[i+2]+a[i];
    }//////////////////////
    for(i=1;i<=n;i++)
    {
        ans=max(ans,s2[i]+s1[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
