#include<bits/stdc++.h>
#define N 100005
using namespace std;
int P,xl,xr,yl,yr,e[N],X[N],Y[N],be[N],on[N],id[N],D[N],n,m,k,t,OP,x,y,W[10],T;char op;
vector<int>A[N];
struct O{
int m,w,i;
}ans,h[6][6];
struct B{
int l,r,m,w,c;
}b[N<<1];
struct C{
int l,r,s,c;
}c[N<<1];
bool operator==(O a,O b){
return a.m==b.m&&a.w==b.w&&a.i==b.i;
}
bool operator<(O a,O b){
return a.m==b.m?(a.w==b.w?a.i<b.i:a.w<b.w):a.m<b.m;
}
O operator+(O a,O b){
return(O){a.m+b.m,a.w+b.w,a.i?a.i:b.i};
}
bool cmp(int p,int q){
if(!(h[p][0]==h[q][0]))return h[p][0]<h[q][0];
if(h[p][2].i!=h[q][2].i)return h[p][2].i<h[q][2].i;
if(h[p][2].w<h[q][2].w)return h[p][3].i<h[q][2].m;
else return h[p][2].m<h[q][3].i;
}
void build(int&u,int p,int q){
u=++t;
if(p==q){b[u].w=1;return;}
build(b[u].l,p,p+q>>1);
build(b[u].r,(p+q>>1)+1,q);
b[u].w=b[b[u].l].w+b[b[u].r].w;
}
void Build(int&u,int p,int q){
u=++t;
if(p==q)return;
Build(c[u].l,p,p+q>>1);
Build(c[u].r,(p+q>>1)+1,q);
}
void cl(int u,int p,int q,int l,int r){
if(l<=p&&q<=r){c[u].s=0,c[u].c=1;return;}
if(c[u].c){
c[c[u].l].s=c[c[u].r].s=c[u].c=0;
c[c[u].l].c=c[c[u].r].c=1;return;
}
if(l<=p+q>>1)cl(c[u].l,p,p+q>>1,l,r);
if(r>p+q>>1)cl(c[u].r,(p+q>>1)+1,q,l,r);
c[u].s=c[c[u].l].s+c[c[u].r].s;
}
void Cl(int u,int p,int q,int l,int r){
if(l<=p&&q<=r){b[u].m=0,b[u].c=1;return;}
if(b[u].c){
b[b[u].l].m=b[b[u].r].m=b[u].c=0;
b[b[u].l].c=b[b[u].r].c=1;return;
}
if(l<=p+q>>1)Cl(b[u].l,p,p+q>>1,l,r);
if(r>p+q>>1)Cl(b[u].r,(p+q>>1)+1,q,l,r);
b[u].m=b[b[u].l].m+b[b[u].r].m;
}
void add(int u,int p,int q){
if(p==q){++c[u].s;return;}
if(c[u].c){
c[c[u].l].c=c[c[u].r].c=1;
c[c[u].l].s=c[c[u].r].s=c[u].c=0;
}
if(t<=p+q>>1)add(c[u].l,p,p+q>>1);
else add(c[u].r,(p+q>>1)+1,q);
c[u].s=c[c[u].l].s+c[c[u].r].s;
}
void Down(int u,int p,int q){
if(p==q){
if(b[u].c){
if(X[k]<=Y[k])X[k]=0;else Y[k]=0,
cl(e[k],0,A[k].size()-2,0,A[k].size()-2);
b[u].c=0;
}
if(t>=0)
if(t==(int)A[k].size()-1)++X[k];else 
add(e[k],0,A[k].size()-2),++Y[k];
b[u].w=Y[k]<X[k]?A[k].size()-1:1;
b[u].m=min(X[k],Y[k]);return;
}
if(b[u].c){
b[b[u].l].c=b[b[u].r].c=1;
b[b[u].l].m=b[b[u].r].m=b[u].c=0;
}
if(k<=p+q>>1)Down(b[u].l,p,p+q>>1);
else Down(b[u].r,(p+q>>1)+1,q);
b[u].m=b[b[u].l].m+b[b[u].r].m;
b[u].w=b[b[u].l].w+b[b[u].r].w;
}
int get(int u,int p,int q,int l,int r){
if(l<=p&&q<=r)return c[u].s;
if(c[u].c){
c[c[u].l].c=c[c[u].r].c=1;
return c[c[u].l].s=c[c[u].r].s=c[u].c=0;
}
int s=0;
if(l<=p+q>>1)s+=get(c[u].l,p,p+q>>1,l,r);
if(r>p+q>>1)s+=get(c[u].r,(p+q>>1)+1,q,l,r);
return s;
}
O Get(int u,int p,int q,int l,int r){
if(l<=p&&q<=r)return(O){b[u].m,b[u].w,0};
if(b[u].c){
b[b[u].l].c=b[b[u].r].c=1;
b[b[u].l].m=b[b[u].r].m=b[u].c=0;
}
O s={0,0,0};
if(l<=p+q>>1)s=Get(b[u].l,p,p+q>>1,l,r);
if(r>p+q>>1)s=s+Get(b[u].r,(p+q>>1)+1,q,l,r);
return s;
}
O qiu(int x,int y){
if(x==y)return(O){0,0,0};O s;
k=!id[x]?be[x]:(!id[y]?be[y]:id[x]);
int p=be[x]==k?on[x]:0,q=be[y]==k?on[y]:0;
if(p<q){
s.m=get(e[k],0,A[k].size()-2,p,q-1);
s.w=q-p;s.i=A[k][p+1];
}else{
s.m=get(e[k],0,A[k].size()-2,q,p-1);
s.w=p-q;s.i=A[k][p-1];
}
return s;
}
O Qiu(int x,int y){
if(x==y){++T;return(O){0,0,0};}
int p=id[x],q=id[y];O s1,s2;
if(p<q){
s1=Get(1,1,m,p,q-1);
s2=p>1?Get(1,1,m,1,p-1):(O){0,0,0};
s2=s2+Get(1,1,m,q,m);
s1.i=X[p]>Y[p]?A[p][1]:D[p+1];
if(p==1)s2.i=X[m]>Y[m]?A[m][A[m].size()-2]:D[m];
else s2.i=X[p-1]>Y[p-1]?A[p-1][A[p-1].size()-2]:D[p-1];
}else{
s1=Get(1,1,m,q,p-1);
s2=q>1?Get(1,1,m,1,q-1):(O){0,0,0};
s2=s2+Get(1,1,m,p,m);
s2.i=X[p]>Y[p]?A[p][1]:D[p+1];
if(p==1)s1.i=X[m]>Y[m]?A[m][A[m].size()-2]:D[m];
else s1.i=X[p-1]>Y[p-1]?A[p-1][A[p-1].size()-2]:D[p-1];
}
if(s1<s2){W[++T]=0;return s1;}else{W[++T]=1;return s2;}
}
void cr(int x,int y){
if(x==y)return;
k=!id[x]?be[x]:(!id[y]?be[y]:id[x]);
int p=be[x]==k?on[x]:0,q=be[y]==k?on[y]:0;
if(p>q)swap(p,q);
cl(e[k],0,A[k].size()-2,p,q-1);
Y[k]=c[e[k]].s;t=-1;Down(1,1,m);
}
void Cr(int x,int y,int W){
if(x==y)return;
int p=id[x],q=id[y];
if(p>q)swap(p,q);
if(W){
if(p>1)Cl(1,1,m,1,p-1);Cl(1,1,m,q,m);
}else Cl(1,1,m,p,q-1);
}
int main(){
scanf("%d%d",&n,&m);
for(int i=1;i<=m;++i)scanf("%d",&D[i]),id[D[i]]=i;
D[m+1]=D[1];
for(int i=1;i<=m;++i){
scanf("%d",&k);
for(int j=0;j<k;++j){
scanf("%d",&x);
if(j)be[x]=i,on[x]=j;
A[i].push_back(x);
}
Build(e[i],0,k-2);
}
t=0;build(x,1,m);
scanf("%d\n",&OP);
while(OP--){
scanf("%c%d%d\n",&op,&x,&y);
if(op=='+'){
if(id[x]&&id[y]){
k=min(id[x],id[y]);
if(k==1&&id[x]+id[y]-1==m)k=m;
t=A[k].size()-1;
}else{
k=max(be[x],be[y]);
if(k==m&&be[x]+be[y]-1==m)k=1;
t=be[x]!=be[y]?0:min(on[x],on[y]);
}
Down(1,1,m);
}else{
if(x==y){puts("0");continue;}
t=-1;T=0;
k=x==D[1]?1:max(id[x],be[x]);Down(1,1,m);
xl=D[k];xr=id[x]?xl:D[k+1];
k=y==D[1]?1:max(id[y],be[y]);Down(1,1,m);
yl=D[k];yr=id[y]?yl:D[k+1];
h[1][1]=qiu(x,xl),h[1][2]=Qiu(xl,yl),h[1][3]=qiu(yl,y);
h[2][1]=h[1][1],h[2][2]=Qiu(xl,yr),h[2][3]=qiu(yr,y);
h[3][1]=qiu(x,xr),h[3][2]=Qiu(xr,yl),h[3][3]=h[1][3];
h[4][1]=h[3][1],h[4][2]=Qiu(xr,yr),h[4][3]=h[2][3];
for(int j=1;j<5;++j)h[j][0]=h[j][1]+h[j][2]+h[j][3];
h[1][2].m=h[3][2].m=yl;h[2][2].m=h[4][2].m=yr;
P=1;for(int j=2;j<5;++j)if(cmp(j,P))P=j;
ans=h[P][0];
if(be[x]==be[y]&&!id[x]&&!id[y]){
O s=qiu(x,y);
if(s<ans)ans=s,P=5;
}
printf("%d\n",ans.m);
if(P==1)cr(x,xl),Cr(xl,yl,W[1]),cr(yl,y);else 
if(P==2)cr(x,xl),Cr(xl,yr,W[2]),cr(yr,y);else 
if(P==3)cr(x,xr),Cr(xr,yl,W[3]),cr(yl,y);else 
if(P==4)cr(x,xr),Cr(xr,yr,W[4]),cr(yr,y);else 
cr(x,y);
}
}
return 0;
}