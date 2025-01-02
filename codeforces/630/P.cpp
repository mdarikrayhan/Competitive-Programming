// LUOGU_RID: 160436961
#include<bits/stdc++.h>
#define pi 3.1415926535897932
using namespace std;
double n,r,s,a,b,c,x,y;
int main(){
	scanf("%lf%lf",&n,&r);
	a=pi/(2.0*n);
	b=pi-3*pi/(2.0*n);
	x=r;
	y=x*sin(pi/(2.0*n))/sin(b);
	s=0.5*y*r*sin(2*a);
	printf("%.12lf",n*s*2);
}

