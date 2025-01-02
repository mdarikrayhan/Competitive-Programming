#include<bits/stdc++.h>
#define db long double
using namespace std;
const int N=1e3+5;
int w,h,n,a[N],b[N];
db ans=-8e18;
mt19937 rnd(time(0));
db calc(db x,db y){
	db mn=8e18,mn2=8e18,d;
	for(int i=1;i<=n;i++){
		d=(x-a[i])*(x-a[i])+(y-b[i])*(y-b[i]);
		if(d<=mn) mn2=mn,mn=d;
		else mn2=min(mn2,d);
	}
	return mn2;
}
db rd(db l,db r){
	return l+(r-l)*rnd()/rnd.max();
}
void SA(){
	db x=rd(0,w),y=rd(0,h),v=calc(x,y);
	ans=max(ans,v);
	for(db t=0.4;t>1e-12;t*=0.995){
		db nx=max((db)0,min((db)w,x+rd(-w,w)*t)),ny=max((db)0,min((db)h,y+rd(-h,h)*t)),nv=calc(nx,ny);
		ans=max(ans,nv);
		if(nv>v||rnd()<exp((nv-v)/t)*rnd.max()) x=nx,y=ny,v=nv;
	}
}
signed main(){
	scanf("%d%d%d",&w,&h,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=60;i++) SA();
	printf("%.12Lf\n",sqrtl(ans));
	return 0;
}