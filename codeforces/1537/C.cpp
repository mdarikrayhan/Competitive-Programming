#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
 int n;
 cin >> n;
 vector<int> v(n);
 vector<int> a;
 vector<int> b;
 for(int i=0;i<n;i++)
 {
     cin >> v[i];
 }
 for(int i=0;i<n;i++)
 {
     a.push_back(v[i]);
 }
 sort(v.begin(),v.end());
 sort(a.begin(),a.end());
  int count=1;
  for(int i=1;i<n;i++)
  {
      if(v[i]!=v[i-1])
      {
          count++;
      }
  }
  int m=INT_MAX;
  int r,s;
  if(count==n)
  {
     for(int i=1;i<n;i++)
     {
         int p=v[i]-v[i-1];
         if(p<m)
         {
             m=min(p,m);
             r=i-1;
             s=i;
         }
     }
     b.push_back(v[r]);
  
  for(int i=r+2;i<n;i++)
  {
      b.push_back(v[i]);
  }
  if(r!=0)
  {
      for(int i=0;i<r;i++)
      {
          b.push_back(v[i]);
      }
      b.push_back(v[s]);
  }else
  {
      b.push_back(v[s]);
  }
  for(int i=0;i<n;i++)
  {
      cout << b[i] << " ";
  }cout << endl;
  return;
  }
  int x,y;
  for(int i=1;i<n;i++)
  {
      if(v[i]==v[i-1])
      {
          x=i-1;
          y=i;
          break;
      }
  }

  vector<int> v1;
  v1.push_back(a[x]);
  
  for(int i=x+2;i<n;i++)
  {
      v1.push_back(a[i]);
  }
  if(x!=0)
  {
      for(int i=0;i<x;i++)
      {
          v1.push_back(a[i]);
      }
      v1.push_back(a[y]);
  }else
  {
      v1.push_back(a[y]);
  }
  for(int i=0;i<n;i++)
  {
      cout << v1[i] << " ";
  }cout << endl;
  
   
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}