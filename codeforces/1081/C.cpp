#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using ll = long long;
ll mod= 998244353;
void solve(){
    int t=1;
    while(t--){
        int N,M,K;
        cin>>N>>M>>K;
        std::vector<vector<ll>> dp(N+1,vector<ll>(K+1));
        dp[N][0]=1;
        for(int i=N-1;i>=0;i--){
            for(int k=0;k<=K;k++){
                if(i==0) dp[i][k]=(M*dp[i+1][k])%mod;
                else dp[i][k]=(((M-1)*(k>0 ? dp[i+1][k-1]:0)%mod)+dp[i+1][k])%mod;
            }
        }
        cout<<(dp[0][K] + mod)%mod<<"\n";
    }
}
int main(){
    fastio();
    solve();
}