#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
int sum[2010][26][2];
int dp[2010][2010];
void solve() {
    int n;
    cin>>n;
    string s[2];
    cin>>s[1]>>s[0];
    for(int i=0;i<=1;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<26;k++){
                sum[j][k][i]=sum[j-1][k][i]+((s[i][j-1]-'a')==k);
            }
        }
    } 
    for(int i=0;i<26;i++){
        if(sum[n][i][0]!=sum[n][i][1])  {cout<<"-1\n";return ;}
    }
    for(int i=1;i<=n;i++){
        int pre=i;
        dp[i][0]=i;
        bool flag=false;
        for(int j=1;j<=i;j++){
            flag|=(sum[j][s[1][j-1]-'a'][1]>sum[i][s[1][j-1]-'a'][0]);
            if(flag)    {dp[i][j]=-1;continue;}
            if(s[0][i-1]==s[1][j-1]&&dp[i-1][j-1]!=-1){
                if(pre>dp[i-1][j-1])   pre=dp[i-1][j-1];
            }
            dp[i][j]=pre;
            if(i-1>=j&&dp[i-1][j]!=-1)    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
        }
    }
    cout<<dp[n][n]<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
   			 	    	   		 	 			 	    	