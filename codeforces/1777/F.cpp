#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#include <iostream>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1,n,a[200000],res,mx,s;
    cin>>t;
    for(int q=1; q<=t; q++)
    {
        cin>>n;res=mx=s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);s^=a[i];
            res=max(res,(s^mx));
        }
        for(int i=1;i<n;i++)
        {
            mx=0;s=0;
            for(int j=i;j<(i<5000?n:min(n,i+50000));j++)
            {
                mx=max(mx,a[j]);s^=a[j];
                res=max(res,(s^mx));
            }
        }
        cout<<res<<endl;
    }
}