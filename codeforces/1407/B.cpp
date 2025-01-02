#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ll t,n,i,j,k,ct1;
cin>>t;
while(t--){
cin>>n;
ll v[n];
for(i=0;i<n;i++)
cin>>v[i];
k=0;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(__gcd(v[i],k)<__gcd(v[j],k))
swap(v[i],v[j]);
}
cout<<v[i]<<" ";
k=__gcd(v[i],k);
}
}
}