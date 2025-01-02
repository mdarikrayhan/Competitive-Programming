#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff '\n'
#define  all(v)   v.begin(), v.end()
#define  rall(v)  v.rbegin(),v.rend()
#define  pb       push_back









void solve()
     {
        int n;
        cin>>n;
        int sum=0, t=n-1;
        for(int i=1; i<=n-1; i++)  
        {
         sum+= i*t;
         t--;
        } 
        
        cout<<sum+n<<ff;   
      }
     
 int main()
    {
       solve(); 
   }
