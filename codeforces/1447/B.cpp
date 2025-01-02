#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--)
{
  int n,x,t,m=0,c=0;cin>>n>>x;n*=x;x=111;
  for(int i=0;i<n;i++){cin>>t;m+=abs(t);x=min(abs(t),x);if(t<0)c++;}
  cout<<(x&&c%2?m-2*x:m)<<'\n';
}}