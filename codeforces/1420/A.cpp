#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
 
    while(t--)
    {
        long n;
        bool flag=false;
        cin>>n;
 
        vector<long long>a(n,0);
 
 
        for(long i=0;i<n;i++)
            cin>>a[i];
 
        for(long i=1;i<n;i++)
         if(a[i]>=a[i-1])
         {
            flag=true;
 
            break;
         }
 
 
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
