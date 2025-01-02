// LUOGU_RID: 155083523
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <array>
#include <queue>
using namespace std;
#define double long double
typedef long long LL;
const int N=5e4+5;
const double PI=acos(-1);
int sgn(double x)
{
    if (fabs(x)<1e-12) return 0;
    if (x<0) return -1;
    return 1;
}
void solve()
{
    double a,b,l;
    scanf("%Lf%Lf%Lf",&a,&b,&l);
    double ans=l;
    if (l<=a) ans=min(b,l);
    else if (l<=b) ans=min(a,l);
    else 
    for (double deg=0;deg<=PI/2;deg+=1e-6)
    {
      //  cout<<ans<<'\n';
        ans=min(ans,a*cosl(deg)-(l*cosl(deg)-b)*sinl(deg));
    }

    if (sgn(ans)<=0) printf("My poor head =(\n");
    else printf("%.12Lf\n", ans);
}
int main()
{

    int T=1;
  //  scanf("%d",&T);
    while (T--)  solve();
    return 0;
}