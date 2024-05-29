#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
const double eps=1e-7;
int k,n,q,Sx,Sy,x[N],y[N],a[N],px[N],py[N],t[N]; 
pii v[11]; ll ans[N],c[N];
vector<int> vec;
struct node {
	double a; int x,y,id;
	bool operator < (node x) const { return fabs(a-x.a)<eps?id<x.id:a<x.a; }
} w[N<<1];
bool cmp(pii a,pii b) { return (!b.fi?(a.fi || a.se<b.se):(a.se*b.fi<b.se*a.fi)); }
void update(int x,int val) { for (; x<N; x+=x&-x) c[x]+=val; }
ll query(int x) { ll s=0; for (; x; x-=x&-x) s+=c[x]; return s; }
int B(int x) { return upper_bound(all(vec),x)-vec.begin(); }
void Init(int i,int op) {
	double k=1.0*v[i].se/v[i].fi;
	for (int j=1; j<=n; j++) w[j]=(node){y[j]-k*x[j],x[j],a[j],0};
	for (int j=1; j<=q; j++) {
		if (op==1) w[n+j]=(node){py[j]-k*px[j],px[j],px[j]+v[i].fi*t[j],-j};
		else w[n+j]=(node){py[j]-k*px[j],px[j]-v[i].fi*t[j],px[j],j};
		px[j]+=v[i].fi*t[j]*op,py[j]+=v[i].se*t[j]*op; 
	}
	sort(w+1,w+n+q+1); memset(c,0,sizeof(c));
}
int main() {
	scanf("%d%d%d",&k,&n,&q);
	for (int i=1; i<=k; i++) {
		scanf("%d%d",&v[i].fi,&v[i].se);
		if (v[i].fi<0) v[i].fi*=-1,v[i].se*=-1;
		else if (!v[i].fi && v[i].se<0) v[i].se*=-1;
		Sx+=v[i].fi,Sy+=v[i].se;
	}
	sort(v+1,v+k+1,cmp);
	for (int i=1; i<=n; i++) scanf("%d%d%d",&x[i],&y[i],&a[i]),vec.push_back(x[i]);
	sort(all(vec)),vec.erase(unique(all(vec)),vec.end());
	for (int i=1; i<=q; i++) {
		scanf("%d%d%d",&px[i],&py[i],&t[i]);
		px[i]-=Sx*t[i],py[i]-=Sy*t[i],t[i]<<=1;
	}
	for (int i=1; i<=k; i++) {
		if (!v[i].fi) { 
			for (int j=1; j<=q; j++) py[j]+=v[i].se*t[j];
			continue;
		}
		Init(i,1);
		for (int j=1; j<=n+q; j++)
			if (w[j].id) ans[-w[j].id]-=query(B(w[j].y))-query(B(w[j].x-(i<2)));
			else update(B(w[j].x),w[j].y);
	}
	for (int i=1; i<=k; i++) {
		if (!v[i].fi) break;
		Init(i,-1);
		for (int j=1; j<=n+q; j++)
			if (w[j].id) ans[w[j].id]+=query(B(w[j].y-(i>1)))-query(B(w[j].x-1));
			else update(B(w[j].x),w[j].y);
	}
	for (int i=1; i<=q; i++) printf("%lld\n",ans[i]);
	return 0;
}