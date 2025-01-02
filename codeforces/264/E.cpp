// LUOGU_RID: 157044169
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+15;
int n,m,v[N],h[N],f[N];
set<pii>s1,s2;
multiset<int,greater<int>>g[N];
struct sgt{
	struct tree{int l,r,Mx;}t[N*4];
	#define lt p<<1
	#define rt p<<1|1
	inline void pushup(int p){t[p].Mx=max(t[lt].Mx,t[rt].Mx);}
	void build(int p,int l,int r){
		t[p]=(tree){l,r,0};
		if(l==r)return;
		int mid=(l+r)>>1;
		build(lt,l,mid),build(rt,mid+1,r);
	}
	void Change(int p,int x,int d){
		if(t[p].l==t[p].r)return t[p].Mx=d,void();
		int mid=(t[p].l+t[p].r)>>1;
		if(x<=mid)Change(lt,x,d);
		else Change(rt,x,d);
		pushup(p);
	}
	int ask(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r)return t[p].Mx;
		int mid=(t[p].l+t[p].r)>>1,Mx=0;
		if(l<=mid)Mx=max(Mx,ask(lt,l,r));
		if(r>mid)Mx=max(Mx,ask(rt,l,r));
		return Mx;
	}
}t1,t2;
inline void add(int x){t1.Change(1,x,v[x]),g[h[x]].insert(v[x]),t2.Change(1,h[x],*g[h[x]].begin());}
inline void del(int x){t1.Change(1,x,0),g[h[x]].erase(g[h[x]].find(v[x])),t2.Change(1,h[x],g[h[x]].size()?*g[h[x]].begin():0);}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	t1.build(1,1,n),t2.build(1,1,m+20);
	for(int i=1;i<=m;++i){
		int op,x,y;
		cin>>op>>x;
		if(op==1){
			int C=0;
			vector<pii>p;
			for(pii j:s2){
				if(C++==10)break;
				p.push_back(j);
			}
			for(pii j:p)del(j.se);
			cin>>y,y+=m-i+1,h[x]=y,v[x]=t1.ask(1,x+1,n)+1;
			p.push_back(pii(y,x));
			sort(p.begin(),p.end(),[&](const pii x,const pii y){return x.se<y.se;});
			for(int j=p.size()-1;j>=0;--j){
				for(int k=p.size()-1;k>j;--k){
					if(p[j].fi<p[k].fi)v[p[j].se]=max(v[p[j].se],v[p[k].se]+1);
				}
			}
			for(pii j:p)add(j.se);
			s1.insert(pii(x,h[x])),s2.insert(pii(h[x],x));
		}else{
			int C=0;
			vector<pii>p;
			for(pii j:s1){
				if(C++==10)break;
				if(C==x)y=j.fi;
				p.push_back(j);
			}
			for(pii j:p)del(j.fi);
			x=y;
			for(pii j:p)v[j.fi]=t2.ask(1,j.se+1,m+20)+1;
			for(int j=p.size()-1;j>=0;--j){
				for(int k=p.size()-1;k>j;--k){
					if(p[j].fi==x||p[k].fi==x)continue;
					if(p[j].se<p[k].se)v[p[j].fi]=max(v[p[j].fi],v[p[k].fi]+1);
				}
			}
			for(pii j:p)if(j.fi!=x)add(j.fi);
			s1.erase(pii(x,h[x])),s2.erase(pii(h[x],x));
		}
		cout<<max(t1.t[1].Mx,t2.t[1].Mx)<<"\n";
	}
	return 0;
}