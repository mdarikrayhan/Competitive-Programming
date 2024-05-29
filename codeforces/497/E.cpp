#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
long long n;
int k;
struct Mat{
int a[32][32];
Mat(){
memset(a,0,sizeof(a));
}
friend Mat operator*(const Mat&a,const Mat&b){
Mat c;
for(int i=0;i<=k;i++)
for(int j=0;j<=k;j++)
for(int t=0;t<=k;t++)
c.a[i][t]=(c.a[i][t]+1ll*a.a[i][j]*b.a[j][t])%mo;
return c;
}
}f[70][32],pre[32],suf[32],ans;
int num[70],len;
int main(){
scanf("%I64d%d",&n,&k);
ans.a[0][k]=1;
for(;n;n/=k)
num[len++]=n%k;
for(int i=0;i<k;i++)
for(int j=0;j<=k;j++)
f[0][i].a[j][i]=f[0][i].a[j][j]=1;
for(int i=1;i<len;i++){
pre[0]=f[i-1][0];
for(int j=1;j<k;j++)
pre[j]=pre[j-1]*f[i-1][j];
suf[k-1]=f[i-1][k-1];
for(int j=k-1;j--;j)
suf[j]=f[i-1][j]*suf[j+1];
f[i][0]=suf[0];
for(int j=1;j<k;j++)f[i][j]=suf[j]*pre[j-1];
}
for(int i=len,s=0;i--;s+=num[i])
for(int j=0;j<num[i];j++)
ans=ans*f[i][(j+s)%k];
int res=0;
for(int i=0;i<=k;i++)
res=(res+ans.a[0][i])%mo;
printf("%d",res);
}