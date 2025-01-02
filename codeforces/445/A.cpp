#include <bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
  int n,m;

  cin>>n>>m;
  vector<vector<char>> vec( n , vector<char> (m));  
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
        cin>>vec[i][j];
     }
  }

   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      if(vec[i][j]=='.')
       vec[i][j]='B';
       else
       vec[i][j]='-';
    }
   }

   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      if(i%2==0 && vec[i][j]!='-' && j%2!=0)
      {
        vec[i][j]='W';
      }
      if(i%2!=0 && vec[i][j]!='-' && j%2==0)
       vec[i][j]='W';
    }
   }
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
      cout<<vec[i][j];
    }
    cout<<endl;
   }

    return 0;
}
