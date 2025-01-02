#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int T,n,x1,x2,a[N],m,b[N],da[N];
pair<int,int> db[N];
bool vs[N];
vector<int> ans;
bitset<N> f,t;
map<int,vector<int> > mp;
void Calc(int x) {
	for (int i=0;i<=n;i++) vs[i]=0;
	for (int i=0;i<=x;i+=2) vs[i]^=1;
	ans.clear();
	ans.resize(x2);
	for (int i=0;i<x2;i++) ans[i]=i,x1-=i;
	int t=0;
	for (int i=x2-1;i>=0;i--) {
		int dt=min(x-t-i,x1);
		ans[i]+=dt;
		x1-=dt;
		if (!x1) break;
		t++;
	}
	for (int v:ans) vs[v]^=1;
	ans.clear();
	for (int i=0;i<=x;i++)
		if (vs[i]) ans.push_back(x+1-i);
		
	for (int i=x+2;i<=x+m-1;i++)
		if (da[i]<db[i-x+1].first)
			ans.push_back(i);
	printf("%d\n",ans.size());
	for (int v:ans) printf("%lld ",v);
	printf("\n");
}

signed main() {
	scanf("%lld",&T);
	while (T--) {
		mp.clear();
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		scanf("%lld",&m);
		for (int i=1;i<=m;i++) scanf("%lld",&b[i]);
		for (int i=3;i<=n;i++) da[i]=a[i]+a[i-1]*2+a[i-2];
		for (int i=3;i<=n;i++) mp[da[i]].push_back(i);
		for (int i=3;i<=m;i++) db[i]=make_pair(b[i]+b[i-1]*2+b[i-2],i);
		sort(db+3,db+m+1);
		f.set();
		for (int l=3,r=l;l<=m;l=r) {
			t.reset();
			for (int v:mp[db[l].first]) t[v]=1;
			for (int v:mp[db[l].first-1]) t[v]=1;
			while (r<=m && db[r].first==db[l].first) {
				if (db[r].second)
				f&=t>>(db[r].second-1),r++;
			}
		}
		for (int i=3;i<=m;i++) db[i]=make_pair(b[i]+b[i-1]*2+b[i-2],i);
		bool fl=0;
		for (int i=1;i<=n-m+1;i++) {
			if (!f[i]) continue;
			x1=a[i]-b[1],x2=a[i+1]-b[2]+a[i]-b[1];
			int ev=(i/2)*2;
			x1-=(ev+2)*(ev/2)/2,x2+=ev/2+1;
			if (x2<0 || x2>i+1) continue;
			int l=(x2-1)*x2/2,r=(i*2-x2+1)*x2/2;
			x1=-x1;
			if (l<=x1 && x1<=r) {
				Calc(i),fl=1;
				break;
			}
		}
		if (!fl) printf("-1\n");
	}
	return 0;
}