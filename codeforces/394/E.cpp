#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,n)for(int i=0;i<n;++i)
const int N=100005;
int n,m,flag;double A,B,C,x,y,z;
struct node{
int x,y;
void sum(){A-=2*x,B-=2*y,C+=1.*x*x+1.*y*y;}
void read(){scanf("%d%d",&x,&y);}
}a[N],b[N],D,E;
double cal(){return n*(x*x+y*y)+A*x+B*y+C;}
int main()
{
scanf("%d",&n);rep(i,n)a[i].read(),a[i].sum();
scanf("%d",&m);rep(i,m)b[i].read();b[m]=*b;
x=-A/2/n,y=-B/2/n,z=cal();
rep(i,m)if((b[i+1].x-b[i].x)*(y-b[i].y)-(x-b[i].x)*(b[i+1].y-b[i].y)>0)flag=1;
if(flag){
z=1e30;
rep(i,m){
D=b[i],E=b[i+1];x=D.x,y=D.y,z=min(z,cal());
if(D.x==E.x){
x=D.x,y=B/2/n;if(D.y>E.y)swap(D,E);
if(D.y<y&&y<E.y)z=min(z,cal());
}else{
double k=(E.y-D.y)/(0.+E.x-D.x),l=D.y-k*D.x;
x=-(2*n*k*l+A+B*k)/2/(n+n*k*k),y=k*x+l;if(D.x>E.x)swap(D,E);
if(D.x<x&&x<E.x)z=min(z,cal());
}
}
}
printf("%.8lf\n",z);return 0;
}