#include<cstdio>
#include<cstring>
using namespace std;

#define n 1000005
#define For(i,b)for(int i=0;i<b;i++)

int N,M,D,P[n],G[n],Ans[n];
char s[n],t[n];

int main(){
scanf("%s%d",s,&M);N=strlen(s);
for(int k,d;M--;puts(""),D=0){
scanf("%d%d",&k,&d);
For(i,N)P[i]=Ans[i]=i;
For(i,d)for(int j=i;j<k;j+=d)P[D++]=j;

P[N]=P[0];For(i,N)P[i]=P[i+1];
for(int t=N-k+1;t;t>>=1){
if(t&1)For(i,N)Ans[i]=P[Ans[i]];
For(i,N)G[i]=P[i];For(i,N)P[i]=G[P[i]];
}
For(i,N)t[(i+N-k+1)%N]=s[Ans[i]];
For(i,N)printf("%c",s[i]=t[i]);
}
}