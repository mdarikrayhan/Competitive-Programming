#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans=1e19,i,j,s,l,k;
int main(){
cin>>n;
for(i=1;i<=n;i++) cin>>a[i];
for(i=1;i<=n;i++){
s=0,l=0;
for(j=i-1;j>=1;j--){
k=l/a[j]+1;
s+=k,l=k*a[j];
}
l=0;
for(j=i+1;j<=n;j++){
k=l/a[j]+1;
s+=k,l=k*a[j]; 
}
ans=min(ans,s);
}
cout<<ans;
}