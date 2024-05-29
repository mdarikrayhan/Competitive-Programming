#include<cstdio>
#include<cstdlib>
#define N 55
int f[N][N],g[N*N],a[2*N],b[2*N],aa,bb;
int n,m;
struct rec{
int num,d[55];
void read(int id){
int u,v;
scanf("%d%d",&u,&v);
f[u][v]=id;
scanf("%d",&num);
for(int i=1;i<=num;i++)scanf("%d",&d[i]);
for(int i=1;i<=num;i++)
if(d[i]==u&&d[i+1]==v){g[id]=i;return;}
}
}E[N*N];
void doit(int t1,int t2){
int now=t1;
for(int i=2;i<=aa;i++){
int p=a[i];
if(!f[p][now])return;
int id=f[p][now];
for(int j=E[id].num;j;j--)a[++aa]=E[id].d[j];
now=p;
if(aa+bb>2*n)return;
}
now=t2;
for(int i=2;i<=bb;i++){
int p=b[i];
if(!f[now][p])return;
int id=f[now][p];
for(int j=1;j<=E[id].num;j++)b[++bb]=E[id].d[j];
now=p;
if(aa+bb>2*n)return;
}
printf("%d\n",aa+bb);
for(int i=aa;i>=1;i--)printf("%d ",a[i]);
for(int i=1;i<=bb;i++)printf("%d ",b[i]);
exit(0);
}
int main(){
scanf("%d%d",&n,&m);
for(int i=1;i<=m;i++)E[i].read(i);
for(int i=1;i<=m;i++)
if(g[i]){
aa=bb=0;
for(int k=g[i];k;k--)a[++aa]=E[i].d[k];
for(int k=g[i]+1;k<=E[i].num;k++)b[++bb]=E[i].d[k];
doit(E[i].d[g[i]],E[i].d[g[i]+1]);
}
printf("0\n");
}