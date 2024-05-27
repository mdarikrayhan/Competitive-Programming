#include<bits/stdc++.h>
using namespace std;
int a=1,b,c,n,x,y,z;
main(){
cin>>n>>x>>y>>c;
while(a<c){
b++;
z=min(x-1,b);
a+=max(z-max((y+b-n),0)+1,0)+max(z-max((b-y+1),0)+1,0)-(z==b);
z=min(n-x,b);
a+=max(z-max((y+b-n),1)+1,0)+max(z-max((b-y+1),1)+1,0)-(z==b);}
cout<<b;}