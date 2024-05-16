#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int>arr(n);
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      if(is_sorted(arr.begin(),arr.end())==true){
        cout<<"yes"<<endl;
      }
      else{
        //kisi bhi order me elemn do element nikal sakte hai;
        vector<int>ans;
        if(n%2==0){
          int i=0;
          int j=i+1;
          while(i<n && j<n ){
          if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            i+=2;
            j+=2;
          }
          else{
            ans.push_back(arr[j]);
            ans.push_back(arr[i]);
            i+=2;
            j+=2;
          }
          }
        }
        else {
          ans.push_back(arr[0]);
          int i=1;
          int j=i+1;
         while(i<n && j<n ){
          if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            i+=2;
            j+=2;
          }
          else{
            ans.push_back(arr[j]);
            ans.push_back(arr[i]);
            i+=2;
            j+=2;
          }
          }
          
        }
        
        
        if(is_sorted(ans.begin(),ans.end())==true){
          cout<<"yes"<<endl;
        }
        else{
          cout<<"no"<<endl;
        }
      }
      
    }
    return 0;
}
