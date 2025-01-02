#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int s,n,nf,ne,ns,df,de,p1,p2,c;
double p[120],uf,ue,w,z,rf,re,rs;
double in(double x,double y,double a,double b)
{
return max(min(y,b)-max(x,a),0.);
}
int main()
{
scanf("%d%d%d%lf%lf%lf%d%d",&nf,&ne,&ns,&rf,&re,&rs,&df,&de);
rf=sqrt(rf*rf-1),re=sqrt(re*re-1),rs=sqrt(rs*rs-1),n=nf+ne+ns,s=1<<n;
for(int i=0;i<s;i++)
{
if(__builtin_popcount(i)!=ns)
continue;
w=c=0;
for(int j=s-i-1;j;j-=j&-j)
{
p1=__builtin_ctz(j)>>1;
uf=df*rf*2,ue=de*re*2;
for(int k=i;k;k-=k&-k)
{
p2=__builtin_ctz(k)>>1;
uf+=df*in(p1-rs,p1+rs,p2-rf,p2+rf);
ue+=de*in(p1-rs,p1+rs,p2-re,p2+re);
}
w+=uf;
p[c++]=uf-ue;
}
sort(p,p+c);
for(int i=0;i<ne;i++)
w-=p[i];
z=max(z,w);
}
printf("%.10f\n",z);
return 0;
}