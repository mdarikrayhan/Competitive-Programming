// LUOGU_RID: 159807239
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
//#define ull unsigned int
//#define lll __int128
//#define double long double
using namespace std;
const long long INF=1e9+5;
//const long long mod=998244353,orm=3;
const long long mod=1000000007;
const int MAXN=100005;
const double eps=1e-6;
vector<int> lp,lnow,v[MAXN];
vector<pair<int,int> > mp1[MAXN],mp2[MAXN];
int T,n,tot=0;
int vst[MAXN],prt[MAXN];
int mp[1005][1005];
struct o {
	int x,y,z;
}e[MAXN];
void clear() {
	lp.clear(),lnow.clear();
	for(int i=0;i<=tot;i++) v[i].clear(),mp[e[i].x][e[i].y]=0,vst[i]=prt[i]=0,mp1[i].clear(),mp2[i].clear();
	tot=0;
}
void add(int x,int y) {
	v[x].push_back(y);v[y].push_back(x);
}
void dfs(int s,int fa) {
	vst[s]=1;prt[s]=fa;
	for(int y:v[s]) {
		if(y==fa) continue;
		if(vst[y]) {
			if(lp.size()) return ;
			int x=s;
			while(x!=y) lp.push_back(x),x=prt[x];
			lp.push_back(y);
			return ;
		}
		dfs(y,s);if(lp.size()) return ;
	}
	vst[s]=2;
}
void ins(int x,int y) {
	if(!mp[x][y]) {
		int z=0;
		cout<<"? "<<x<<" "<<y<<"\n";fflush(stdout);
		cin>>z;
		mp[x][y]=++tot;
		e[tot]={x,y,z};
	}
}
vector<int> change(vector<int> l) {
	vector<int> lpp;
	for(int i=1;i+1<l.size();i++) {
		int x=l[i-1],y=l[i],z=l[i+1];
		if(e[x].x==e[y].x&&e[y].x==e[z].x) continue;
		if(e[x].y==e[y].y&&e[y].y==e[z].y) continue;
		lpp.push_back(y);
	}
	lpp.push_back(l.back());lpp.push_back(l[0]);
	l=lpp;lpp.clear();
	for(int i=1;i+1<l.size();i++) {
		int x=l[i-1],y=l[i],z=l[i+1];
		if(e[x].x==e[y].x&&e[y].x==e[z].x) continue;
		if(e[x].y==e[y].y&&e[y].y==e[z].y) continue;
		lpp.push_back(y);
	}
	lpp.push_back(l.back());lpp.push_back(l[0]);
	l=lpp;lpp.clear();
	return l;
}
void calc(vector<int> x) {
	int len=x.size();
	if(len==4) {
		vector<int> v1,v2;
		for(int i:x) v1.push_back(e[i].x),v2.push_back(e[i].y);
		sort(v1.begin(),v1.end());v1.erase(unique(v1.begin(),v1.end()),v1.end());
		sort(v2.begin(),v2.end());v2.erase(unique(v2.begin(),v2.end()),v2.end());
		if(v1.size()!=2||v2.size()!=2) assert(0);
		cout<<"! "<<v1[0]<<" "<<v1[1]<<" "<<v2[0]<<" "<<v2[1]<<"\n";fflush(stdout);
		string s;cin>>s;fflush(stdout);
		return ;
	}
	int len2=len/2+((len/2)%2==0),a=x[0],b=x[len2-1],xx,yy;
	vector<int> y;
	for(int i=0;i<len2;i++) y.push_back(x[i]);
	xx=e[a].x,yy=e[b].y;int fg=0,fg2=0;
	for(int i:y) {
		if(e[i].x==xx) fg++;
		if(e[i].y==yy) fg2++;
	}
	if(fg>=2||fg2>=2) {
		xx=e[b].x,yy=e[a].y;
		fg=0,fg2=0;
		for(int i:y) {
			if(e[i].x==xx) fg++;
			if(e[i].y==yy) fg2++;
		}
		if(fg>=2||fg2>=2) assert(0);
	}
	ins(xx,yy);
	if(y.size()%2==0) y.pop_back();
	fg=0;
	for(int i:y) {
		if(e[i].z==e[mp[xx][yy]].z) fg=1;
	}
	if(!fg) {
		y.push_back(mp[xx][yy]);
		return calc(y),void();
	}
	y.clear();
	for(int i=len2;i<len;i++) y.push_back(x[i]);
	fg=0;
	for(int i:y) {
		if(e[i].z==e[mp[xx][yy]].z) fg=1;
	}
	if(fg) assert(0);
	y.push_back(mp[xx][yy]);
	y=change(y);
	calc(y);
}
void solve() {
	cin>>n;
	for(int i=1;i<=n*2;i++) {
		int x,y;cin>>x>>y;
		tot++;
		e[i]={x,y,i};mp[x][y]=i;
		mp1[x].push_back({y,i}),mp2[y].push_back({x,i});
	}
	for(int i=1;i<=n;i++) {
		sort(mp1[i].begin(),mp1[i].end());
		for(int j=1;j<mp1[i].size();j++) {
			int x=mp1[i][j-1].second,y=mp1[i][j].second;
			add(x,y);
		}
		sort(mp2[i].begin(),mp2[i].end());
		for(int j=1;j<mp2[i].size();j++) {
			int x=mp2[i][j-1].second,y=mp2[i][j].second;
			add(x,y);
		}
	}
	for(int i=1;i<=n*2;i++) if(!vst[i]) dfs(i,0);
	lp=change(lp);
	calc(lp);
}
signed main() {
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		solve();clear();
	}
	return 0;
}