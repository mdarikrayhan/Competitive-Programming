#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Solve() 
{
    int n;
    cin>>n;
    vector<ll> d(n),l(n),r(n),sum(n,0);
    for(int i=0; i<n; i++)
        cin>>d[i],sum[i]=d[i],sum[i]+=(i)?sum[i-1]:0;
    for(int i=0; i<n; i++)
        cin>>l[i],l[i]-=sum[i];
    for(int i=0; i<n; i++)
        cin>>r[i],r[i]-=sum[i];
    ll a[n+1],b[n+1];
    cin>>a[0]>>b[0];
    tuple<ll,ll,int> t[n];
    for(int i=0; i<n; i++)
        t[i]={l[i],-r[i],i};
    sort(t,t+n);
    ll mx=-(ll)1e18,x=0,mn=b[0];
    for(int i=0; i<n; i++)
    {
        if(mn+min(a[0],get<0>(t[i]))>mx)
        {
            mx=mn+min(a[0],get<0>(t[i]));
            x=i-1;
        }
        mn=min(mn,-get<1>(t[i]));
    }
    if(mn+a[0]>mx)
    {
        mx=mn+a[0];
        x=n-1;
    }
    vector<int> v;
    for(int i=0; i<=x; i++)
    {
        v.push_back(get<2>(t[i]));
    }
    sort(v.begin(),v.end());
    int j=0;
    for(int i=0; i<n; i++)
    {
        a[i+1]=a[i]+d[i];
        b[i+1]=b[i]+d[i];
        if(j<v.size()&&v[j]==i)
        {
            b[i+1]=min(b[i+1],r[i]+sum[i]);
            j++;
        }
        else 
        {
            a[i+1]=min(a[i+1],l[i]+sum[i]);
        }
    }
    cout<<a[n]+b[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while (t--) 
        Solve();
    return 0;
} 
