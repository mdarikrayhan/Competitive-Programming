#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,ans=0;
   cin>>n;
   int s[n];
   for(int i=0;i<n;i++){
       cin>>s[i];
   }
   int c1=0,c2=0,c3=0,c4=0;
   for(int i=0;i<n;i++){
       if(s[i]==1) c1++;
       else if(s[i]==2) c2++;
       else if(s[i]==3) c3++;
       else if(s[i]==4) c4++;
   }
   ans=c4;
   if(c2%2==0) ans=ans+c2/2;
   else{
       ans=ans+c2/2+1;
       c1=c1-2;
   } 
   if(c3>=c1) ans=ans+c3;
   else{
       int temp=c1-c3;
       if(temp%4==0) ans=ans+c3+temp/4;
       else ans=ans+c3+1+temp/4;
   }
   cout<<ans;
}