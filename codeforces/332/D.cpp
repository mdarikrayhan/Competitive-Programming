#include<cstdio>
#define f(i,a,b)for(int i=a;i<=b;i++)
long long S,N,K,x,F[2005],W[2005];
int main()
{
scanf("%I64d%I64d",&N,&K);
f(i,1,N)f(j,i+1,N)
{
scanf("%I64d",&x);
if(x>=0){F[i]+=x,F[j]+=x,W[i]++,W[j]++;}
}
f(i,1,N)S+=K==2?F[i]*(W[i]-1):F[i];
printf("%I64d",K==2?2*S/N/(N-1):S/N);
}