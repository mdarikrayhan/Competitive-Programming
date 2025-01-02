#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=1e5+10;
const db eps=1e-9;

int n,m,num,cnt;
db len[N],sum,a,b,c,d;

inline db sqr(db x){return x*x;}

struct P{
db x,y;
P(db x_=0,db y_=0):x(x_),y(y_){};
P operator+(const P&ky){return P(x+ky.x,y+ky.y);}
P operator-(const P&ky){return P(x-ky.x,y-ky.y);}
P operator/(const db&ky){return P(x/ky,y/ky);}
P operator*(const db&ky){return P(x*ky,y*ky);}
inline db sq(){return sqr(x)+sqr(y);}
}p[N],dir[N],st,ed;


inline db dis(P a,P b){return sqrt((a-b).sq());}

struct F{db ql,qr,a,b,c;}f[N<<4];

struct dat{
db pos;int v;
bool operator<(const dat&ky)const{
return fabs(pos-ky.pos)<eps?v<ky.v:pos<ky.pos;
}
}t[N<<4];

inline bool ck(db lim)
{
int i,j;cnt=0;db l,r,z,x,y;
for(i=1;i<=num;++i){
a=f[i].a;b=f[i].b;c=f[i].c-lim;l=f[i].ql;r=f[i].qr;
assert(a>-eps);
if(fabs(a)<eps){
if(fabs(b)<eps){if(c<eps)t[++cnt]=(dat){l,1},t[++cnt]=(dat){r,-1};}
else{
z=-c/b;
if(b>0&&z>0)t[++cnt]=(dat){l,1},t[++cnt]=(dat){min(l+z,r),-1};
else if(b<0&&l+z<r)t[++cnt]=(dat){max(l+z,0.0),1},t[++cnt]=(dat){r,-1};
}
}else{
z=b*b-4*a*c;if(z<0)continue;z=sqrt(z);
x=(-b-z)/(2*a);y=(-b+z)/(2*a);
if(l+x>r||y<0)continue;
t[++cnt]=(dat){l+max(0.0,x),1};t[++cnt]=(dat){min(r,l+y),-1};
}
}
sort(t+1,t+cnt+1);
for(i=1,j=0;i<=cnt;++i)
{j+=t[i].v;if(j==m)return true;}
return false;
}

int main(){
int i,pl=1,pr=1,id=1;P dr,dt,st,ed;
db l=0,r,mid,res,cur=0,la,lb,avr;
scanf("%d%d",&n,&m);
for(i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
p[n+1]=p[1];
for(i=1;i<=n;++i){
len[i]=dis(p[i],p[i+1]);dir[i]=(p[i+1]-p[i])/len[i];
sum+=len[i];
}
avr=lb=sum/m;
for(;len[pr]<lb+eps;++pr)lb-=len[pr];
st=p[1];ed=p[pr]+dir[pr]*lb;la=len[1];lb=len[pr]-lb;
for(;cur+(1e-5)<sum;){
res=min(id*avr-cur,min(la,lb));
dt=ed-st;dr=dir[pr]-dir[pl];
f[++num]=(F){cur-(id-1)*avr,cur-(id-1)*avr+res,dr.sq(),2*(dr.x*dt.x+dr.y*dt.y),dt.sq()};
cur+=res;if(cur+(1e-5)>id*avr)id++;
st=st+(dir[pl]*res);ed=ed+(dir[pr]*res);
if(res+eps>la){pl=pl%n+1;la=len[pl];}else la-=res;
if(res+eps>lb){pr=pr%n+1;lb=len[pr];}else lb-=res;
}
for(r=avr;r-l>eps;){
mid=(l+r)/2.0;
ck(mid*mid)?r=mid:l=mid;
}
printf("%.8lf",l);
return 0;
}