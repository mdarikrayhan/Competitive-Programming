#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
 map<ll , ll>mp;
ll  my_sqrt(long long a)
{
    ll  l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
ll solve(ll x,ll y)
{
    ll d=(ll)(x*x)-(ll)(4*y);
    if (d<0) return 0;
    ll x1=(ll)(x-my_sqrt(d))/(ll) (2);
    ll x2=(ll)(x+my_sqrt(d))/(ll) (2);
    if (x1+x2!=x || (ll) (x1*x2) != y) {return 0;}
    if (x1==x2) {return  (ll)(mp[x1])* (mp[x1]-1)/(ll) 2;}
    else return mp[x1]*mp[x2];
}

ll a[200200]; int q,n;


int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i]; mp[a[i]]++;
        }

        cin>>q;
        while (q--)
        {
            ll x,y;
            cin>>x>>y;
            ll ans=0;
            ans=solve(x,y);

            cout <<ans<<endl;

        }
     mp.clear();
    }




}