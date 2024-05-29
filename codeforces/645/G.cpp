#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int n,a,x[N],y[N],st[N*2];
double r[N],d[N];
vector<pair<double,int>>b;
bool chk(double w){
	int i,t=0;
	double p,q,u,v,o,z;
	b.clear();
	for(i=1;i<=n;++i)if(w+r[i]>d[i]&&fabs(r[i]-w)<d[i]){
		z=(d[i]*d[i]+w*w-r[i]*r[i])/(2*d[i]),o=z/d[i],p=x[i]*o,q=y[i]*o,o=sqrt(w*w-z*z)/d[i];
		b.push_back({atan2(q-x[i]*o,p+y[i]*o),i}),b.push_back({atan2(q+x[i]*o,p-y[i]*o),i});
	}
	sort(b.begin(),b.end());
	for(auto o:b)if(st[t]==o.second)--t;else st[++t]=o.second;
	return t;
}
int main(){
	int i;
	double l=0,r,m;
	scanf("%d%d",&n,&a),r=2*a;
	for(i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i);
		::r[i]=sqrt((x[i]+a)*(x[i]+a)+y[i]*y[i]);
		x[i]-=a;
		d[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	while(r-l>1e-8){
		m=(l+r)/2;
		if(chk(m))r=m;
		else l=m;
	}
	printf("%.9lf",r);
	return 0;
}