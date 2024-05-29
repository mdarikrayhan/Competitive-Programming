#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=1e6+5;
using T=long double;
const T inf=1e18,eps=1e-14;
int n,m,k,h,q,C[N];
T ls[M],cs;
vector<T> p[N];
vector<int> c[N],in[M];
inline T divd(T u,T v){
	return v>eps?1.0*u/v:(u>eps?inf:0);
}
pair<T,int> zc[15];
struct line{
	int u;
	T o,l,r,a,b;
	inline bool operator <(const line &tp)const{
		return r<tp.r;
	}
}a[M],b[M];
inline int get(T w){return lower_bound(ls+1,ls+h+1,w)-ls;}
int main(){
	cin>>n>>q;
	for(int i=1,u;i<=n;i++){
		scanf("%d",&u);
		c[i].resize(u);p[i].resize(u);
		for(int j=0;j<u;j++) scanf("%d",&c[i][j]),C[i]+=c[i][j];
		T sn=0,sm,x;cs+=C[i];
		for(int j=0;j<u;j++) scanf("%Lf",&p[i][j]),sn+=p[i][j];
		for(int j=0;j<u;j++){
			p[i][j]/=sn;
			zc[j]=make_pair(divd(c[i][j],p[i][j]),j);
		}
		sort(zc,zc+u);sm=C[i];sn=1;
		a[++m]=(line){i,(T)C[i],-inf,0};
		for(int j=0,v;j<u;j++){
			x=zc[j].first;
			v=zc[j].second;
			if(x>C[i]){
				T tp=a[m].r=-sm/a[m].o/a[m].o;
				a[m].a=sm;a[m].b=sn;
				a[++m]=(line){i,0,tp,-sm/x/x,sm,sn};
				a[++m]=(line){i,x,-sm/x/x};
			}
			sm-=c[i][v];sn-=p[i][v];
		}
		a[m].r=-eps;a[m].a=sm;a[m].b=sn;
	}
	for(int i=1;i<=m;i++) ls[++h]=a[i].l,ls[++h]=a[i].r;
	sort(ls+1,ls+h+1);h=unique(ls+1,ls+h+1)-ls-1;
	for(int i=1;i<=m;i++){
		in[get(a[i].l)].push_back(+i);
		in[get(a[i].r)].push_back(-i);
	}
	T sx=0,sa=0,sb=0,lx,rx;
	for(int i=1;i<h;i++){
		for(int u:in[i]){
			if(u<0){
				u=-u;
				if(a[u].o<eps) sa-=sqrt(a[u].a),sb-=a[u].b;
				else{
					sx-=a[u].o;
					sb-=a[u].b-a[u].a/a[u].o;
				}
			}
			else{
				if(a[u].o<eps) sa+=sqrt(a[u].a),sb+=a[u].b; 
				else{
					sx+=a[u].o;
					sb+=a[u].b-a[u].a/a[u].o;
				}
			}
		}
		lx=rx=sx;
		if(sa>eps) lx+=sa*sqrt(-1/ls[i]),rx+=sa*sqrt(-1/ls[i+1]);
		b[++k]=(line){0,sx,lx,rx,sa,sb};
	}
	for(int i=k-1;i;i--) b[i].r=min(b[i].r,b[i+1].r); 
	line tp;
	for(int i=1,u;i<=q;i++){
		scanf("%Lf",&tp.r);tp.r+=cs;
		u=lower_bound(b+1,b+k+1,tp)-b;
		if(u>k){puts("0");continue;}
		tp.r=max(eps,tp.r-b[u].o);
		printf("%.12Lf\n",2*(b[u].a*b[u].a/tp.r-b[u].b));
	}
}