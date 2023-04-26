#include<bits/stdc++.h>
using namespace std;
int main(){
int q;
cin>>q;
while(q--){
string s;
cin>>s;
int a=0,b=0,c1=0,c2=0,i;
for(i=0;i<10;i++){
if(s[i]=='1')
if(i%2==0) a++;
else b++;
if(s[i]=='?')
if(i%2==0) c1++;
else c2++;
if(a+c1>b+(10-i)/2||b+c2>a+(9-i)/2){
i++;
break;
}
}
cout<<i<<endl;
}
}