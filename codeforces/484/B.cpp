#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn];


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int nn=unique(a+1,a+1+n)-a-1;
    
    int ans=0;
    
    for(int i=1;i<=nn;i++)
    {
        //cout<<"i="<<i<<endl;
        for(int j=a[i];j-a[i]<=a[nn];j+=a[i])
        {
            int fd=a[lower_bound(a+1,a+1+nn,j)-a-1];
            //cout<<"j="<<j<<' '<<fd<<'\n';
            if(fd>j-a[i]&&fd>a[i])ans=max(ans,fd-j+a[i]);
        }
    }
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;//cin>>t;
    while(t--)
    {
        solve();
    }
}