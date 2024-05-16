#include <iostream>
#include <bits/stdc++.h>
using namespace std;




int main()
{  
   
   string s;
   cin>>s;
   int n=5;
   while(n--){
       string a;
       cin>>a;
       
       if((a[0]==s[0])||a[1]==s[1]){
           cout<<"YES"<<endl;
           return 0;
       }
   }
   cout<<"NO"<<endl;
   
   
   return 0;
}