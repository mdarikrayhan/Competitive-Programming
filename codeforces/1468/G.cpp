#include <bits/stdc++.h>
using namespace std;
//
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define qwq ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define QWQ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define jump ;return 0;
#define space " "
#define m0(a) memset((a),0,sizeof(a));
#define mINF(a) memset((a),0x3f,sizeof(a));
#define mNINF(a) memset((a),-0x3f,sizeof(a));
#define mNeg(a) memset((a),-1,sizeof(a));
using mainint=signed;using ll=long long;
template<class T>void gmin(T &a,T b){if(a>b) a=b;}
template<class T>void gmax(T &a,T b){if(a<b) a=b;};using pll=pair<ll,ll>;using pil=pair<int,ll>;using Pli=pair<ll,int>;const int INF=0x3f3f3f3f;const ll INFINF=123456789123456789;

const double eps=1e-8;
const double pi=acos(-1.0);
int sgn(double x){
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}
struct point{
	double x,y;
	point(){x=0,y=0;}
	point(double _x,double _y){
		x=_x,y=_y;
	}
	inline point operator +(point b){return point(x+b.x,y+b.y);}
	inline point operator -(point b){return point(x-b.x,y-b.y);}
	inline double operator *(point b){return x*b.x+y*b.y;}//点只因
	inline double operator ^(point b){return x*b.y-y*b.x;}//叉只因,逆正顺负
	double distoO(){return sqrt(x*x+y*y);}
	double getlength(){return sqrt(x*x+y*y);}
	void transXY(double B){ 
		double tx=x,ty=y;
		x=tx*cos(B)-ty*sin(B); 
		y=tx*sin(B)+ty*cos(B);
	}
	friend ostream& operator <<(ostream& output,point a){
		output<<a.x<<" "<<a.y<<" ";
		return output;
	}
	
};
int Quadrant(point a)
{
    if(a.x>0&&a.y>=0)  return 1;
    if(a.x<=0&&a.y>0)  return 2;
    if(a.x<0&&a.y<=0)  return 3;
    if(a.x>=0&&a.y<0)  return 4;
	return 0;
}
bool cmp_chaji(point a,point b){
	point c(0,0);
	int op=sgn((a-c)^(b-c));
	if(op>0) return 1;
	if(op==0) return a.x<b.x;
	return 0;
}
bool cmp_jijiao(point a,point b){
	if(atan2(a.y,a.x)!=atan2(b.y,b.x))
		return atan2(a.y,a.x)<atan2(b.y,b.x);//或者预处理
	return a.x<b.x;
}
bool cmp_complex_chaji(point a,point b){
	if(Quadrant(a)!=Quadrant(b)) return Quadrant(a)<Quadrant(b);
	return cmp_chaji(a,b);
}
bool cmp_complex_jijiao(point a,point b){
	if(Quadrant(a)!=Quadrant(b)) return Quadrant(a)<Quadrant(b);
	return cmp_chaji(a,b);
}

