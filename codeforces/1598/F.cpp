#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++)cin>>s[i];
  vector<int>full_balance(n);
  vector<int>min_val(n);
  vector<vector<vector<int>>>p_b(n);
  for(int i=0;i<n;i++)
  {
      p_b[i].resize(s[i].size()+1);
      int b=0;
      for(int j=0;j<s[i].size();j++)
      {
          b+=(s[i][j]=='('?1:-1);
          if(b<=0)p_b[i][-b].push_back(j);
          min_val[i]=min(min_val[i],b);
      }
      full_balance[i]=b;
      for(auto &x:p_b[i])sort(x.begin(),x.end());
  }
  vector<int>dp(1<<n,-1e9);
  dp[0]=0,dp[(1<<n)-1]=0;
  for(int i=0;i<(1<<n);i++)
  {
      int cur_b=0;
      for(int j=0;j<n;j++)if(i&(1<<j))cur_b+=full_balance[j];
      if(cur_b<0)continue;
      for(int j=0;j<n;j++)
        if(!(i&(1<<j)))
      {
          if(min_val[j]<-cur_b)
          {
              dp[(1<<n)-1]=max(dp[(1<<n)-1],dp[i]+(int)(lower_bound(p_b[j][cur_b].begin(),p_b[j][cur_b].end(),p_b[j][cur_b+1][0])-p_b[j][cur_b].begin()));
          }
          else if(min_val[j]==-cur_b)
          {
              dp[i+(1<<j)]=max(dp[i+(1<<j)],dp[i]+(int)p_b[j][cur_b].size());
          }
          else dp[i+(1<<j)]=max(dp[i+(1<<j)],dp[i]);
      }
  }
  cout<<dp[(1<<n)-1];
}