#include <iostream>
#include <cmath>
#define sqr(a) ((a)*(a))
using namespace std;
 
double x[5],y[5],r[5],ap[5];
double f(double dx, double dy){
	for (int i=0;i<3;i++)
		ap[i]=sqrt(sqr(dx-x[i])+sqr(dy-y[i]))/r[i];
	
	double re=0.0;
	for (int i=0;i<3;i++)
		re+=sqr(ap[i]-ap[(i+1)%3]);
	return re;
}
 
int main(){
	double s=1.0,dx=0,dy=0;
	for (int i=0;i<3;i++){
		cin >> x[i] >> y[i] >> r[i];
		dx+=x[i]/3.0;
		dy+=y[i]/3.0;
	}
	
	while (s>1e-6){
		if (f(dx,dy)>f(dx+s,dy)) dx+=s;
		else if (f(dx,dy)>f(dx-s,dy)) dx-=s;
		else if (f(dx,dy)>f(dx,dy+s)) dy+=s;
		else if (f(dx,dy)>f(dx,dy-s)) dy-=s;
		else s*=0.7;
	}
	if (f(dx,dy)<0.005) printf("%lf %lf\n", dx, dy);
	return 0;
}
