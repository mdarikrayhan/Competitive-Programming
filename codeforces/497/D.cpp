#include<bits/stdc++.h>
using namespace std;
typedef double db;
int n,m;
struct V
{
int x,y;
void in(){scanf("%d%d",&x,&y);}
V operator-(const V&A){return(V){x-A.x,y-A.y};}
db operator*(const V&A){return x*A.x+y*A.y;}
db operator^(const V&A){return x*A.y-y*A.x;}
db l(){return sqrt(x*x+y*y);}
}P,Q,A[1005],B[1005];
inline void chk(V A,V b,V c,V Q)
{
b=b-A-Q;c=c-A-Q;
db r1=c.l(),r2=b.l(),ds=(b-c).l();
if(!ds)return;if(r1>r2)swap(r1,r2);
if(c*(c-b)>=0&&b*(b-c)>=0)r1=fabs((b^c)/(b-c).l());
if(r1<=Q.l()&&r2>=Q.l()){puts("YES");exit(0);}
}
int main()
{
P.in();scanf("%d",&n);
for(int i=1;i<=n;i++)A[i].in();
Q.in();scanf("%d",&m);
for(int i=1;i<=m;i++)B[i].in();
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
{
chk(A[i]-P,B[j]-P,B[j%m+1]-P,Q-P);
chk(B[j]-Q,A[i]-Q,A[i%n+1]-Q,P-Q);
}
puts("NO");
return 0;
}
