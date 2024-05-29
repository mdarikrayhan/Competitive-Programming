#include<bits/stdc++.h>
using namespace std;
#define db double
#define eps 1e-7
#define N 1100
struct P{db x,y,vx,vy;inline void rd(){db t1,t2;scanf("%lf%lf%lf%lf%lf%lf",&t1,&x,&y,&t2,&vx,&vy);t2-=t1;vx=(vx-x)/t2;vy=(vy-y)/t2;x-=vx*t1;y-=vy*t1;}}p[N],q;
struct V{db x,y;}b[N];
inline db det(const V&a,const V&b){return a.x*b.y-a.y*b.x;}
inline bool cmp(const V&a,const V&b){if(abs(det(a,b))<eps)return(abs(a.x-b.x)<eps)?a.y<b.y:a.x<b.x;return det(a,b)<0;}
int n,ans,tot,cnt;db a[N];
int main()
{
scanf("%d",&n);
for(int i=1;i<=n;i++)p[i].rd();
for(int i=1;i<=n;i++)
{
tot=0;
for(int j=1;j<=n;j++)if(i^j)
{
q.x=p[j].x-p[i].x;q.y=p[j].y-p[i].y;q.vx=p[j].vx-p[i].vx;q.vy=p[j].vy-p[i].vy;
db t=q.vx?q.x/q.vx:(q.vy?q.y/q.vy:0);
if(abs(q.x-q.vx*t)<eps&&abs(q.y-q.vy*t)<eps){a[++tot]=t;b[tot].x=q.vx;b[tot].y=q.vy;}
}
sort(a+1,a+tot+1);cnt=0;
for(int j=1;j<=tot;j++){cnt=(abs(a[j]-a[j-1])<eps)?cnt+1:1;ans=max(ans,cnt);}
sort(b+1,b+tot+1,cmp);cnt=1;
for(int j=2;j<=tot;j++)
{
if(abs(det(b[j],b[j-1]))<eps){if(abs(b[j].x-b[j-1].x)>eps||abs(b[j].y-b[j-1].y)>eps)cnt++;}else cnt=1;
ans=max(ans,cnt);
}
}
printf("%d\n",ans+1);
return 0;
}