#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cmath>
#define LL long long
using namespace std;
LL miu[100010],f[100010],p[100010];
LL N,M,L,R,P,len,res,ans;
LL calc(LL d,LL x,LL R2){
if(R2<d*x*d*x)return 0;
LL r=min(M/d,(LL)sqrt(R2-d*x*d*x)/d);
return(2*M%P-d*(r+1)%P+2)*r%P;
}
int main(){
scanf("%I64d%I64d%I64d%I64d%I64d",&N,&M,&L,&R,&P);
miu[1]=1;
for(LL i=2;i<=100000;i++){
if(!f[i]){f[i]=i;p[++len]=i;miu[i]=-1;}
for(LL j=1;j<=len&&p[j]*i<=100000&&p[j]<=f[i];j++){
f[p[j]*i]=p[j];
if(f[p[j]*i]==f[i])miu[p[j]*i]=0;
else miu[p[j]*i]=-miu[i];
}
}
for(LL d=1;d<=min(N,M);d++){
for(LL x=1;x<=N/d;x++){
res=calc(d,x,R*R);
res=res-calc(d,x,L*L-1);
ans=(ans+res%P*miu[d]%P*(N-d*x+1)%P)%P;
}
}
if(L==1)ans=(ans+2*N*M%P+N+M)%P;
printf("%I64d\n",(ans+P)%P);
}