#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;int n,m,f[1000100],x[300],y[300];int main(){cin>>n>>m;for(int i=0;i<m;i++)cin>>x[i]>>y[i];for(int i=0;i<m;i++)for(int j=i+1;j<m;j++){int cnt=1;long long a=y[i]-y[j],b=x[j]-x[i],c=-a*x[i]-b*y[i];if(!a||abs(c)%a)continue;long long X=-c/a;if(X<1||X>n)continue;for(int k=j+1;k<m;k++)cnt+=a*x[k]+b*y[k]==-c;f[X]=max(f[X],cnt);}int ans=0;for(int i=1;i<=n;i++)ans+=f[i]+1;cout<<ans<<endl;}