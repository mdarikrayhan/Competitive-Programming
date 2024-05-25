#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
   int n;
   cin>>n;
   vector<int>num(n,0);
   for(auto &i:num)cin>>i;

   vector<int>v;
   v.push_back(num[0]);
   for(int i=1;i<n;i++){
    if(num[i]==0){v.push_back(0);continue;}

    if(v.back()==0){
        v.push_back(num[i]);
    }
    else {
     if(num[i]>=v.back())v.back()=num[i];
    }
   }

//    for(auto &i:v)cout<<i<<" ";
   int m=v.size();

   int ans=0;
   vector<bool>used(m,false);

   for(int i=0;i<m;i++){
      if(v[i]==2){
        used[i]=true;
        if(i-1>=0)used[i-1]=true;
        if(i+1 <m)used[i+1]=true;
        ans++;
      }
   }

//     for(int i=0;i<m;i++){
//         cout<<used[i]<<" ";
//   }
//   cout<<"ans "<<ans<<endl;

   for(int i=0;i<m;i++){
    if(v[i]==1){
        
        used[i]=true;
        ans++;
  

        if(i-1>=0 and used[i-1]==false and v[i]==1)used[i-1]=true,v[i]--;
        if(i+1<m and used[i+1]==false and v[i]==1)used[i+1]=true;
       
    }
   }

//      for(int i=0;i<m;i++){
//         cout<<used[i]<<" ";
//   }
//   cout<<"ans "<<ans<<endl;


  for(int i=0;i<m;i++){
    if(!used[i])ans++;
  }
cout<<ans<<endl;


   
}


signed main(){
    int t;
    // cin>>t;
    t=1;

    while (t--)
    {
         solve();
        /* code */
    }
    
}