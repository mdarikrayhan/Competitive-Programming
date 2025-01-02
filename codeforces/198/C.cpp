#include<bits/stdc++.h>
using namespace std;
typedef long double lb;
const lb pi=acos(-1);
lb xp,yp,vp,x,y,v,r,R,len1,len2,deg1,deg2,tl,tr,ans;
inline lb check(lb t){
	lb deg=atan2(yp,xp)+t*vp,nx=R*cos(deg),ny=R*sin(deg),M=atan2(y,x)-atan2(ny,nx);
	if (M<0) M=-M;
	if (M>pi) M=pi*2-M;
	return deg1+deg2>=M?sqrt((x-nx)*(x-nx)+(y-ny)*(y-ny)):len1+len2+r*(M-deg1-deg2);
}
int main(){
	cin>>xp>>yp>>vp>>x>>y>>v>>r;
	R=sqrt(xp*xp+yp*yp);
	len1=sqrt(x*x+y*y-r*r),len2=sqrt(R*R-r*r);
	deg1=atan(len1/r),deg2=atan(len2/r);
	tl=0,tr=1e9; vp/=R;
	for (int i=1; i<=100; i++){
		lb mid=(tl+tr)/2;
		if (check(mid)/v<=mid) ans=mid,tr=mid;
		else tl=mid;
	}
	printf("%.9lf\n",(double)ans);
}