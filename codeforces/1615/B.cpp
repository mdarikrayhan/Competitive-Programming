#include <bits/stdc++.h>
using namespace std;
int t,l,r;
int F(int x,int j){
return (x>>j+1<<j)+min(x%(1<<j+1),1<<j);
}
int main(){
cin>>t;
while(t--){
cin>>l>>r;
int z=r;
for(int j=0;j<18;j++){
z=min(z,F(r+1,j)-F(l,j));
}
cout<<z<<endl;
}
return 0;
}