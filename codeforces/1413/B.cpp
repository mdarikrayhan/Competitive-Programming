#include<bits/stdc++.h>
using namespace std;
int a[250010],p[510][510],T,n,m;
int main()
{
 cin>>T;
 while(T--)
 {
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  for(int j=1,x;j<=m;j++)
   cin>>x,a[x]=j;
  for(int i=1;i<=m;i++)
  for(int j=1,x;j<=n;j++)
   cin>>x,p[j][a[x]]=x;
  for(int i=1;i<=n;i++,cout<<endl)
  for(int j=1;j<=m;j++)
   cout<<p[i][j]<<" ";
  }
 return 0;
}