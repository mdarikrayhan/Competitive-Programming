#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
         vector<ll>a(n),b(n);
         ll ze=0,on=0;
         for(ll i=0;i<n;i++)
         cin>>a[i];
         for(ll i=0;i<n;i++)
         {
         cin>>b[i];
         if(b[i]==1)
         on++;
         else
         ze++;
         }
         if(is_sorted(a.begin(),a.end()) || (on>0 && ze>0))
         {
            cout<<"Yes"<<endl;
            
         }
         else
         cout<<"No"<<endl;
        //  vector<pair<ll,ll>>p;
        //  map<ll,ll>m;
        //  for(ll i=0;i<n;i++)
        //  {
        //  p.pb({a[i],b[i]});
        //  }
        //  sort(p.begin(),p.end());
        //  for(auto it:p)
        //  cout<<it.ff<<" "<<it.ss<<endl;
        //  ll cnt=0;
        //  ll f=0;
        //  for(ll i=0;i<n;i++)
        //  {
        //     if(p[i].ff!=a[i])
        //     {
        //         if(p[i].ss!=b[i])
        //         cnt++;
        //         else
        //         f=1;
        //     }
        //  }
        //  if(f==0)
        //  cout<<"Yes"<<endl;
        //  else
        //  cout<<"No"<<endl;
    }
    
    return 0;
}