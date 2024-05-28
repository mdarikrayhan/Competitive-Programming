#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define db double
#define Eps 1e-14
using namespace std;
const int M=1e6+7,N=1e6+7;
int n,m,cs=150,L[M],R[M];
int lst,np,res,tr[N],las[M];
db x,y,k[M],b[M],l,r=1e13,mid,ans;
struct node{db jj; int id;}a[M*2+1];
db pf(db x){return x*x;}
void add(int p,int v){
for(;p<=np;p+=p&-p) tr[p]+=v;
}
int ask(int p){
int ans=0;
for(;p>0;p-=p&-p) ans+=tr[p];
return ans;
}
bool cmp(node a,node b){
return a.jj<b.jj;
}
bool check(db r){
db A,B,C,D,nx,ny; int sum=0; np=0;
for(int i=1;i<=n;i++){
A=pf(k[i])+1;
B=-2*x+2*k[i]*(b[i]-y);
C=pf(x)+pf(b[i]-y)-pf(r);
if(B*B<=4*A*C) continue;
D=sqrt(pf(B)-4*A*C),A*=2;
nx=(D-B)/A,ny=k[i]*nx+b[i];
a[++np]={atan2(ny-y,nx-x),i};
nx=(-D-B)/A,ny=k[i]*nx+b[i];
a[++np]={atan2(ny-y,nx-x),i};
}
sort(a+1,a+np+1,cmp);
for(int i=1,id;i<=np;i++){
id=a[i].id; if(las[id]){
sum+=ask(i)-ask(las[id]);
add(las[id],-1),las[id]=0;
}else add(i,1),las[id]=i;
}
//树状数组判线段交数
return sum>=m;
}
db dis(int i,int j){
db nx=(b[j]-b[i])/(k[i]-k[j]);
db ny=nx*k[i]+b[i];
return sqrt(pf(nx-x)+pf(ny-y));
}
int main(){
scanf("%d%lf%lf%d",&n,&x,&y,&m);
x/=1000,y/=1000; res=m;
for(int i=1;i<=n;i++){
scanf("%lf%lf",&k[i],&b[i]);
k[i]/=1000,b[i]/=1000;
}
while((cs--) && (r-l>Eps)){
mid=(l+r)/2;
if(check(mid)) r=mid;
else l=mid;
}
check(l);
for(int i=1,j=0,p;i<=np;i++)
if(las[a[i].id]){
for(p=j;p>las[a[i].id];p=L[p])
res--,ans+=dis(a[i].id,a[p].id);
R[L[p]]=R[p],L[R[p]]=L[p]; if(p==j) j=L[j];
}else R[j]=i,L[i]=j,j=i,las[a[i].id]=i;
printf("%.8lf",ans+l*res);
return 0;
}