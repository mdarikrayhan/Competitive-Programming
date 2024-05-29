#include <cstdio>
#include <cstring>
#define rep(i,n) for (int i=0;i<n;i++)
char s[100],Ans[2000];
int n,m,ans,cnt,b[20],a[40][40],p[50],q[50],x[20][20];
void dfs(int c,int d) {
 if (d==15) {
  memset(x,0,sizeof(x));
  for (int i=1;i<=28;i++) { if (x[b[p[i]]][b[q[i]]]) return;x[b[p[i]]][b[q[i]]]=x[b[q[i]]][b[p[i]]]=1;}
  if (++ans==1) { cnt=0;rep(i,n) {
   rep(j,m) Ans[cnt++]=a[i][j]?(b[a[i][j]]+47):'.';
   Ans[cnt++]='\n';
  } Ans[cnt]='\0';}
 } else {
  if (b[d]) {dfs(c,d+1);return;}
  b[d]=c;for (int j=d+1;j<=14;j++) if (!b[j]) b[j]=c,dfs(c+1,d+1),b[j]=0;b[d]=0;
 }
}
main() {
 scanf("%d%d",&n,&m);
 rep(i,n) {
  scanf("%s",&s);
  rep(j,m) {
   if (s[j]!='.' && !a[i][j]) a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=++cnt;
   if (s[j]!='.') {
    int t=s[j]<='B'?s[j]-64:s[j]-94;
    if (!p[t]) p[t]=a[i][j]; else q[t]=a[i][j];
   }
  }
 }
 dfs(1,1);
 printf("%d\n%s",ans*5040,Ans);
}