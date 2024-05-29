#include<cmath>
#include<cstdio>
#include<cstring>

int N,K,b[10005];

void dfs(int t,int s,int x,int k)
{
if(!N)return;
if(t>3){if(t==4&&(s=std::abs(s-K))<1e4&&b[s]!=k)printf("%04d%04d\n",k,s),b[s]=k,N--;return;}
dfs(t+1,x%10+s,x/10,k),dfs(t+1,x%10*s,x/10,k),dfs(t+1,s-(x%10),x/10,k);
dfs(t+2,x%100+s,x/100,k),dfs(t+2,x%100*s,x/100,k),dfs(t+2,s-(x%100),x/100,k);
}

void doit()
{
scanf("%d%d",&K,&N),memset(b,-1,sizeof(b));
for(int i=0;i<1e4;i++)dfs(1,i%10,i/10,i),dfs(2,i%100,i/100,i);
}

int main()
{
doit();
return 0;
}