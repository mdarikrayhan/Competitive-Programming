#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        
        ll a[n];
        ll b[m];
        
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for (int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        
        ll op=0;
        for(int i=0;i<m;i++)
        {
            op=op|b[i];
        }
        ll minans=0,maxans=0;
        
        for (int i=0;i<n;i++)
        {
            maxans=maxans^a[i];
            minans=minans^(a[i]|op);
        }
        
        cout<<min(minans,maxans)<<" "<<max(maxans,minans)<<endl;
        
        
    }
    return 0;
}
