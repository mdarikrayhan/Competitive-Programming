#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int t;
  cin>>t;
  
  while(t--){
    
    long long n,ans=0;
    cin>>n;
    
    vector<int> arr;
    priority_queue<int> q;
    
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      q.push(x);
      if(x==0){
        ans+=q.top();
        q.pop();
      }
    }
    
    
    cout<<ans<<endl;
    
  }
  
  return 0;
}