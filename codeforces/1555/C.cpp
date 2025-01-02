#include<bits/stdc++.h>
using namespace std;
int t;int n,a[100010],b[100010];
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i];
a[i]+=a[i-1];
}
for(int i=1;i<=n;i++){
cin>>b[i];
b[i]+=b[i-1];
}
int ans=INT_MAX;
for(int i=1;i<=n;i++){
ans=min(ans,max(a[n]-a[i],b[i-1]));
}
cout<<ans<<endl;
}
}