#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int two=0,five=0;
    int temp=n;
    while(temp>0 && temp%2==0)
    {
      temp=temp/2;
      two++;
    }
    while(temp>0 && temp%5==0)
    {
      temp=temp/5;
      five++;
    }
    int k=1;
    if(two<five)
    {
      while(k*2<=m && two<five)
      {
        k=k*2;
        two++;
      }
    }
    if(five<two)
    {
      while(k*5<=m && five<two)
      {
        k=k*5;
        five++;
      }
    }
    while(k*10<=m)
    {
      k=k*10;
    }
    int res=((m/k)*k);
    int ans=n*res;
    cout<<ans<<endl;
  }
}