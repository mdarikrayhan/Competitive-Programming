#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define all(a) a.begin(),a.end()
#define nl "\n"

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll t; cin>>t;
    f(i,0,t,1){
      ll n,k,x; cin>>n>>k>>x;
      ll a=n/2;
      if(k==1 && x==1) cout<<"NO"<<nl;
      else if(x!=1){
          cout<<"YES"<<nl;
          cout<<n<<nl;
          f(i,0,n,1) cout<<1<<" ";
          cout<<nl;
      }
      else if(k==2 && n%k==1) cout<<"NO"<<nl;
      else if(k==2 && n%k==0){
          cout<<"YES"<<nl;
          cout<<a<<nl;
          f(i,0,a,1) cout<<2<<" ";
          cout<<nl;
      }
      else {
          if(n%2==0){
             cout<<"YES"<<nl;
             cout<<a<<nl;
             f(i,0,a,1) cout<<2<<" ";
             cout<<nl;
          }
          else{
              cout<<"YES"<<nl;
              cout<<a<<nl;
              f(i,0,a-1,1) cout<<2<<" ";
              cout<<3<<nl;
          }
      }
    }
    return 0;
}
