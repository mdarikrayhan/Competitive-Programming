#include<bits/stdc++.h>
using namespace std;
int t,s[2003],ans[2003],n,x;
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=1;i<=n;++i){
cin>>x;
s[x]=i;
}
for(int i=n;i>=1;--i){
ans[i]=s[i]%i;
for(int j=1;j<i;++j){
s[j]=(s[j]+i-ans[i])%i;
}
}
for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
cout<<endl;
}
}