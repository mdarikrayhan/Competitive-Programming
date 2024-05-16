#include <bits/stdc++.h>
using namespace std;

long long solve(int i,long long bitmask,vector<long long> &fact,long long n,vector<vector<long long>> &dp){
    if(i==fact.size()){
        long long sum=0;
        for(int j=0;j<14;j++){
            if(((bitmask>>j)&1)==1){
                sum+=fact[j];
            }
        }
        // int temp=n-sum;
        // if(temp<0){
        //     return INT_MAX;
        // }
        return __builtin_popcountll(n-sum)+__builtin_popcount(bitmask);
    }
    if(dp[i][bitmask]!=-1){
        return dp[i][bitmask];
    }
    long long ans=INT_MAX;
    long long temp=INT_MAX;
    if(((bitmask>>i)&1)==0){
        temp=solve(i+1,bitmask|(1<<i),fact,n,dp);
    }
    ans=min(ans,min(temp,solve(i+1,bitmask,fact,n,dp)));
    return dp[i][bitmask]=ans;
}

int main(){
    int t;
    cin>>t;
    vector<long long> fact;
    long long curr=1;
    for(int i=1;i<=14;i++){
        curr*=i;
        // cout<<curr<<endl;
        fact.push_back(curr);
    }
    while(t--){
        long long n;
        cin>>n;
        vector<vector<long long>> dp(14,vector<long long>(1<<15,-1));
        cout<<solve(0,0,fact,n,dp)<<endl;
    }
}