#include<bits/stdc++.h>
using namespace std;
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
   
     vector<long long> factorise(long long x,long long & k,vector<long long>& v){
      vector<long long>temp;
      while(x!=1){
      temp.push_back(v[x]);
      long long count=0;
      long long z=v[x];
      while(x%z==0 and x!=1){
        x/=z;
        count++;
      }
      if(count%k==0){
        temp.pop_back();
      }
      else{
        temp.push_back(count%k);
      }
     
    
      }

      if((int)temp.size()==0)return {0};
      return temp;
      


      
    }
    vector<long long> inplace(vector<long long> &v,long long & k){
    vector<long long>temp;
    for(int i=0;i<(int)v.size();i++){
      if(i%2==0){
        temp.push_back(v[i]);
      }
    else{
      temp.push_back((k-v[i])%k);
    }
    }
    return temp;
    }
    

 
int main(){
     FASTIO
     
      vector<long long>v(100005);
    for(int i=0;i<100005;i++){
      v[i]=i;
    }
    for(int i=2;i*i<=100005;i++){
      for(int j=i;j<100005;j+=i){
        if(v[j]>=i){
          v[j]=i;
        }
      }
    }
    

    
    long long n,k;
    cin>>n>>k;


   vector<long long>arr(n);
   map<vector<long long>,long long>m;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    m[factorise(arr[i],k,v)]=0;
   }
   
    

   long long ans=0;
  
   for(int i=0;i<n;i++){
      vector<long long>t=factorise(arr[i],k,v);
       ans+=m[inplace(t,k)];
       m[factorise(arr[i],k,v)]++;
   }

   cout<<ans<<endl;

   

   }