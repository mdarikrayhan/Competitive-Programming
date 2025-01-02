#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    string s,t;
    cin>>s;
    cin>>t;
    int sz1=s.size(),sz2=t.size();
    vector<int> del(sz1+1);
    for(int i=sz1-1;i>=0;i--){
        int len=0;
        if(s[i]=='.')   {del[i+1]=sz1+1;continue;}
        for(int j=i;j<sz1;j++){
            if(s[j]=='.')   len--;
            else len++;
            if(len==0)  {del[i+1]=j+1;break;}
        }
        if(len!=0)  del[i+1]=sz1+1;
    }
    vector<vector<int>> dp(sz1+1,vector<int>(sz2+1,-1));
    auto ckmin=[&](int a,int b)->int {
        if(a==-1)   return b;
        if(b==-1)   return a;
        return min(a,b);
    };
    dp[0][0]=0;
    for(int i=1;i<=sz1;i++){
        for(int j=0;j<=sz2;j++){
            if(dp[i-1][j]!=-1){
                dp[i][j]=ckmin(dp[i][j],dp[i-1][j]+1);
                if(j!=sz2&&s[i-1]==t[j]){
                    dp[i][j+1]=ckmin(dp[i][j+1],dp[i-1][j]);
                }
                if(s[i-1]!='.'&&del[i]!=sz1+1){
                    dp[del[i]][j]=ckmin(dp[del[i]][j],dp[i-1][j]);
                }
            }
        }
    }
    cout<<dp[sz1][sz2]<<'\n';

}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}