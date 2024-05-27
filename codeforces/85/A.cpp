#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int m,x;
for(int i=0;i<4;i++){
if(i<2) cout<<'a';
m=n-(i<2);
for(int j=0;j<m/2;j++){
x='a'+(i+j)%24+1;
cout<<char(x)<<char(x);
}
if(m%2) cout<<'z';
cout<<endl;
}
}
