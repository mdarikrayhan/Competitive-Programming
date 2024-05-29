#include <cstdio>

int S,N,a[25],x[25],q[1<<21][2];

void print(int a,int c,int s) {for (int i=1; i<=s; i++) q[++S][0]=a,q[S][1]=c;}

void work0(int t,int a,int c,int b)
{
 if (t>N) return;
 work0(t+1,a,b,c),print(a,c,x[t]),work0(t+1,b,c,a);
}

void work1(int t,int a,int c,int b)
{
 if (t>N||!x[t]) return;
 if (t==N) print(a,b,x[t]-1),print(a,c,1),print(b,c,x[t]-1);
 else if (x[t]==1) work0(t,a,c,b);
 else work1(t+1,a,c,b),print(a,b,x[t]),work0(t+1,c,a,b),print(b,c,x[t]),work0(t+1,a,c,b);
}

int main()
{
 scanf("%d",&N); int n=0;
 for (int i=1; i<=N; i++)
 {
  scanf("%d",&a[i]);
  if (a[i]!=a[i-1]) x[++n]=1; else x[n]++;
 }
 N=n,work1(1,1,3,2),printf("%d\n",S);
 for (int i=1; i<=S; i++) printf("%d %d\n",q[i][0],q[i][1]);
}