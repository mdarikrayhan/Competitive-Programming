#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps=1e-8;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
int main()
{
	double a,v,l,d,w;
	cin>>a>>v>>l>>d>>w;
	double t1,t2,v0;
	double u=sqrt(w*w/2+a*d);
	double r=l-d;
	if(dcmp(d-v*v/2/a)<=0 && dcmp(sqrt(2*a*d)-w)<=0)
		t1=sqrt(2*d/a),v0=sqrt(2*a*d);
	else if(dcmp(d-v*v/2/a)>=0 && dcmp(w-v)>=0)
		t1=d/v+v/2/a,v0=v;
	else if(dcmp(v-u)>=0 && dcmp(u-w)>=0)
		t1=(2*u-w)/a,v0=w;
	else
		t1=d/v-(2*v*v-w*w)/(2*a*v)+(2*v-w)/a,v0=w;

	if(dcmp(r-(v*v-v0*v0)/(2*a))>=0)
		t2=r/v-(v*v-v0*v0)/(2*a*v)+(v-v0)/a;
	else t2=(sqrt(2*a*r+v0*v0)-v0)/a;

	printf("%.10f\n",t1+t2);
	return 0;
}