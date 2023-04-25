#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long T,n,s,f[N][2],x[N],y[N];
int main(){
ios::sync_with_stdio(0);
cin>>T;
while(T--){
cin>>n>>s;
for(int i=1,j;i<=n;i++){
cin>>j;
if(i==1||i==n)x[i]=y[i]=j;
else if(j<=s)x[i]=0,y[i]=j;
else x[i]=s,y[i]=j-s;
}
f[1][0]=f[1][1]=0;
for(int i=2;i<=n;i++)
f[i][0]=min(f[i-1][0]+y[i-1]*x[i],f[i-1][1]+x[i-1]*x[i]),
f[i][1]=min(f[i-1][0]+y[i-1]*y[i],f[i-1][1]+x[i-1]*y[i]);
cout<<f[n][0]<<"\n";
}
return 0;
}