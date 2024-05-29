#include<bits/stdc++.h> 
using namespace std;
double const eps=1e-12;double x,y,z,v,f[5050];
struct node{double x,y;}a[5050];long long i,j,n,s,u,w,tot;
int main(){
scanf("%d",&n);
for (i=1;i<=n;i++){
scanf("%lf%lf%lf",&x,&y,&z);
v=z/(x*x+y*y);a[i]={x*v,y*v};
}
for (i=1;i<=n;i++){
for (tot=u=0,j=i+1;j<=n;j++)
if (a[i].x==a[j].x&&a[i].y==a[j].y)
s+=n-i-(++u);
else if (fabs(a[i].x-a[j].x)>eps)
f[++tot]=(a[i].y-a[j].y)/(a[i].x-a[j].x);
else f[++tot]=1e18;
sort(f+1,f+1+tot);
for (w=0,j=2;j<=tot;s+=w,j++)
w=(fabs(f[j]-f[j-1])<eps)?(w+1):0;
}
printf("%lld\n",s);
return 0;
}