#include<bits/stdc++.h>
#define update(i) x[i]=x[l[i]]+x[r[i]]+a[i],y[i]=y[l[i]]+y[r[i]]+1-a[i];
using namespace std;
const int N=214514;
int n,m,a,b,t,T,L,mb,mdb,as;
int d[N],z[N],g[N],o[N],fa[N],FA[N],p[N*2],nt[N*2];
struct d_tr {
int g,t,l[N],r[N],z[N],a[N],x[N],y[N],fa[N],ro[N];
void put(int i,int j) {if(i&&j) z[i]=!z[i],a[i]=!a[i],swap(x[i],y[i]);}
void lazy(int i) {put(l[i],z[i]),put(r[i],z[i]),z[i]=0;}
void rt(int i,int j){
if(l[i]==j)l[i]=r[j],fa[r[j]]=i,r[j]=i;
else r[i]=l[j],fa[l[j]]=i,l[j]=i;
ro[j]=ro[i],ro[i]=0;
if(l[fa[i]]==i) l[fa[i]]=j; else
if(r[fa[i]]==i) r[fa[i]]=j;
fa[j]=fa[i],fa[i]=j;
update(i);update(j);
}
void splay(int i,int j){
if(ro[i]) lazy(i);
while(!ro[i]){
lazy(fa[i]);
lazy(i);
rt(fa[i],i);
}if(j){ro[g=r[i]]=1;
r[i]=0;
update(i);
}
}
void arc(int i){
splay(t=i,1);
while(fa[i]){
splay(t=fa[i],1);
r[t]=1,rt(t,i);
}
}
void cov(int i){
arc(i);
splay(L,0);
as+=y[r[L]]-x[r[L]];
put(r[L],1);
}

} tr;

void link(int a,int b) {nt[++t]=d[a],d[a]=t,p[t]=b;}
int find(int i) {return(FA[i]==i)?i:FA[i]=find(FA[i]);}

void dfs(int i,int h){
z[++t]=i,o[i]=t;
for(int k=d[i],j=p[k];k;k=nt[k],j=p[k]) if((h^k)!=1){
if(o[j]){
mb=k;
for(int I=o[j];I<=t;I++) g[++T]=z[I];
} else dfs(j,k);
}
t--;
}

void dfs2(int i,int h){
for(int k=d[i],j=p[k];k;k=nt[k],j=p[k]) if((h^k)!=1 &&((k^mb)>1)){
fa[j]=i;dfs2(j,k);
}
}

int main(){int mdb=0;t=1;
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++){
scanf("%d%d",&a,&b);
link(a,b);link(b,a);
}t=0;dfs(1,0);dfs2(g[1],0);
for(int i=0;i<N;i++) o[i]=0;
for(int i=1;i<=T;i++) o[g[i]]=i;
for(int i=1;i<=n;i++) FA[i]=(o[i])?i:fa[i];
for(int i=1;i<=n;i++) find(i);
for(int i=1;i<=n;i++){tr.fa[i]=fa[i];
tr.y[i]=tr.ro[i]=1;
};
g[0]=g[T],L=g[T+1]=g[1];
while(m--){
scanf("%d%d",&a,&b);
int Fa=FA[a],Fb=FA[b];
int d1=abs(o[Fa]-o[Fb]);
int g1,g2;
if(o[Fa]<o[Fb]) g1=g[o[Fa]+1],g2=g[o[Fa]-1];
else g1=g[o[Fa]-1],g2=g[o[Fa]+1];
tr.cov(a);
tr.cov(b);
if(d1>T-d1||((d1==T-d1) && g1>g2)){
mdb=!mdb;
if(mdb)as++;else as--;
tr.cov(g[T]);
}tr.arc(g[T]);
int al=tr.x[g[T]]+mdb==T;
printf("%d\n",n-as+al);
};
}