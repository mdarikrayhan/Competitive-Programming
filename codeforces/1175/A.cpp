#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll i=0; i<t; i++)
    {
        ll cnt=0,val,ans;
        ll n,k;
        cin>>n>>k;
        while(n!=0)
        {
            if(n%k==0)
            {
                cnt++;
                n=n/k;
            }
            else if(n%k!=0)
            {
               val=n/k;
               ans=n-(val*k);
               n=val*k;
               cnt=cnt+ans;

            }
        }
        cout<<cnt<<endl;


    }

}
