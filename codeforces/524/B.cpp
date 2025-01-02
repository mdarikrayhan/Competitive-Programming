#include<iostream>
#include<cstdio>
using namespace std;int n,h[10010],w[10010],maxx,minn,ans=0x3f3f3f3f;signed main(){cin>>n;for(int i=1;i<=n;i++)cin>>w[i]>>h[i],maxx=max(maxx,max(w[i],h[i])),minn=max(minn,min(w[i],h[i]));for(int H=maxx;H>=minn;H--){int res=0;for(int i=1;i<=n;i++)if(max(w[i],h[i])>H)res+=max(w[i],h[i]);else res+=min(w[i],h[i]);ans=min(ans,res*H);}cout<<ans;}