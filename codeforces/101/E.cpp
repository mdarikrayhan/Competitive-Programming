#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
#define N 20005
bitset<N> a[N/2];
int x[N],y[N],f[N],g[N],n,m,p,len,flag=1;
char ans[N+N];
void work()
{
 for (int i=1;i<=n;i++){
  memset(g,0,sizeof(g)); if (n-i<N/2) a[n-i].reset();
  for (int j=1;j<=m;j++){
   g[j]=g[j-1];
   if (j<2 || f[j]>g[j]){g[j]=f[j]; if (n-i<N/2) a[n-i][j]=1;}
   g[j]+=(x[i]+y[j])%p;
   }
  memcpy(f,g,sizeof(f));
  }
 int i=0; if (flag) printf("%d\n",f[m]),flag=0;
 while (i<N/2 && i<n && n-i+m>1 && m)
  if (a[i][m]) i++,ans[--len]='C'; else m--,ans[--len]='S';
 n-=i; memset(f,0,sizeof(f));
}
int main()
{
 scanf("%d%d%d",&n,&m,&p),len=n+m-2;
 for (int i=1;i<=n;i++) scanf("%d",&x[i]);
 for (int i=1;i<=m;i++) scanf("%d",&y[i]);
 work(),work(); puts(ans); return 0;
}