#include<bits/stdc++.h>
using namespace std;
#define double long double
const int N=1e5+5;
const double Pi=acos(-1.0),eps=1e-10;
struct point{
	double x,y;
	double angle(){
		double res=atan2(y,x);
		if(res<-eps) res+=2*Pi;
		return res;
	}
}O,a[N];
struct cmp{
	bool operator () (const double a,const double b) {
		return a+eps<b;
	}
};
double calc(double x){
	x+=Pi;
	if(x>=2*Pi) x-=2*Pi;
	return x;
}
multiset<double,cmp> mp;
int cnt1,cnt2;
void ins(int u){
	if(fabs(a[u].x)<eps&&fabs(a[u].y)<eps) return (void)(++cnt1);
	double tmp=a[u].angle();
	if(mp.find(tmp)==mp.end()&&mp.find(calc(tmp))!=mp.end()) ++cnt2;
	mp.insert(tmp);
	//if(u==2) printf("%.9lf %.9lf ???????\n",tmp,calc(tmp));
	//if(u==2) printf("%.9lf %.9lf ???????\n",a[u].angle(),calc(a[u].angle()));
}
void del(int u){
	if(fabs(a[u].x)<eps&&fabs(a[u].y)<eps) return (void)(--cnt1);
	double tmp=a[u].angle();
	mp.erase(mp.find(tmp));
	if(mp.find(tmp)==mp.end()&&mp.find(calc(tmp))!=mp.end()) --cnt2;
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	int n,X,Y,Z;
	cin>>X>>Y>>Z>>n,O.x=1.0*X/(X+Y+Z),O.y=1.0*Y/(X+Y+Z);
	for(int i=1,tot=0;i<=n;++i){
		char op;
		cin>>op;
		if(op=='A') cin>>X>>Y>>Z,++tot,a[tot].x=1.0*X/(X+Y+Z)-O.x,a[tot].y=1.0*Y/(X+Y+Z)-O.y,ins(tot);
		else cin>>X,del(X);
		if(cnt1) cout<<"1\n";
		else if(cnt2) cout<<"2\n";
		else{
			bool fl=1;
			if(mp.size()<3) fl=0;
			else if(*mp.rbegin()-*mp.begin()<Pi) fl=0;
			else{
				auto it=mp.lower_bound(Pi);
				if(it==mp.end()||it==mp.begin()) fl=0;
				else{
					if(*it-*prev(it)>Pi) fl=0;	
				}
			}
			if(fl) cout<<"3\n";
			else cout<<"0\n";
		}
	}
	//printf("%.9lf %.9lf %.9lf ???\n",a[1].angle(),a[2].angle(),calc(a[2].angle()));
	//cout<<a[2].angle()<<" "<<calc(a[2].angle())<<" ????\n";
}