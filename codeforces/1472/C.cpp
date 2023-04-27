#include<iostream>
using namespace std;
int main(){
int t,n,i,a[200005],mx=0;
cin>>t;
while(t--){
mx=0;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];
}
for(i=n;i>=1;i--){
if(i+a[i]<=n) a[i]=a[i]+a[i+a[i]];
if(mx<a[i]) mx=a[i];
}
cout<<mx<<endl;
}
}