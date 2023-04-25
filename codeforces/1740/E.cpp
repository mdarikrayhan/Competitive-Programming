#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;cin>>n;
    vector<int> p(n+1),dp(n+1),h(n+1,1);
    for(i=2;i<=n;i++) cin>>p[i];
    for(i=n;i>=1;i--){
        dp[i]=max(dp[i],h[i]);
        dp[p[i]]+=dp[i]; h[p[i]]=max(h[p[i]],h[i]+1);}
    cout<<dp[1]<<endl;
}