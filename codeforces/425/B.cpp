#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,x;
bitset<102> M[101],b;
int main()
{
  cin>>n>>m>>k,ans=2e9;
  for(int i=0;i<n;i++) 
  for(int j=0;j<m;j++)
  {
    scanf("%d",&x);
    if(x)M[i].set(j);
  }
  if(n<=k)
  {
    for(int s=0;s<(1<<n);s++)
    {
      int t=0;
      for(int i=0;i<m;i++)
      {
        int cnt=0;
        for(int j=0;j<n;j++)cnt+=(M[j][i]!=((s>>j)&1));
        t+=min(cnt,n-cnt);
      }
      ans=min(ans,t);
    }
  }
  else 
  {
    for(int i=0;i<n;i++)
    {
      int t=0;
      for(int j=0;j<n;j++)
      if(j!=i)
      {
        auto t1=M[i]^M[j];
        t+=min(t1.count(),m-t1.count());
      }
      ans=min(ans,t);
    }
  }
  if(ans>k)puts("-1");
  else cout<<ans;
  return 0;
} 