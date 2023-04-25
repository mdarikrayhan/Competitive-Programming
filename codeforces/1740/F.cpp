#include<bits/stdc++.h>
typedef long long ll;
enum{N=2013,mod=998244353};
ll a[N],t[N],c[N],n,dp[N][N],r;
int main(){
    std::cin>>n;dp[0][0]=1;
    for(int i=1,x;i<=n;i++)std::cin>>x,t[++c[x]]++;
    for(int i=1;i<=n;i++)t[i]+=t[i-1];
    for(int v=n;v;v--)for(int j=1;j*v<=n;j++)for(int k=v*j;k<=t[j];k++)(dp[j][k]+=dp[j-1][k-v])%=mod;
    for(int i=1;i<=n;i++)(r+=dp[i][n])%=mod;std::cout<<r<<'\n';
}