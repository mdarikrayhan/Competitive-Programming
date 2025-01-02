#include<bits/stdc++.h>
#define For(i,j,k)for(int i=j;i<=k;i++)
#define Rep(i,j,k)for(int i=j;i>=k;i--)
#define upd(x,y)(((x)+=(y))>=mo?x-=mo:233);
using namespace std;
const int N=260,mo=777777777;
int f[30][N][N],c[N*2][N*2],n,k,ans;
int power(int x,int y){
int s=1;
for(;y;y/=2,x=1ll*x*x%mo)
if(y&1)s=1ll*s*x%mo;
return s;
}
int main(){
scanf("%d%d",&n,&k);k=n-k;
For(i,0,n)c[i][0]=1;
For(i,1,n)For(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
f[0][0][0]=1;
Rep(i,n,1)Rep(v,min(22,n/i),0)Rep(v1,k,0)Rep(v2,n-k,0){
int tmp=1ll*f[v][v1][v2]*c[v1+v2+i][i]%mo;
if(v1+i<=k)upd(f[v+1][v1+i][v2],tmp);
if(v2+i<=n-k)upd(f[v+1][v1][v2+i],mo-tmp);
}
For(v,0,min(n,23))For(v2,0,n-k)
upd(ans,1ll*f[v][k][v2]*c[n][k+v2]%mo*power(n-v,n-k-v2)%mo);
printf("%d\n",ans);
}