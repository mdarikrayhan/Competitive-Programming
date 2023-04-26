#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n,i,x;
cin>>t;
while(t--){
cin>>n>>x;
int a[n],b[n],ans=1;
for(i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
sort(b,b+n);
for(i=n-x;i<x;i++){if(b[i]!=a[i]){ans=0;}}
ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
}