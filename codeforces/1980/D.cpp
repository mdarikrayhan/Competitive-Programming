#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int idx,vector<int>a){
         a.erase(a.begin()+idx);
         vector<int> v1;
        for(int i=0; i<a.size()-1; i++){
         v1.push_back(__gcd(a[i],a[i+1]));
        }
        if(is_sorted(v1.begin(),v1.end())) return true;
        else return false;      
}

int main()
{
   int t;
   cin>>t;
   while (t--)
   {
      int n;
      cin>>n;
      vector<int> a(n);
      for(int i=0; i<n; i++){cin>>a[i];}
      vector<int> v;
      for(int i=0; i<n-1; i++){
         v.push_back(__gcd(a[i],a[i+1]));
      }
      if(is_sorted(v.begin(),v.end())){
         cout<<"YES"<<endl;
         continue;
      }
      int idx=0;
      for(int i=0; i<v.size()-1; i++){
         if(v[i]>v[i+1]){
            idx=i;
            break;
         }
      }
      if(check(idx,a)|| check(idx+1,a)||check(idx+2,a)){
        cout<<"YES"<<endl;
      }
      else cout<<"NO"<<endl;
      
    
   }

return 0;
}