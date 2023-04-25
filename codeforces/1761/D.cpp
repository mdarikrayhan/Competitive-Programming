#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,k;
ll ans,fc[1000005];
ll qp(ll a,int b) {
if(b<0)return 0;
ll ans=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
return ans;
}
ll c(int n,int m){return n<m?0:fc[n]*qp(fc[m]*fc[n-m]%mod,mod-2)%mod;}
int main() {
cin>>n>>k,fc[0]=1;
if(!k)return cout<<qp(3,n),0;
for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
for(int i=1;i<=n+1>>1;i++)ans=(ans+c(k-1,i-1)*(c(n-k,i-1)*qp(3,n-2*i+1)%mod+c(n-k,i)*qp(3,n-2*i)%mod))%mod;
cout<<ans;
return 0;
}