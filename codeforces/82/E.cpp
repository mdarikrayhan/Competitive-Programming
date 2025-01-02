#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
int n,h,f,l[1010],r[1010];
double ans;
double calc(double x,double y) {
 if (x==0||y==0) return 0;
 if (x<0||y<0) x=-x,y=-y;
 if (y<x) swap(x,y);
 if (y*(f-h)>x*(f+h)) return x*(1.*(f+h)/(f-h)+1)*h;
 double a=f*(y-x)/(y+x),z=x*(f+a)/(f-h);
 return ((y+z)*(h-a)+(x+z)*(h+a))/2;
}
int main() {
 scanf("%d%d%d",&n,&h,&f);
 rep(i,0,n) {
  scanf("%d%d",l+i,r+i);
  if (l[i]<0&&r[i]>0) r[i+1]=r[i],r[i]=0,l[++i]=0,++n;
 }
 ans=0;
 rep(i,0,n) ans+=(r[i]-l[i])*(1.*(f+h)/(f-h)+1)*2*h;
 rep(i,0,n) rep(j,0,n) if (l[i]<0&&l[j]<0||r[i]>0&&r[j]>0)
  ans-=calc(l[i],l[j])+calc(r[i],r[j])-calc(l[i],r[j])-calc(r[i],l[j]);
 printf("%.9f\n",ans);
}