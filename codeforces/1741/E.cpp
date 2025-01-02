#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> OMS;
 
const int   N                               = (int) 1e7;
const int   M                               = (int) 1e9+5;
const int   mod                             = (int) 1000000007;
const int   max_prime                       = (int) 1e6+3;
const int   BLKs                            = (int) 70000;
const int   BLKspan                         = (int) 700;
 
#define ll                                  long long int
#define Faster                              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

// sieve starts
// vector<ll>mark(N+1);
// vector<ll>adj[N+1];
// void sieve(){
    
//     iota(mark.begin(), mark.end(), 0);
//     // mark[0]=0,mark[1]=0,mark[2]=2;
//     for(ll i=4;i<=N;i+=2LL){
//          mark[i]=2;
     
//     }
//     for(ll i=3;i*i<=N;i+=2LL){
//         if(mark[i]==i){
//             for(ll j=i*i;j<=N;j+=i){
//                 if(mark[j]==j){
//                       mark[j]=i;
//                 }
              
//             }
//         }
//     }
//     for(int i= 2;i<=N;i++){
//         ll num = i;
//         while(num>1){
//             ll x = mark[num];
//             while(num%x==0){
//                 num/=x;
//             }
//             adj[i].push_back(x);
//         }
//     }
// }


void solve(){
  ll n;
  cin>>n;
  vector<ll>v(n+1);
  v.push_back(0);
  for(int i = 0;i<n;i++){
      cin>>v[i+1];
  }
  vector<ll>dp(n+1,0);
  dp[0]=1;
  for(int i = 1;i<=n;i++){
      if(i-(v[i]+1)>=0&&dp[i-(v[i]+1)]){
          dp[i]=1;
      }
      if(i+(v[i])<=n&&dp[i-1]==1){
          dp[i+v[i]]=1;
      }
  }
 if(dp[n]==1){
     cout<<"YES"<<endl;
     
 }
 else{
     cout<<"NO"<<endl;
 }


}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   ll t;
   cin>>t;
   while(t--){
     
       solve();
   }

}