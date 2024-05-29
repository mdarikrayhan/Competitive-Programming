#include <bits/stdc++.h>

#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define x first
#define y second

using namespace std;

typedef double db;
typedef pair<db,int> pr;

const db pi=acos(-1),eps=1e-12;

int n,K;pr g[8001];
struct ww{
	db x,y;
	db len(){return sqrt(x*x+y*y);}
	ww operator - (ww&A){return{x-A.x,y-A.y};}
}a[1001];db r[1001];


auto calc=[](int i){
	int m=0,ma=0;
	For(j,1,n)if(i^j){
		ww V=a[j]-a[i];
		db A=atan2(V.y,V.x),B=asin((r[j]-r[i])/V.len())+pi/2,G=acos((r[j]+r[i])/V.len());
		for(db S:{0.,2*pi}){
			g[++m]=pr(A-B+S+eps,1);g[++m]=pr(A-G+S-eps,-1);
			g[++m]=pr(A+G+S+eps,1);g[++m]=pr(A+B+S-eps,-1);
		}
	}
	sort(g+1,g+m+1);
	for(int j=1,t=0;j<=m;++j)if((t+=g[j].y)>ma)ma=t;
	return ma;
};

int main(){
	scanf("%d%d",&n,&K);
	For(i,1,n)scanf("%lf%lf%lf",&a[i].x,&a[i].y,r+i);
	printf("%I64d\n",[](){int ma=0;For(i,1,n)ma=max(ma,calc(i));return ma;}()*K+(K+1ll)*K/2+n);
}