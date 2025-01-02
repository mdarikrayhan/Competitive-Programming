#include<bits/stdc++.h>
#define Min(x,y) ((x)<(y)?(x):(y))
#define Max(x,y) ((x)>(y)?(x):(y))
using namespace std;
using pdd=pair<double,double>;
inline int read()
{
int x=0,f=1;char ch=getchar();
while(!isdigit(ch))
{
if(ch=='-')f=-1;
ch=getchar();
}
while(isdigit(ch))
{
x=(x<<1)+(x<<3)+ch-'0';
ch=getchar();
}
return x*f;
}
const int N=51;
struct Point{
double x,y;
Point():x(0),y(0){}
Point(double x,double y):x(x),y(y){}
}P[N];
inline Point operator-(Point A,Point B)
{
return{A.x-B.x,A.y-B.y};
}
inline double operator*(Point A,Point B)
{
return A.x*B.x+A.y*B.y;
}
inline double sqr(Point A)
{
return sqrt(A*A);
}
inline Point operator/(Point A,double x)
{
return{A.x/x,A.y/x};
}
inline void checkbad(double a,double b,double c,double l,double r,vector<pdd>&ans)
{
assert(abs(a-1)<1e-5 or a<0);
if(a>0)
{
b/=a;
c/=a;
a=1;
if(b*b<4*a*c)return;
double delta=sqrt(b*b-4*a*c),l0=(-b-delta)/2,r0=(-b+delta)/2;
l0=Max(l0,l);
r0=Min(r0,r);
if(l0<r0)ans.emplace_back(l0,r0);
}
if(a<0)
{
double s=sqrt(a*a+b*b+c*c);
a/=s;
b/=s;
c/=s;
if(b*b<4*a*c)
{
ans.emplace_back(l,r);
return;
}
double delta=sqrt(b*b-4*a*c),l0=(-b+delta)/(2*a),r0=(-b-delta)/(2*a);
if(-0.01<a)
{
if(b>0)l0=(-2*c)/(b+delta);
else r0=(2*c)/(-b+delta);
}
if(l<l0)ans.emplace_back(l,Min(l0,r));
if(r0<r)ans.emplace_back(Max(l,r0),r);
}
}
inline void checkbad(double a,double b,double c,double d,double l0,double r0,double l1,double r1,vector<pdd>&ans)
{
assert(a>=1.99);
double lmin=(-2*r1-c)/a,rmin=(-2*l1-c)/a;
lmin=Max(lmin,l0);
rmin=Min(rmin,r0);
if(lmin<rmin)checkbad(1-a*a/4,b-a*c/2,d-c*c/4,lmin,rmin,ans);
checkbad(1,a*l1+b,l1*l1+c*l1+d,l0,r0,ans);
checkbad(1,a*r1+b,r1*r1+c*r1+d,l0,r0,ans);
}
inline void checkgood(Point A,Point B,Point C,Point D,double v,double l,vector<pdd>&ans)
{
double lA=0,rA=sqr(B-A),lC=0,rC=sqr(D-C);
Point dA=(B-A)/rA,dC=(D-C)/rC;
if(v>=sqrt(2/(1+dA*dC)))return;
double c1=v*v-1,c2=(2*(1-(v*v)*(dA*dC)))/c1,c3=(2*v*v*((A-C)*dA)+2*l)/c1,c4=(-2*v*v*((A-C)*dC)-2*l)/c1,c5=(v*v*((A-C)*(A-C))-l*l)/c1;
checkbad(c2,c3,c4,c5,lA,rA,lC,rC,ans);
}
inline bool checkcmp(pair<double,double>I1,pair<double,double>I2)
{
return Max(I1.first,I2.first)<Min(I1.second,I2.second);
}
double pre[N];
int n,T=50;
int main(){
n=read();
for(int i=0;i<=n;++i)scanf("%lf%lf",&P[i].x,&P[i].y);
for(int i=1;i<n;++i)pre[i]=pre[i-1]+sqr(P[i]-P[i-1]);
if(n<=2)
{
puts("1");
return 0;
}
double l=1.0,r=30.0;
while(T--){
bool fl=false;
double mid=(l+r)/2;
for(int i=1;i<n-1;++i)
{
vector<pdd>vec1,vec2;
for(int j=0;j<i;++j)checkgood(P[i],P[i+1],P[j],P[j+1],mid,pre[j]-pre[i],vec1);
for(int j=i+1;j<n;++j)checkgood(P[i],P[i+1],P[j],P[j+1],mid,pre[j]-pre[i],vec2);
for(auto&j:vec1)for(auto&k:vec2)fl|=checkcmp(j,k);
}
if(fl)l=mid;
else r=mid;
}printf("%.10lf\n",l);return 0;}