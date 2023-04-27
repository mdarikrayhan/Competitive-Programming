#include<bits/stdc++.h>
int t,n,i,a[200007],m,b[200007],f;
using std::cin;
int main(){
for(cin>>t; t--; puts(f?"NO":"YES")){
for(cin>>n,i=f=0; i++<n;)
cin>>a[i],b[i]=a[i];
for(std::sort(a,a+i); i--;)
f+=(a[i]^b[i]&&b[i]%a[1]);
}
return 0;
}