#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
main(){
ios::sync_with_stdio(false);
int t,s=0,c=0,p=1,u=1; cin>>t;
map<int,int> mp;
while(t--){
int op,x; cin>>op;
switch(op){
case 1:cin>>x; mp[x+s]+=u; break;
case 2:cin>>x; s+=x; break;
case 3:if(s<2e5){
if(!s){p=(p<<1)%mod; u=u*499122177%mod; continue;}
for(int i=s+2e5;i>s;i--)mp[i+s]+=mp[i]; s<<=1;
}
}
}
for(auto [x,y]:mp)if(x>s)c+=y;
cout<<c%mod*p%mod<<endl;
return 0;
}