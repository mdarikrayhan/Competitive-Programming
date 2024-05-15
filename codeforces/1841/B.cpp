#include <bits/stdc++.h>
using namespace std;
 
int main()
 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 int t=1;
cin>>t;
 while(t--)
  {
long long int n,i,x,mx=0,f=-1;
cin>>n;
string s="";
vector<long long int >v;
cin>>x;
v.push_back(x);
s+='1';
mx=v[0];

for(i=1; i<n; i++)
{
    cin>>x;
  if(x>=mx&&f==-1)
  {//cout<<x<<" "<<v.back();
      v.push_back(x);
      mx=max(mx,x);
s+='1';
  }
  else if(x<=v[0]&&f==-1)
  { //cout<<x;
       v.push_back(x);
       f=x;
       s+='1';
  }
  else if(x<=v[0]&&x>=f)
  {
       v.push_back(x);
       f=x;
       s+='1';
  }
  else
  s+='0';
}

  cout<<s<<"\n";
  }
  return 0;
}