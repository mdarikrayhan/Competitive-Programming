#include<bits/stdc++.h>
using namespace std;int T;main(){cin>>T;while(T--){long long int i,n,mx=0,x,ans=0;cin>>n;for(i=0;i<n;i++)cin>>x,ans+=x;for(i=0;i<n;i++)cin>>x,ans+=x,mx=max(mx,x);cout<<ans-mx<<"\n";}}