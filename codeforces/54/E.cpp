#include<bits/stdc++.h>
using namespace std;
#define X real()
#define Y imag()
typedef long long ll;
typedef double ld; 
typedef complex<ld> point;
const ld eps=1e-9;
const int MAX=1e5+9;
int n;
point a[MAX],z;
ld ans=1e18;
ld cross(point a,point b){return a.X*b.Y-b.X*a.Y;}
ld dot(point a,point b){return a.X*b.X+a.Y*b.Y;}
ld cross(point a,point b,point c){return abs(cross(b-a,c-a));}
ld dot(point a,point b,point c){return dot(b-a,c-a);}
ld p(ld x){return x*x;}
ld dis(point a,point b){return p(a.X-b.X)+p(a.Y-b.Y);}
void cal()
{
 int p=1;
 ld sum=0;
 for (int i=0;i<n;i++)
 {
  while (dot(a[i],a[p],a[(i+1)%n])<dot(a[i],a[(p+1)%n],a[(i+1)%n])) sum+=cross(a[i],a[p],a[(p+1)%n]),p=(p+1)%n; 
  ans=min(ans,dot(a[i],a[p],a[(i+1)%n])/dis(a[i],a[(i+1)%n])*cross(a[i],a[p],a[(i+1)%n])/2.0-sum/2.0);
  sum-=abs(cross(a[p],a[i],a[(i+1)%n]));
 }
}
int main()
{
 ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 cin>>n;
 for (int i=0,x,y;i<n;i++) cin>>x>>y,a[i]={1.0*x,1.0*y};
 cal(),reverse(a,a+n),cal();
 cout<<fixed<<setprecision(9)<<ans<<endl;
 return 0;
}