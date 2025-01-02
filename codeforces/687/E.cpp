#include<cstdio>
#include<cstring>
#define min(x,y)((x)<(y)?(x):(y))
#define max(x,y)((x)<(y)?(y):(x))
using namespace std;
const int N=5050,oo=1000000000;
int i,j,k,n,m,x,y,ch,num,En,ans,mi;
int a[N][N],b[N],d[N],h[N],z[N];
struct edge{int s,n;}E[N];
void R(int&x){
x=0;ch=getchar();
while(ch<'0'||'9'<ch)ch=getchar();
while('0'<=ch&&ch<='9')x=x*10+ch-'0',ch=getchar();
}
void E_add(int x,int y){
E[++En].s=y;E[En].n=h[x];h[x]=En;
}
void work(int x){
int i=0,j=1,k;
d[1]=x;
while(i<j){
i++;
for(k=h[d[i]];k;k=E[k].n)if(!a[x][E[k].s]){
a[x][E[k].s]=a[x][d[i]]+1;
d[++j]=E[k].s;
}
}
}
int main(){
R(n);R(m);ans=n;
for(i=1;i<=m;i++){
R(x);R(y);
E_add(x,y);
}
for(i=1;i<=n;i++)work(i);
for(i=1;i<=n;i++)if(!b[i]){
b[i]=++num;
for(j=1;j<=n;j++)if(!b[j]&&a[i][j]&&a[j][i])b[j]=num;
}
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)if(a[i][j]&&b[i]!=b[j])z[b[i]]=1;
for(i=1;i<=num;i++)if(!z[i]){
mi=n;
for(j=1;j<=n;j++)if(b[j]==i)mi=min(mi,a[j][j]);
if(mi)ans+=mi*999-(mi-1);
}
printf("%d\n",ans);
}