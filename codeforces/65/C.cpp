#include<cstdio>
#include<cmath>
#define For(i,x,y) for(int i=(int)x,_y=y;i<=_y;i++)
typedef double db;
const db eps=1e-9;
struct point
{
 db x,y,z;
 void scan(){scanf("%lf%lf%lf",&x,&y,&z);}
 point operator +(const point &B)const{return (point){x+B.x,y+B.y,z+B.z};}
 point operator -(const point &B)const{return (point){x-B.x,y-B.y,z-B.z};}
 point operator *(const db &b)const{return (point){x*b,y*b,z*b};}
 db dist(){return sqrt(x*x+y*y+z*z);}
}p[10005],P;
int n;
db vs,vp,T;
int main()
{
 scanf("%d",&n);
 For(i,1,n+1)p[i].scan();
 scanf("%lf%lf",&vp,&vs);
 P.scan();
 For(i,1,n)
 {
  db l=0,r=1e9,mid,t=(p[i+1]-p[i]).dist()/vs;
  For(test,0,100)
  {
   mid=(l+r)/2;
   if(vp*(mid+T)+eps>((p[i+1]-p[i])*(mid/t)+p[i]-P).dist())r=mid;else l=mid;
  }
  if(r<t+eps)
  {
   P=(p[i+1]-p[i])*(r/t)+p[i];
   printf("YES\n%.9f\n%.9f %.9f %.9f\n",r+T,P.x,P.y,P.z);
   return 0;
  }
  T+=t;
 }
 puts("NO");
}