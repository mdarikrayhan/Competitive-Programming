#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
 int n,i,a[105],b[105],c[105],k=0;
 cin>>n;
 for(i=0;i<n;i++)cin>>a[i];
 for(i=0;i<n;i++){
  cin>>b[i];
  if(!b[i])c[k++]=a[i];
 }
 sort(c,c+k);
 k--;
 for(i=0;i<n;i++){
  int j;
  if(b[i])cout<<a[i]<<" ";
  else cout<<c[k--]<<" ";
 }
 cout<<endl;
}
 return 0;
 }