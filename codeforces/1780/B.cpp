#include<bits/stdc++.h>
using namespace std;
int t,n,a[600001];
int main(){
cin>>t;
while(t--){
cin>>n;
long long ans=1,tot=0,now=0;
for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i];
for(int i=1;i<n;i++) now+=a[i],ans=max(ans,__gcd(tot-now,now));
cout<<ans<<endl;
}
}