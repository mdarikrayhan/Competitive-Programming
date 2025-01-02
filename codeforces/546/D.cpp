#include<bits/stdc++.h>
using namespace std;
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);


  // long long gcd(long long a,long long b){
  //    if(b==0)return a;
  //    else return gcd(b,a%b);
  // }
  
  // long long b_e(long long a,long long b,long long c){
  //  if(b==0)return 1;
   
  //   if(b%2==0){
  //     return b_e((a*a)%c,b/2,c)%c;
  //   }
  //   else {
  //     return ((a%c)*(b_e((a*a)%c,b/2,c))%c)%c;
  //   }
  // }
  // long long factorial (long long a){

  // }

  //  vector<bool>v(1e6+1,true);
  //   v[0]=false;
  //   v[1]=false;
  
  //   for(int i=2;i*i<=1e6;i++){
  //         if(v[i]==true)
  //          {
  //             for(int j=i*i;j<=1e6;j+=i){
  //              v[j]=false;
  //              }
  //          }
  //   }

  // bool prime(long long n){
  //    for(long long i=2;i*i<=n;i++){
  //     if(n%i==0)return false;
  //    }
  //    return true;
  // }

 
int main(){
     FASTIO
     
    vector<long long>v(5000002);
    for(int i=0;i<5000002;i++){
      v[i]=i;
    }

    for(int i=2;i*i<=5000002;i++){
      if(v[i]==i){
        for(int j=i*i;j<5000002;j+=i){
          if(v[j]>i)v[j]=i;
        }
      }
    }

    vector<long long>dp(5000002);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<5000002;i++){
       if((i/v[i])==1)dp[i]=dp[i/v[i]];
       else dp[i]=dp[i/v[i]]+1;
    }
    for(int i=1;i<5000002;i++){
      dp[i]+=dp[i-1];
    }
   
  
    
   long long test;
   cin>>test;
   while(test--){
    
    long long a,b;
    cin>>a>>b;

    long long ans=dp[a]-dp[b];

    

    cout<<ans<<endl;



   }

    

    

    
 
    


}

