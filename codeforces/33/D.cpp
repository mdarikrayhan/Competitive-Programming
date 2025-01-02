// LUOGU_RID: 160217075
#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
double n,m,k;
pair<double,double> poi[N+5];
struct Node
	{double x,y;double r;}cir[N+5];
bitset<1005> bs[1005];
bool Check(double x,double y,double r,double cx,double cy)
{
	double dis=sqrt((cx-x)*(cx-x)+(cy-y)*(cy-y));
	return dis<r;
}
int main()
{
	scanf("%lf%lf%lf",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&poi[i].first,&poi[i].second);
	for(int i=1;i<=m;i++)
		scanf("%lf%lf%lf",&cir[i].r,&cir[i].x,&cir[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(Check(poi[i].first,poi[i].second,cir[j].r,cir[j].x,cir[j].y))
				bs[i][j]=1;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		bs[0]=bs[a]^bs[b];
		printf("%d\n",bs[0].count());
	}
	return 0;
}

