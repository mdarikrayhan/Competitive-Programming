//JAI SHREE RAM 
//JAI BAJRANGBALI
//JAI MAHAKAL
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

#define int long long
int ceil2(int a, int b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}
bool monotonic(vector<int>&v,int k,int n){
  vector<int>temp;
  for(auto it:v){
    if((it<=k)||(it>=(n+1-k))){
      continue;
    }
    else{
    temp.push_back(it);
    }
  }
  for(int i=0;i<temp.size()-1;i++){
    if(temp[i]>temp[i+1])return false;
  }
  return true;
}
signed main(){
   
   ios::sync_with_stdio(false); cin.tie(NULL);
   int tc;
   cin>>tc;
   while(tc--){
    int a,b;
    cin>>a>>b;
    cout<<abs(a-b)<<" ";
    if(min(a,b)==0||abs(a-b)==0){
      cout<<0;
    }
    else{
      cout<<min(a%(abs(a-b)),(abs(a-b)-(a%(abs(a-b)))));
    }
    cout<<endl;
   }

 }
      

      
  



        
        
    

