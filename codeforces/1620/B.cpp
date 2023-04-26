#include<iostream>
using namespace std;
int main(){
int y;
cin>>y;
while(y--){
long long x,y,a[200000],s=0;
cin>>x>>y;
for(int i=0;i<4;i++){
int b,n;
cin>>b;
for(int j=0;j<b;j++) cin>>a[j];
if(i<2) n=y;
else n=x;
s=max(s,(a[b-1]-a[0])*n);
}
cout<<s<<endl;
}
}