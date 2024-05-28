#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ld eps = 1e-12;

struct point {
	ld x,y;
	point(){}
	point(ld _x,ld _y): x(_x),y(_y){}
	point operator + (const point &a) const {
		return point(x+a.x,y+a.y);
	}
	point operator - (const point &a) const {
		return point(x-a.x,y-a.y);
	}
	point operator * (const ld &a) const {
		return point(x*a,y*a);
	}
	point operator / (const ld &a) const {
		return point(x/a,y/a);
	}
	bool operator < (const point &a) const {
		return fabs(x-a.x)<eps?y<a.y:x<a.x;
	}
	bool operator == (const point &a) const {
		return fabs(x-a.x)<eps && fabs(y-a.y)<eps;
	}
	ld len() const {
		return sqrt(x*x+y*y);
	}
	point rot() const {
		return point(-y,x);
	}
};

struct circle {
	point o;
	ld r;
	circle(){}
	circle(point _o,ld _r): o(_o),r(_r){}
	friend vector<point> operator & (const circle &a,const circle &b){
		ld d=(a.o-b.o).len();
		if (d>a.r+b.r+eps || d<fabs(a.r-b.r)-eps){ // no inter
			return vector<point>();
		}
		ld dt=(a.r*a.r-b.r*b.r)/d;
		ld d1=(d+dt)/2;
		point dr=(b.o-a.o)/d,p=a.o+dr*d1;
		dt=sqrt(max((ld)0.,a.r*a.r-d1*d1)),dr=dr.rot();
		return vector<point>{p+dr*dt,p-dr*dt};
	}
} a[5];

int n,fa[5];

int ff(int x){
	return fa[x]==x?x:fa[x]=ff(fa[x]);
}

void merge(int x,int y){
	x=ff(x);
	y=ff(y);
	if (x!=y){
		fa[x]=y;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for (int i=1; i<=n; i++){
		fa[i]=i;
		cin>>a[i].o.x>>a[i].o.y>>a[i].r; 
	}
	vector<point> al;
	int v=0,e=0,c=0;
	for (int i=1; i<=n; i++){
		vector<point> pt;
		for (int j=1; j<=n; j++){
			if (i==j){
				continue;
			}
			vector<point> tmp=a[i]&a[j];
			if (!tmp.empty()){
				merge(i,j);
			}
			for (int k=0; k<tmp.size(); k++){
				al.push_back(tmp[k]);
				pt.push_back(tmp[k]);
			}
		}
		sort(pt.begin(),pt.end());
		e+=unique(pt.begin(),pt.end())-pt.begin();
	}
	sort(al.begin(),al.end());
	v+=unique(al.begin(),al.end())-al.begin();
	for (int i=1; i<=n; i++){
		if (ff(i)==i){
			c++;
		}
	}
	cout<<e-v+c+1<<"\n";
	return 0;
}
