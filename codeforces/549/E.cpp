#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
const int N=1e4+10;
struct pt{
int x,y;
inline pt(int _x=0,int _y=0){x=_x;y=_y;}
}a[N],b[N],p[N];
int top,n,m;
inline pt operator -(const pt &a,const pt &b){return pt(a.x-b.x,a.y-b.y);}
inline int operator *(const pt &a,const pt &b){return a.x*b.x+a.y*b.y;}
inline int operator ^(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}
inline double Len(const pt &p){return sqrt(p.x*p.x+p.y*p.y);}
inline bool cmpx(const pt &a,const pt &b){return (a.x^b.x)?a.x<b.x:a.y<b.y;}
inline bool check(pt x,pt y){
double l=-1e18,r=1e18;
for(int i=1;i<=n;++i){
if(!((x-a[i])^(y-a[i]))) continue;
double w=1.0*((x-a[i])*(y-a[i]))/((x-a[i])^(y-a[i]));
if(((a[i]-x)^(y-x))<0) l=max(l,w);
else r=min(r,w);
}
for(int i=1;i<=m;++i){
if(!((x-b[i])^(y-b[i]))){
if(b[i].x>=min(x.x,y.x)&&b[i].x<=max(x.x,y.x)&&b[i].y>=min(x.y,y.y)&&b[i].y<=max(x.y,y.y)) return false;
continue;
}
double w=1.0*((x-b[i])*(y-b[i]))/((x-b[i])^(y-b[i]));
if(((b[i]-x)^(y-x))>0) l=max(l,w);
else r=min(r,w);
}
return r-l>eps;

}
inline bool dfs(int l,int r){
if(r-l+1<=2) return false;
int pos=l+1;double mx=0;
for(int k=l+1;k<r;++k){
double tmp=((p[l]-p[k])*(p[r]-p[k]))*1.0/((p[l]-p[k])^(p[r]-p[k]));
if(k==l+1||tmp-mx>eps) mx=tmp,pos=k;
}
return check(p[l],p[pos])||check(p[pos],p[r])||dfs(l,pos)||dfs(pos,r);
}
inline bool work(){
p[top=1]=a[1];
for(int i=2;i<=n;++i){
while(top>1&&((p[top-1]-p[top])^(a[i]-p[top]))<=0) --top;
p[++top]=a[i];
}
int now=top;
for(int i=n-1;i>=1;--i){
while(top>now&&((p[top-1]-p[top])^(a[i]-p[top]))<=0) --top;
p[++top]=a[i];
}
--top;
return check(p[1],p[top])||dfs(1,top);
}
int main(){
scanf("%d%d",&n,&m);
if(n==1||m==1){puts("YES");return 0;}
for(int i=1;i<=n;++i)
scanf("%d%d",&a[i].x,&a[i].y);
for(int i=1;i<=m;++i)
scanf("%d%d",&b[i].x,&b[i].y);
sort(a+1,a+n+1,cmpx);
sort(b+1,b+m+1,cmpx);
if(work()) puts("YES");
else{
swap(a,b);
swap(n,m);
if(work()) puts("YES");
else puts("NO");
}
return 0;
}