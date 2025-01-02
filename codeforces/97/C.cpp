#include <cstdio>
int n,i,j;
double a[101],z,ans;
main()
{
 scanf("%d",&n);
 for (i=0;i<=n;++i) scanf("%lf",&a[i]);
 for (i=0;i<=n/2;++i) for (j=n/2+1;j<=n;++j)
 {
  z=(a[i]*(2*j-n)+a[j]*(n-2*i))/2/(j-i);
  if (z>ans) ans=z;
 }
 printf("%.10lf\n",ans);
}