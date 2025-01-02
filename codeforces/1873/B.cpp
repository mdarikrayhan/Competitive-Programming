#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
      cin>>n;
      int arr[n];
      for(int j=0;j<n;j++)
        cin>>arr[j];
      sort(arr,arr+n);
      arr[0]+=1;
      long long ans=1;
       for(int j=0;j<n;j++)
        ans=ans*arr[j];
       cout<<ans<<endl;
    }

return 0;
}
