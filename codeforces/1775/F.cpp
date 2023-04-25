#include<bits/stdc++.h>
using namespace std;
int T,tp,mod,dp[4003];
int main(){
ios::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
cin>>T>>tp;
if(tp==2){
cin>>mod;
dp[0]=1;
for(int i=1;i<=4000;i++)
for(int j=0;j<4;j++)
for(int k=0;k<=4000-i;k++)
dp[k+i]=(dp[k+i]+dp[k])%mod;
}
while(T--){
int n;
cin>>n;
int ans=1e5,p=-1;
for(int i=1;i<=1000;i++)
if(ans>i+1+(n-1)/i)
ans=i+1+(n-1)/i,
p=i;
if(tp==1){
cout<<(n-1)/p+1<<' '<<p<<'\n';
for(int i=0;i<=(n-1)/p;i++){
for(int j=0;j<p;j++)
if(i*p+j<n)
cout<<'#';
else
cout<<'.';
cout<<'\n';
}
}else{
int sum=0;
for(int i=1;i<=1000;i++)
if(ans==i+1+(n-1)/i)
sum=(sum+dp[(n+i-1)/i*i-n])%mod;
cout<<ans*2<<' '<<sum<<'\n';
}
}
}
