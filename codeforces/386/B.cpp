/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=1;
    // cin>>t;
    while(t--)
  {
 
   int n;
   cin>>n;
  vector<int>v(n);
  for(auto &x:v) cin>>x;
  int t;
  cin>>t;
  int ans=-1;
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
{
    int num=upper_bound(v.begin(), v.end(), v[i]+t)-v.begin()-i;
    // cout<<num;
    ans=max(ans,num);
    
}  
   cout<<ans<<endl;

  
        
  
   
  
      
  }
   
        
    
    return 0;
}