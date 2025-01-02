#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1,tc1=1;
    //cin>>tc;
    up:
    while(tc--){
      ll n,m;
      cin>>n>>m;
      ll a[n+5][m+5];
      for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
          cin>>a[i][j];
        }
      }
      ll tr=1;
      for(ll i=1;i<=n;i++){
        ll tot=0;
        for(ll j=1;j<=m;j++){
          if(a[i][j]!=j){
            tot++;
          }
        }
        if(tot>2){
          tr=0;
        }
      }
      if(tr==1){
        cout<<"YES\n";
        goto up;
      }
      for(ll swi=1;swi<=m;swi++){
        for(ll swj=swi+1;swj<=m;swj++){
          for(ll i=1;i<=n;i++){
            swap(a[i][swi],a[i][swj]);
          }
          ll mx=0;
          for(ll i=1;i<=n;i++){
            ll tot=0,tr=1;
            for(ll j=1;j<=m;j++){
              if(a[i][j]!=j){
                tot++;
              }
            }
            mx=max(mx,tot);
          }
          if(mx<=2){
            //cout<<swi<<' '<<swj<<'\n';
            cout<<"YES\n";
            goto up;
          }
          for(ll i=1;i<=n;i++){
            swap(a[i][swi],a[i][swj]);
          }
        }
      }
      cout<<"NO\n";
    }
}
