#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const double eps=1e-8;
int n,m,ans;
double x[1005],y[1005];
bool eq(double a,double b){return fabs(a-b)<eps;}
struct point{
	double x,y,k;
	bool operator < (const point &a)const{
		if(eq(x,a.x)) return eq(y,a.y)?k<a.k:y<a.y;
		return x<a.x;
	}
} a[500005];
int main(){
	cin>>n;
	for(int i=1,a,b,c,d;i<=n;++i){
		cin>>a>>b>>c>>d;
		double X=1.*a/b,Y=1.*c/d;
		x[i]=1.*X/(X*X+Y*Y);
		y[i]=1.*Y/(X*X+Y*Y);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			a[++m]={x[i]+x[j],y[i]+y[j],eq(x[i],x[j])?1e20:1.*(y[i]-y[j])/(x[i]-x[j])};
	sort(a+1,a+m+1);
	for(int l=1,r;l<=m;l=r){
		for(r=l;eq(a[l].x,a[r].x)&&eq(a[l].y,a[r].y);++r);
		int cnt=1,res=1;
		for(int i=l;i<r;++i){
			if(i==r-1||!eq(a[i].k,a[i+1].k)) res=1ll*res*(cnt+1)%mod,cnt=1;
			else ++cnt;
		}
		res=(res-(r-l+1)+mod)%mod;
		(ans+=res)%=mod;
	}
	cout<<ans;
	return 0;
}