#include<bits/stdc++.h>
#define mo 1000000007
#define N 10005
using namespace std;
int a[N][6],n,m;
map<int,int>f[N];
int power(int x,int y){
int s=1;
for(;y;y/=2,x=1ll*x*x%mo)
if(y&1)s=1ll*s*x%mo;
return s;
}
int main(){
scanf("%d%d",&n,&m);
for(int i=2;i<=m;i++)
for(int j=1;j<i;j++){
a[i][++a[i][0]]=j;
f[i][j]=f[j][i]=mo-1;
f[i][i]++;f[j][j]++;
}
for(int i=m+1;i<=n;i++){
a[i][0]=m;
for(int j=1;j<=m;j++){
scanf("%d",&a[i][j]);
f[i][a[i][j]]=f[a[i][j]][i]=mo-1;
f[i][i]++;f[a[i][j]][a[i][j]]++;
}
}
int ans=1;
for(int i=n;i>1;i--){
int t=power(f[i][i],mo-2);
ans=1ll*ans*f[i][i]%mo;
for(int j=1;j<=a[i][0];j++)
for(int k=1;k<=a[i][0];k++)
(f[a[i][j]][a[i][k]]+=mo-1ll*f[a[i][j]][i]*f[i][a[i][k]]%mo*t%mo)%=mo;
}
printf("%d",ans);
}