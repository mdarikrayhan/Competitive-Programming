// LUOGU_RID: 160596908
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pr;
inline LL rd(){
	LL x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const LL N=200005;
LL n,m,de[N],f[N],sz[N],sn[N],tp[N],dfn[N],id[N],po[N],cn;vector<LL>ve;
LL ln[N<<2],le[N<<2],tg[N<<2],s1[N<<2],s2[N<<2];vector<pr>vc[N];
void dfs(LL x,LL fa){
	f[x]=fa;de[x]=de[fa]+1;sz[x]=1;
	for(auto y:vc[x])if(y.F!=fa){
		dfs(y.F,x);sz[x]+=sz[y.F];id[y.F]=y.S;
		if(sz[y.F]>sz[sn[x]])sn[x]=y.F;
	}
}
void df(LL x,LL to){
	tp[x]=to;dfn[x]=++cn;po[cn]=x;
	if(sn[x])df(sn[x],to);
	for(auto y:vc[x])if(y.F!=f[x]&&y.F!=sn[x])df(y.F,y.F);
}
void pu(LL rt){le[rt]=le[rt<<1]+le[rt<<1|1];s2[rt]=s2[rt<<1]+s2[rt<<1|1];}
void rev(LL rt){tg[rt]^=1;le[rt]=ln[rt]-le[rt];s2[rt]=s1[rt]-s2[rt];}
void pd(LL rt){if(tg[rt])rev(rt<<1),rev(rt<<1|1),tg[rt]=0;}
void bd(LL rt,LL l,LL r){
	ln[rt]=r-l+1;if(l==r){s1[rt]=id[po[l]];return;}
	LL md=l+r>>1;bd(rt<<1,l,md);bd(rt<<1|1,md+1,r);s1[rt]=s1[rt<<1]+s1[rt<<1|1];
}
void upd(LL rt,LL l,LL r,LL x,LL y){
	if(x<=l&&r<=y){rev(rt);return;}LL md=l+r>>1;pd(rt);
	if(x<=md)upd(rt<<1,l,md,x,y);if(y>md)upd(rt<<1|1,md+1,r,x,y);pu(rt);
}
void wt(LL rt,LL l,LL r){
	if(l==r){if(le[rt])ve.push_back(id[po[l]]);return;}LL md=l+r>>1;pd(rt);
	wt(rt<<1,l,md);wt(rt<<1|1,md+1,r);
}
int main(){
	ios::sync_with_stdio(false);cin>>n;
	for(LL i=1,x,y;i<n;++i)cin>>x>>y,vc[x].push_back({y,i}),vc[y].push_back({x,i});
	dfs(1,0);df(1,1);bd(1,1,n);upd(1,1,n,1,1);
	for(LL op,x,z=1;;){
		cin>>op;
		if(op==1){
			for(++z,cin>>x;x;x=f[tp[x]])upd(1,1,n,dfn[tp[x]],dfn[x]);
			cout<<(z==le[1]*2?s2[1]:0)<<endl;
			fflush(stdout);
		}else if(op==2){
			if(z==le[1]*2){
				ve.clear();wt(1,1,n);sort(ve.begin(),ve.end());
				cout<<ve.size()<<" ";for(auto i:ve)cout<<i<<" ";cout<<endl;
			}else cout<<0<<endl;
			fflush(stdout);
		}else break;
	}
	return 0;
}