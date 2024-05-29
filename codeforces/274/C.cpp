#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

int n,i,j,k,l;
int x[105],y[105],dist[105][105];
double ans,a,b,a1,a2,b1,b2,c1,c2;

int cal(int a,int b,int c){return(x[b]-x[a])*(x[c]-x[a])+(y[b]-y[a])*(y[c]-y[a]);}
void check(double X,double Y,double Min)
{
int i;double tmp;
for(i=1;i<=n;++i)
{
tmp=sqrt((x[i]-X)*(x[i]-X)+(y[i]-Y)*(y[i]-Y));
if(tmp+0.000001<Min)return;
}
if(Min>ans)ans=Min;
}

int main()
{
scanf("%d",&n);
for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
for(i=1;i<=n;++i)
for(j=1;j<=n;++j)
dist[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
for(i=1;i<=n;++i)
for(j=i+1;j<=n;++j)
for(k=j+1;k<=n;++k)
if(cal(i,j,k)>0&&cal(j,i,k)>0&&cal(k,i,j)>0)
{
a1=-2*(x[j]-x[i]);b1=-2*(y[j]-y[i]);c1=x[i]*x[i]-x[j]*x[j]+y[i]*y[i]-y[j]*y[j];
a2=-2*(x[k]-x[i]);b2=-2*(y[k]-y[i]);c2=x[i]*x[i]-x[k]*x[k]+y[i]*y[i]-y[k]*y[k];
if(x[i]==x[j])swap(a1,a2),swap(b1,b2),swap(c1,c2);
b2-=b1*a2/a1;c2-=c1*a2/a1;a2=0;
b=c2/b2;c1-=b*b1;b1=0;a=c1/a1;
check(a,b,sqrt((x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b)));
}
for(i=1;i<=n;++i)
for(j=1;j<=n;++j)if(i!=j)
for(k=1;k<=n;++k)if(i!=k&&j!=k)
for(l=1;l<=n;++l)if(i!=l&&j!=l&&k!=l)
if(dist[i][j]==dist[k][l]&&dist[i][k]==dist[j][l]&&dist[i][j]+dist[j][k]==dist[i][k])
check(0.5*(x[i]+x[k]),0.5*(y[i]+y[k]),sqrt(dist[i][k])/2);
if(ans<0.0001)printf("-1\n");
else printf("%.20lf\n",ans);
}