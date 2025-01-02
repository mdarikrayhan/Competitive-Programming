#include<bits/stdc++.h>
#define y1 Y1
#define y0 Y0
using namespace std;
double x1,y1,x2,y2,x0,y0,d;
int n,tot;
pair<double,int>T[200005];
double Q(double x,double y){
return sqrt(x*x+y*y);
}
int main(){
scanf("%lf%lf%lf%lf%d",&x1,&y1,&x2,&y2,&n);
x0=(x1+x2)/2;y0=(y1+y2)/2;d=Q(x0-x1,y0-y1);
for(int i=1;i<=n;i++){
double x,y,xx,yy,r;
scanf("%lf%lf%lf",&x,&y,&r);
yy=((y-y0)-(x-x0)*(y1-y0)/(x1-x0))/d*(x1-x0);
xx=((y-y0)-(x-x0)*(y1-y0)/(x1-x0))/d*(y1-y0)+(x-x0)*d/(x1-x0);
double md=(xx+d)/2/yy*(xx-d)+yy/2;
double L=-1e10,R=md;
for(int T=0;T<=100;T++){
double M=(L+R)/2;
if(abs(Q(d,M)-Q(xx,yy-M))<r)R=M;
else L=M;
}
T[++tot]=make_pair(L,1);
L=md,R=1e10;
for(int T=0;T<=100;T++){
double M=(L+R)/2;
if(abs(Q(d,M)-Q(xx,yy-M))<r)L=M;
else R=M;
}
T[++tot]=make_pair(L,-1);
}
T[++tot]=make_pair(0,0);
sort(T+1,T+tot+1);
double ans=1e15;
for(int i=1,s=0;i<=tot;i++){
if(!s)ans=min(ans,Q(d,T[i].first));
s+=T[i].second;
if(!s)ans=min(ans,Q(d,T[i].first));
}
printf("%.15lf\n",ans);
}