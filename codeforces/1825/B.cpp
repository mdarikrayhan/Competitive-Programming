#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    vector<int>a(n*m+1);
    for(int i=1;i<=n*m;i++)cin>>a[i];
    sort(a.begin()+1,a.begin()+n*m+1);

    int len=max(n,m);
    int ben=min(n,m);
    //填min
    int ans=0;
    ans+=(len-1)*(a[n*m]-a[1]);
    ans+=(ben-1)*(a[n*m-1]-a[1]);
    ans+=(n-1)*(m-1)*(a[n*m]-a[1]);

    //填max
    int cnt=0;
    cnt+=(len-1)*(a[n*m]-a[1]);
    cnt+=(ben-1)*(a[n*m]-a[2]);
    cnt+=(n-1)*(m-1)*(a[n*m]-a[1]);
    cout<<max(cnt,ans)<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}