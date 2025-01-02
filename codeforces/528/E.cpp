#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
int a,b,c;
bool operator < (const node &x) const
{
return a*x.b<x.a*b;
}
}l[3030];
int n;
double ans;
void calc(node x,node y,double &px,double &py)
{
py=-1.0*(x.c*y.b-y.c*x.b)/(x.a*y.b-y.a*x.b);
px=-1.0*(x.c*y.a-y.c*x.a)/(x.b*y.a-x.a*y.b);
}
signed main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>l[i].a>>l[i].b>>l[i].c;
if(l[i].a<0||(l[i].a==0&&l[i].b<0))
{
l[i].a*=-1;
l[i].b*=-1;
l[i].c*=-1;
}
}
sort(l+1,l+n+1);
for(int i=1;i<=n;i++)
{
double px=0,py=0,sx=0,sy=0;
for(int j=i%n+1;j!=i;j=j%n+1)
{
calc(l[i],l[j],px,py);
ans+=sx*py-sy*px;
sx+=px;
sy+=py;
}
}
printf("%.10lf\n",ans/2/(1ll*n*(n-1)*(n-2)/6));
return 0;
}
