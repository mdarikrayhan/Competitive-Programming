// LUOGU_RID: 156017215
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <array>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long LL;
const int N=2e5+5,mod=998244353;
int sgn(double x)
{
    if (fabs(x)<1e-12) return 0;
    if (x<0) return -1;
    return 1;
}
struct Point
{
    double x,y;
    Point(){};
    Point(double _x,double _y) {x=_x,y=_y;}
    Point operator+(Point b) {return Point(x+b.x,y+b.y);}
    Point operator-(Point b) {return Point(x-b.x,y-b.y);}
    Point operator*(double k) {return Point(x*k,y*k);}
    double operator*(Point b) {return x*b.x+y*b.y;}
    double operator%(Point b) {return x*b.y-y*b.x;}
    bool operator==(Point b) {return !sgn(x-b.x)&&!sgn(y-b.y);}
    bool operator<(Point b) {return sgn(x-b.x)<0||(sgn(x-b.x)==0&&sgn(y-b.y)<0);}
    Point rotate(double c) {return Point(x*cos(c)-y*sin(c),x*sin(c)+y*cos(c));}
}p[N];
double dist(Point a,Point b) {return sqrt((a-b)*(a-b));}
int n,k;
double cal1(int l,int r)
{
    return dist(p[l],p[r])+min(dist(p[l],p[n+1]),dist(p[r],p[n+1]));
}
double cal2(int l,int r)
{
    return dist(p[l],p[r])+min(dist(p[l],p[n+1])+dist(p[0],p[r]),dist(p[r],p[n+1])+dist(p[0],p[l]));
}
void solve()
{
    
    cin>>n>>k;
    for (int i=1;i<=n+1;i++) cin>>p[i].x,p[i].y=0;
    cin>>p[n+1].y;
    p[0]=p[k];
    sort(p+1,p+n+1);
    double ans=2e9;
    if (k==n+1) ans=cal1(1,n);
    else
    {
        ans=cal2(1,n);
        for (int i=1;i<n;i++)
        {
            double res=min(cal1(1,i)+cal2(i+1,n),cal2(1,i)+cal1(i+1,n));
            ans=min(ans,res);
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
  // scanf("%d",&T);
    while (T--) solve();
    return 0;
}