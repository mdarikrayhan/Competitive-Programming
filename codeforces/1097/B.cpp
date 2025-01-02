#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define Y cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define yes1  cout<<"Yes"<<endl
#define no1  cout<<"No"<<endl
#define fr(i,n)  for(ll i=0;i<n;i++)
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define F first
#define S second
using namespace std;
const  int N=1e7+9;
ll i,j;
//ll p[N];
int main()
{
    fast;
    ll t=1,w=1;
    //cin>>t;
    while(t--)
    {
      ll n;
      cin>>n;
      ll a[n];
      for(i=0;i<n;i++)
      {
          cin>>a[i];
      }
      ll ok=0;
      for(i=0;i<(1<<n);i++)
      {
          ll s=0;
          for(j=0;j<n;j++)
          {
              if(i&(1<<j))
              {
                  s+=a[j];
              }
              else{
                s-=a[j];
              }
          }
          if(s%360==0)
          {
              ok=1;
              break;
          }
      }
      if(ok==1)
      {
          Y;
      }
      else{
        no;
      }


        //cout<<"ok"<<endl;
        //cout<<"Case"<<" "<<w++<<":"<<" "<<ok<<endl;
    }
}
