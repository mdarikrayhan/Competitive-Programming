#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll min(ll a, ll b){
    if(a<b){
        return a;
    }
    return b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        ll recent=1000000000000000;
        vector<ll> dp(n+5,0);
        ll recent1=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                dp[i+3]=dp[i+2];
                recent=1000000000000000;
            }
            else{
                
                dp[i+3]=dp[i]+i+1;
                
                
            }
        }
        ll ans=0;
        for(int i=3;i<=n+2;i++){
        //   cout<<dp[i]<<" ";
           ans+=dp[i];
        }
        cout<<ans<<"\n";
    }
}