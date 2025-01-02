#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-12;
#define N 1000
struct P{double x,y;P(){}P(double _x,double _y):x(_x),y(_y){}};
int n,m,x[N],y[N],z[N];P a[N];
P calc(int a,int b,int c,int d,int e,int f)
{
    if(a==0&&b==0)return P(d,e);
    if(b==0&&c==0)return P(e,f);
    if(c==0&&a==0)return P(f,d);
    double t=-(a*d+b*e+c*f+0.0)/(a*a+b*b+c*c);
    double x=d+t*a,y=e+t*b,z=f+t*c;
    double aa=sqrt(x*x+y*y+z*z),bb=sqrt(b*b+c*c),cc=sqrt(x*x+(c+y)*(c+y)+(z-b)*(z-b));
    if(fabs(aa)<eps)return P(0,0);
    double ang=acos((aa*aa+bb*bb-cc*cc)/(2*aa*bb));
    if(x<0)ang=-ang;
    return P(aa*cos(ang),aa*sin(ang));
}
inline double dis(const P&a,const P&b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline P getC(double a,double b,double c,double d,double e,double f)
{
    return P((c*e-f*b)/(a*e-b*d),(c*d-f*a)/(b*d-e*a));
}
double chk()
{
    random_shuffle(a+1,a+n+1);
    P o=a[1];double R=0;
    for(int i=2;i<=n;i++)if(dis(o,a[i])>R+eps)
    {
        o=a[i];R=0;
        for(int j=1;j<i;j++)if(dis(o,a[j])>R+eps)
        {
            o=P((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2);R=dis(o,a[j]);
            for(int k=1;k<j;k++)if(dis(o,a[k])>R+eps)
            {
                o=getC(
                    a[j].x-a[i].x,a[j].y-a[i].y,(a[j].x*a[j].x+a[j].y*a[j].y-a[i].x*a[i].x-a[i].y*a[i].y)/2,
                    a[k].x-a[i].x,a[k].y-a[i].y,(a[k].x*a[k].x+a[k].y*a[k].y-a[i].x*a[i].x-a[i].y*a[i].y)/2);
                R=dis(o,a[k]);
            }
        }
    }
    return R;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,y+i,z+i);
    for(int i=1;i<=m;i++)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        for(int j=1;j<=n;j++)a[j]=calc(A,B,C,x[j],y[j],z[j]);
        printf("%.9f\n",chk());
    }
    return 0;
}