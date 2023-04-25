#include<bits/stdc++.h> 
#define rep(i,p,q) for (int i=(p);i<=(q);i++)
#define pre(i,p,q) for (int i=(p);i>=(q);i--)
#define ll long long
#define pb push_back 
using namespace std;
const int N=1e6+5; map<ll,ll>mp;
ll n,m,M,X,Y,S=1,T=1,sum,cnt,k,a[N],v[N]; vector<ll>p[105],q[105],f[105];
ll check(ll x) {
	ll l,r,mid,t=T; k=sum=0;
	rep(i,0,m) {
		if (i&&!v[i]) t/=a[i];
		if (t==T||!q[i].size()) continue;
		for (l=0,r=q[i].size()-1;l<=r;) {
			mid=l+r>>1;
			if (q[i][mid]*(T-t)>=x) l=mid+1;
			else r=mid-1;
		}
		k+=l;
		if (l>0) sum+=f[i][l-1]*(T-t);
	}
}
void calc(ll x) {
	ll l=0,r=1e18,mid,s=T,t=T;
	x/=X;
	rep(i,0,m) {
		if (i&&!v[i]) t/=a[i];
		if (f[i].size()) s+=t*f[i].back();
	}
	for (;l<=r;) {
		mid=l+r>>1;
		check(mid);
		if (k<=x) r=mid-1;
		else l=mid+1;
	}
	check(r);
	s+=sum-max(k-x,0ll)*r;
	S=max(S,s);
}
void dfs(ll x,ll y) {
	if (y*Y>M) return;
	if (x==cnt+1) return calc(M-y*Y);
	dfs(x+1,y);
	for (auto i:p[x]) y++,v[i]=1,dfs(x+1,y);
	for (auto i:p[x]) v[i]=0;
}
int main() {
	char st[N]; ll x;
	scanf("%lld%lld%lld%lld",&n,&M,&X,&Y);
	rep(i,1,n) {
		scanf("%s%lld",st+1,&x);
		if (st[1]=='*') {
			if (x>1) {
				S*=x,T*=(a[++m]=x);
				if (!mp[x]) mp[x]=++cnt;
				p[mp[x]].pb(m);
			}
		}
		else S+=x,q[m].pb(x);
	}
	rep(i,0,m) {
		sort(q[i].begin(),q[i].end(),greater<int>());
		for (int j=0;j<q[i].size();j++) {
			f[i].pb(q[i][j]);
			if (j) f[i][j]+=f[i][j-1];
		}
	}
	dfs(1,0);
	printf("%lld",S);
}