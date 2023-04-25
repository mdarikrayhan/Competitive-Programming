#include<iostream>
using namespace std;
int64_t s[200007],n,T,i,ans,x;
main(){cin>>T;while(T--){cin>>n;ans=0;for(i=1;i<=n;i++)cin>>x,s[i]=s[i-1]+(x<i),(x<i)?ans+=s[x-1]:7;cout<<ans<<'\n';}}