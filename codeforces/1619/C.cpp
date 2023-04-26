#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--)
 
{
long long a,s,x,y;
long long b=0,p=1;
cin>>a>>s;
while(a>0){
x=a%10; y=s%10;
if(y<x){
s/=10;
y+=s%10*10;
}
if(x>y or (y-x)>9){
b=-1;
break;
}
b+=p*(y-x);
a/=10,s/=10,p*=10;
}
if(b!=-1) b+=p*s;
cout<<b<<endl;
}
 
}

