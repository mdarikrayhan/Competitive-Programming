#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define in(vi) for(auto &input: vi) cin>>input;
#define ll long long int

void solve()
{
   ll n;  cin>>n;
   
   vector<int> arr[n];
   
   ll i = 1, j = n*n;
   
   while(j > i)
   {
       for(int k = 0; k<n; k++)
       {
           arr[k].push_back(i); i++;
       }
       
       while(j > i)
       {
           for(int k = 0; k<n; k++)
           {
               arr[k].push_back(j); j--;
           }
           break;
       }
   }
   
   for(auto x: arr)
   {
       for(auto y: x) cout<<y<<" ";
       cout<<'\n';
   }
}




int main()
{
    //int t;
    //cin>>t;
    
    //while(t--)
    solve();
}