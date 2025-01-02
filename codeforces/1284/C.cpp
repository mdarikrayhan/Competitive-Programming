#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<string>
#include <cmath>
 
using namespace std;
 
 
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
   long long n,m;
   cin>>n>>m;
   if(n==1)
   {
    cout<<1<<endl;
    return 0;
   }
   vector<long long >fact(n+1,0);
   fact[0]=1;
   fact[1]=1;

   for(int i=2;i<=n;i++)
   {
    fact[i]=((fact[i-1]%m)*(i%m))%m;

   }

   long long total=0;

   for(int i=n;i>=1;i--)
   {
   long long frag=((i%m));
      frag=((frag%m)*(fact[n-i+1]%m))%m;
      frag=((frag%m)*(fact[i-1]%m))%m;
      frag=((frag%m)*(i%m))%m;
      total=((total%m)+(frag%m))%m;


   }  
   cout<<total<<endl;
}