inline double dis(point &a,point &b){
	return sqrt((a-b)*(a-b));
}
double dis2(point a,point b){
	return ((a-b)*(a-b));
}
struct line{
	point a,b;
	line(){a.x=a.y=0;b.x=b.y=1;}
	line(point c,point d){a=c,b=d;}
	line(double _a,double _b,double _c,double _d){
		a.x=_a,a.y=_b;b.x=_c,b.y=_d;
	}
	inline pair<int,point> operator &(line &c){
		point temp=a;
		if(sgn((a-b)^(c.a-c.b))==0) return {0,a.x<b.x ? a : b};
		double t=((a-c.a)^(c.a-c.b))/((a-b)^(c.a-c.b));
		temp.x+=(b.x-a.x)*t;
		temp.y+=(b.y-a.y)*t;
		return {2,temp};
	}
};
bool line_cross(line a,line b){
	return 
	max(a.a.x,a.b.x)>=min(b.a.x,b.b.x) &&
	max(b.a.x,b.b.x)>=min(a.a.x,a.b.x) &&
	max(a.a.y,a.b.y)>=min(b.a.y,b.b.y) &&
	max(b.a.y,b.b.y)>=min(a.a.y,a.b.y) &&
	sgn((b.a-a.b)^(a.a-a.b))*sgn((b.b-a.b)^(a.a-a.b))<=0 &&
	sgn((a.a-b.b)^(b.a-b.b))*sgn((a.b-b.b)^(b.a-b.b))<=0;
}
bool line_cross_sei(line a,line b){
	return 
	max(a.a.x,a.b.x)>min(b.a.x,b.b.x) &&
	max(b.a.x,b.b.x)>min(a.a.x,a.b.x) &&
	max(a.a.y,a.b.y)>min(b.a.y,b.b.y) &&
	max(b.a.y,b.b.y)>min(a.a.y,a.b.y) &&
	sgn((b.a-a.b)^(a.a-a.b))*sgn((b.b-a.b)^(a.a-a.b))<=0 &&
	sgn((a.a-b.b)^(b.a-b.b))*sgn((a.b-b.b)^(b.a-b.b))<=0;
}
bool line_cross_seg(line l1,line l2){
	return sgn((l2.a-l1.b)^(l1.a-l1.b))*sgn((l2.b-l1.b)^(l1.a-l1.b))<=0;
}
bool ispointonseg(point p,line len){
	return sgn((len.a-p)^(len.b-p))==0 &&
	sgn((p.x-len.a.x)*(p.x-len.b.x))<=0 &&
	sgn((p.y-len.a.y)*(p.y-len.b.y))<=0;
}
bool ispointonline(point p,line len){
	return sgn((len.a-p)^(len.b-p))==0;
}
point pointtoline(point p,line len){
	point temp(0,0);
	double t=((p-len.a)*(len.b-len.a))/((len.b-len.a)*(len.b-len.a));
	temp.x=len.a.x+t*(len.b.x-len.a.x);
	temp.y=len.a.y+t*(len.b.y-len.a.y);
	return temp;
}
inline point pointtoseg(point p,line len){
	point temp(0,0);
	double t=((p-len.a)*(len.b-len.a))/((len.b-len.a)*(len.b-len.a));
	if(t>=0 && t<=1){
		temp.x=len.a.x+t*(len.b.x-len.a.x);
		temp.y=len.a.y+t*(len.b.y-len.a.y);
	}
	else{
		if(dis(p,len.a)>=dis(p,len.b)) temp=len.b;
		else temp=len.a;
	}
	return temp;
}
double ka[4],kb[4];
point LineCrossLine(line &a,line &b){
	ka[1]=a.a.y-a.b.y;
	ka[2]=a.b.x-a.a.x;
	ka[3]=a.a.x*a.b.y-a.b.x*a.a.y;
	kb[1]=b.a.y-b.b.y;
	kb[2]=b.b.x-b.a.x;
	kb[3]=b.a.x*b.b.y-b.b.x*b.a.y;
	double D=(ka[1]*kb[2]-ka[2]*kb[1]);
	point p;
	p.x=(ka[2]*kb[3]-kb[2]*ka[3])/D;
	p.y=(ka[3]*kb[1]-kb[3]*ka[1])/D;
	return p;
}
bool operator <(point &a,point &b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

point p[200005],Q,R;
inline double getk(point &a,point &b){
	return (a.y-b.y)/(a.x-b.x);
}
mainint main(){
    qwq
	int n,H;
	cin>>n>>H;
	for(int i=1,X,Y;i<=n;++i){
		cin>>X>>Y;
		p[i].x=X,p[i].y=Y;
	
	}
	Q.x=p[n].x,Q.y=p[n].y+H;
	R=p[n];
	double ans=0;
	for(int i=n-1;i>=1;--i){
		if(getk(Q,R)>=getk(Q,p[i])){
			line L1(Q,R),L2(p[i+1],p[i]);
			auto temp=(L1&L2);
			ans+=dis(temp.second,p[i]);
			R=p[i];
		}
	}
	cout<<fixed<<setprecision(10)<<ans;
}