#include<bits/stdc++.h>
using namespace std;
int n,T,ou[333],g[333],a,b;
int main(){
cin>>T;
while(T--){
cin>>n;
a=0,b=0;
for(int i=1;i<=n;i++){
int x;cin>>x;
if(x&1)g[++a]=i;else ou[++b]=i;
}
if(a>=3)cout<<"YES\n"<<g[1]<<" "<<g[2]<<" "<<g[3]<<endl;
else{
if(a>=1&&b>=2)cout<<"YES\n"<<g[1]<<" "<<ou[1]<<" "<<ou[2]<<endl;
else puts("NO");
}
}
}