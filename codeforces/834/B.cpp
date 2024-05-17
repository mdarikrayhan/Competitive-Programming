#include <iostream>
#include<bits/stdc++.h>
using namespace std;
  map<char,int>mp;
  set<char>en;
int main()
{

   int n,k;
   string s;

   cin>>n>>k>>s;
   for(int i=0;i<n;i++)
   {
     mp[s[i]]=i;

   }
        for(int i=0;i<n;i++)
   {
     en.insert(s[i]);

     if(en.size()>k){
        cout<<"YES"<<endl;
return 0;
     }
   if(mp[s[i]]==i)
    en.erase(s[i]);
   }
cout<<"NO"<<endl;
return 0;
}

