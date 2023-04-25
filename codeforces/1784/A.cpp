#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
long long ans=0;
for(int i=1;i<=n;i++){
if(a[i]<=a[i-1]+1)continue;
ans+=a[i]-a[i-1]-1;
a[i]=a[i-1]+1;
}
cout<<ans<<endl;
}
}