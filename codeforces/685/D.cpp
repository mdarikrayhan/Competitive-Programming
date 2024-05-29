#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
int x,y,z;
inline bool operator<(const point t)const{
return x<t.x;
}
};
point p[300000];
long long c[300000];
int d[300000],e[300000],z[300000];
int i,j,l,r,m,n,w,x,y;
int main(){
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++){
scanf("%d%d",&x,&y),z[i]=y,z[n+i]=y-m;
p[i]=(point){x-m,y,1},p[n+i]=(point){x,y,-1};
}
w=2*n;
sort(z+1,z+w+1);
w=unique(z+1,z+w+1)-z-1;
sort(p+1,p+2*n+1);
for(i=1;i<=2*n;i++){
l=lower_bound(z+1,z+w+1,p[i].y-m)-z;
r=lower_bound(z+1,z+w+1,p[i].y)-z;
for(j=l+1;j<=r;j++){
c[e[j]]=c[e[j]]+1LL*(z[j]-z[j-1])*(p[i].x-d[j]);
d[j]=p[i].x;
e[j]=e[j]+p[i].z;
}
}
for(i=1;i<=n;i++)
printf("%I64d ",c[i]);
}