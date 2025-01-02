// LUOGU_RID: 156298763
#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define isz(v) (int)(v.size())
using namespace std;

const int maxn=105;
const int maxm=5005;
const int inf=0x3f3f3f3f;
const double eps=1e-9;

namespace Solve {
	struct Edge {
		int x,y,v;
	} e[maxm];
	int n,m;
	double a[maxn][maxn];
	double d[maxn];
	void clear() {
		
	}
	void gauss() {
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(abs(a[j][i])>abs(a[i][i])) {
					for(int k=1;k<=n+1;k++) {
						swap(a[i][k],a[j][k]);
					}
				}
			}
			if(abs(a[i][i])<=eps) {
				continue;
			}
			for(int j=1;j<=n;j++) {
				if(i==j) {
					continue;
				}
				double v=a[j][i]/a[i][i];
				for(int k=1;k<=n+1;k++) {
					a[j][k]-=a[i][k]*v;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			d[i]=abs(a[i][i])>eps?a[i][n+1]/a[i][i]:0;
		}
	}
	void main(int tid) {
		cin>>n>>m;
		a[1][1]=1;
		a[n][n]=1,a[n][n+1]=1;
		for(int i=1;i<=m;i++) {
			cin>>e[i].x>>e[i].y>>e[i].v;
			if(e[i].x!=1&&e[i].x!=n) {
				a[e[i].x][e[i].y]++,a[e[i].x][e[i].x]--;
			}
			if(e[i].y!=1&&e[i].y!=n) {
				a[e[i].y][e[i].y]--,a[e[i].y][e[i].x]++;
			}
		}
		gauss();
		double v=inf;
		for(int i=1;i<=m;i++) {
			v=min(v,e[i].v/abs(d[e[i].y]-d[e[i].x]));
		}
		double sum=0;
		for(int i=1;i<=m;i++) {
			if(e[i].x==1) {
				sum+=(d[e[i].y]-d[e[i].x])*v;
			}
			if(e[i].y==1) {
				sum-=(d[e[i].y]-d[e[i].x])*v;
			}
		}
		cout<<fixed<<setprecision(10);
		cout<<sum<<"\n";
		for(int i=1;i<=m;i++) {
			cout<<(d[e[i].y]-d[e[i].x])*v<<"\n";
		}
	}
	void init() {
		
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	Solve::init();
	for(int t=1;t<=T;t++) {
		Solve::main(t);
		Solve::clear();
	}
#ifndef ONLINE_JUDGE
	cerr<<"Time: "<<(1.0*clock()/CLOCKS_PER_SEC)*1000<<"ms\n";
#endif
}
