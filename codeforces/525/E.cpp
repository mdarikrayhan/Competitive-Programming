// LUOGU_RID: 160214254
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,ans,mid,a[30],fac[30];
map<int,int>v[30];
void dfs1(int k,int sum,int cnt)
{
  if(sum>s) return;
  if(k>mid)
  {
    v[cnt][sum]++;
    return;
  }
  dfs1(k+1,sum,cnt);
  dfs1(k+1,sum+a[k],cnt);
  if(cnt<m&&a[k]<=18) dfs1(k+1,sum+fac[a[k]],cnt+1);
  return;
}
void dfs2(int k,int sum,int cnt)
{
  if(sum>s) return;
  if(k==mid)
  {
    for(int i=m-cnt;i>=0;i--) ans+=v[i][s-sum];
    return;
  }
  dfs2(k-1,sum,cnt);
  dfs2(k-1,sum+a[k],cnt);
  if(cnt<m&&a[k]<=18) dfs2(k-1,sum+fac[a[k]],cnt+1);
  return;
}
signed main()
{
  ios::sync_with_stdio(0);
  cin>>n>>m>>s;
  mid=n+1>>1;
  for(int i=1;i<=n;i++) cin>>a[i];
  fac[0]=1;
  for(int i=1;i<=18;i++) fac[i]=fac[i-1]*i;
  dfs1(1,0,0);
  dfs2(n,0,0);
  cout<<ans;
  return 0;
}