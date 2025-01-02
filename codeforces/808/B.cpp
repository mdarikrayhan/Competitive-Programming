#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

signed main()
{
    fastio;
    int n,k,ans=0,slp=0,i,j;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(i=0;i<k;i++)
    slp+=arr[i];
    ans=slp;
    
    for(i=k;i<n;i++)
    {
        ans+=(slp-arr[i-k]+arr[i]);
        slp=slp-arr[i-k]+arr[i];
    }
    //cout<<ans<<" ";
        
    float res=float(ans)/float(n-k+1);
    cout<<fixed<<setprecision(6)<<res<<endl;
}