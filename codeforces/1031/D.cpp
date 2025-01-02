#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1,tc1=1;
    //cin>>tc;
    up:
    while(tc--){
      ll n,k;
      cin>>n>>k;
      string s[n];
      for(ll i=0;i<n;i++){
        cin>>s[i];
      }
      ll dp[n][n];
      memset(dp,0,sizeof(dp));
      for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
          if(i==0&&j==0){
            if(s[i][j]=='a'){
              dp[i][j]=k;
              continue;
            }
            else {
              if(k!=0){
                dp[i][j]=k-1;
                s[i][j]='a';
              }
              else {
                dp[i][j]=0;
              }
            }
            continue;
          }
          if(i==0){
            if(s[i][j]=='a'){
              dp[i][j]=dp[i][j-1];
              continue;
            }
            if(dp[i][j-1]!=0){
              s[i][j]='a';
              dp[i][j]=dp[i][j-1]-1;
            }
            continue;
          }
          if(j==0){
            if(s[i][j]=='a'){
              dp[i][j]=dp[i-1][j];
              continue;
            }
            if(dp[i-1][j]!=0){
              s[i][j]='a';
              dp[i][j]=dp[i-1][j]-1;
            }
            continue;
          }
          if(s[i][j]=='a'){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            continue;
          }
          ll mx=max(dp[i-1][j],dp[i][j-1]);
          if(mx!=0){
            s[i][j]='a';
            dp[i][j]=mx-1;
          }
        }
      }
      map<pair<ll,ll>,ll>mp;
      string ans;
      ans.push_back(s[0][0]);
      mp[{0,0}]++;
      for(ll i=1;i<=2*n-2;i++){
        ll sti=max(0LL,i-n+1),stj=min(n-1,i);
        char mn='z';
        map<pair<ll,ll>,ll>mp1;
        ll tempi=sti,tempj=stj;
        while(1){
          if(sti>=n||sti<0||stj>=n||stj<0){
            break;
          }
          if(mp[{sti-1,stj}]!=0||mp[{sti,stj-1}]!=0){
            mn=min(mn,s[sti][stj]);
          }
          sti++,stj--;
        }
        ans.push_back(mn);
        sti=tempi,stj=tempj;
        while(1){
          if(sti>=n||sti<0||stj>=n||stj<0){
            break;
          }
          if((mp[{sti-1,stj}]!=0||mp[{sti,stj-1}]!=0)&&s[sti][stj]==mn){
            mp1[{sti,stj}]++;
          }
          sti++,stj--;
        }
        swap(mp,mp1);
      }
      cout<<ans<<'\n';
    }
}