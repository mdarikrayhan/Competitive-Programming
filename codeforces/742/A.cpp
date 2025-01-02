#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
   int n;
   cin>>n;
   if(n==0){
    cout<<1;
   }
   else if(n%4==1){
    cout<<8;
   }else if(n%4==2){
    cout<<4;
   }else if(n%4==3){
    cout<<2;
   }else if(n%4==0){
    cout<<6;
   }

return 0;
}