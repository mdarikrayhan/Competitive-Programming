//https://codeforces.com/contest/799/submission/27199363
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=10000;
const double PI=acos(-1);
typedef struct P { int x,y; } P;
typedef struct L { double a,b,c; double get(const P &p) const { return a*p.x+b*p.y+c; } } L;

int n,nq;
P p[MAXN+1];
double sumarea[MAXN+1];

double area(double ax,double ay,double bx,double by,double cx,double cy) {
	bx-=ax,by-=ay,cx-=ax,cy-=ay;
	return bx*cy-by*cx;
}
ll area(const P &a,const P &b,const P &c) {
	int bx=b.x-a.x,by=b.y-a.y,cx=c.x-a.x,cy=c.y-a.y;
	return (ll)bx*cy-(ll)by*cx;
}
int findfirstnonpos(const L &line,int l,int r) { // (l,r]
	while(l+1<r) { int m=l+(r-l)/2; if(line.get(p[m])<=0) r=m; else l=m; } return r;
}
int findlastnonpos(const L &line,int l,int r) { // [l,r)
	while(l+1<r) { int m=l+(r-l)/2; if(line.get(p[m])<=0) l=m; else r=m; } return l;
}
int findanypos(const L &line) {
	int l=0,r=n-1; double vl=line.get(p[l]); //(l,r]
	while(l<r) {
		int m=l+(r-l+1)/2;
		double vm=line.get(p[m]);
		if(vm>0) return m;
		if(vm<=vl) { r=m-1; continue; }
		double vp=line.get(p[m-1]);
		if(vp<vm) l=m,vl=vm; else r=m-1;
	}
	assert(false); return -1;
}
int findanyneg(const L &line) {
	int l=1,r=n; double vr=line.get(p[l]); //[l,r)
	while(l<r) {
		int m=l+(r-l)/2;
		double vm=line.get(p[m]);
		if(vm<0) return m;
		if(vm>=vr) { l=m+1; continue; }
		double vp=line.get(p[m-1]);
		if(vp>vm) l=m+1; else r=m,vr=vm;
	}
	assert(false); return -1;
}
bool intersect(const L &u,const P &a,const P &b,double &x,double &y) {
	int dx=b.x-a.x,dy=b.y-a.y; L v; v.a=dy,v.b=-dx,v.c=-(v.a*a.x+v.b*a.y);
	double den=u.a*v.b-u.b*v.a;
	double xnum=u.b*v.c-u.c*v.b;
	double ynum=-(u.a*v.c-u.c*v.a);
	if(fabs(den)<1e-9) return false;
	x=xnum/den,y=ynum/den; return true;
}

int calc(const P &q,double ang) {
	double dx=cos(ang),dy=sin(ang);
	L line; line.a=dy,line.b=-dx,line.c=-(line.a*q.x+line.b*q.y);
	double v0=line.get(p[0]),v1=line.get(p[1]);
	bool flip=false; if(v0>v1) line.a=-line.a,line.b=-line.b,line.c=-line.c,v0=-v0,v1=-v1,flip=true;
	//printf("ang=%lf a=%lf b=%lf c=%lf -> v0=%lf v1=%lf\n",ang,line.a,line.b,line.c,v0,v1);

	int u,v;
	if(v0<=0) {
		int opp=findanypos(line);
		u=findlastnonpos(line,0,opp),v=findfirstnonpos(line,opp,n);
	} else {
		int opp=findanyneg(line);
		u=findfirstnonpos(line,0,opp)-1,v=findlastnonpos(line,opp,n)+1;
	}
	//printf("%d..%d\n",u,v);

	double ux,uy; assert(intersect(line,p[u],p[u+1],ux,uy));
	double vx,vy; assert(intersect(line,p[v-1],p[v],vx,vy));
	//printf("(%lf,%lf) (%lf,%lf)\n",ux,uy,vx,vy);

	double me=sumarea[u]+sumarea[n]-sumarea[v]+area(p[0],p[u],p[v]);
	me+=area(p[u].x,p[u].y,vx,vy,p[v].x,p[v].y);
	me+=area(p[u].x,p[u].y,ux,uy,vx,vy);
	double oth=sumarea[n]-me;
	if(v0<=0) swap(me,oth);
	if(flip) swap(me,oth);
	double cur=me-oth;
	//printf("%lf: me=%lf oth=%lf -> %lf [%lf]\n",ang,me,oth,cur,fabs(me-oth)/(me+oth));
	if(fabs(me-oth)/(me+oth)<=1e-4) return 0;
	return cur>0?+1:-1;
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); p[n]=p[0]; reverse(p+1,p+n);
	sumarea[0]=sumarea[1]=0; FORE(i,2,n) sumarea[i]=sumarea[i-1]+area(p[0],p[i-1],p[i]);
	//REPE(i,n) printf("%d: %lf\n",i,sumarea[i]);
	//P q; q.x=5,q.y=4; calc(q,0); return;
	REP(qi,nq) {
		P q; scanf("%d%d",&q.x,&q.y);
		double l=0,h=PI; int lval=calc(q,l);
		REP(rep,35) {
			if(lval==0) break;
			double m=l+(h-l)/2; int mval=calc(q,m);
			if(mval==-lval) h=m; else l=m,lval=mval;
		}
		printf("%.15lf\n",l);
	}
}

int main() {
	run();
	return 0;
}
