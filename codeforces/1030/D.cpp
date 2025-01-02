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
      ll n,m,k;
      cin>>n>>m>>k;
      if((2*n*m)%k!=0){
        cout<<"NO\n";
        goto up;
      }
      cout<<"YES\n";
      ll g=__gcd(2*n,k);
      if(g==1){
        m=(2*m)/k;
      }
      else {
        n=(2*n)/g;
        m=(m*g)/k;
      }
      cout<<"0 0\n";
      cout<<n<<" "<<"0\n";
      cout<<"0 "<<m<<'\n';
    }
}
