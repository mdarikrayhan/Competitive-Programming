// LUOGU_RID: 158347156
#include<bits/stdc++.h>
using namespace std;
int prime[1000005];
int cnt=0;
int mnp[10000005];
bool vst[10000005];
int rep[10000005];
vector<pair<int,int> > o;
void decom(int x){
	while(x!=1){
		int v=mnp[x];
		if(o.empty() or o.back().first!=rep[v])o.push_back({rep[v],1});
		else o[o.size()-1].second++;
		x/=v;
	}
	return ;
}
vector<int> to[500005];
int dep[500005];
int dfn[500005];
int tim=0;
int hs[500005];
int sz[500005];
int top[500005];
int ff[500005];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;sz[x]=1;ff[x]=fa;
	for(auto v:to[x]){
		if(v==fa)continue;
		dfs1(v,x);
		sz[x]+=sz[v];
		if(sz[v]>sz[hs[x]])hs[x]=v;
	}
	return ;
}
void dfs2(int x,int fa,int tp){
	top[x]=tp;dfn[x]=++tim;
	if(hs[x])dfs2(hs[x],x,tp);
	for(auto v:to[x]){
		if(v==fa or v==hs[x])continue;
		dfs2(v,x,v);
	}
	return ;
}
vector<pair<int,int> > M[1000005];
struct nd{
	int x,y,lim,id;
	bool operator<(const nd&a)const{return lim<a.lim;}
};
vector<nd> Q[1000005];
const long long mod = 1000000007;
long long ans[100005];
int n;
struct sgt{
	int bit[500005];
	void M(int x,int v){
		for(int y=x;y<=n;y+=y&-y)bit[y]+=v;
		return ;
	}
	int Q(int x){
		int ret=0;
		for(int y=x;y;y-=y&-y)ret+=bit[y];
		return ret;
	}
	int Q(int l,int r){return Q(r)-Q(l-1);}
	int QQ(int x,int y){
		int ret=0;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			ret+=Q(dfn[top[x]],dfn[x]);
			x=ff[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		ret+=Q(dfn[x],dfn[y]);
		return ret;
	}
}p1,p2;
long long qpow(long long a,long long w){
	long long ans=1;
	while(w){
		if(w&1)ans=ans*a%mod;
		w>>=1;a=a*a%mod;
	}
	return ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);	
	for(int i=2;i<=10000000;i++){
		if(!vst[i])prime[++cnt]=i,rep[i]=cnt,mnp[i]=i;
		for(int j=1;j<=cnt and i*prime[j]<=10000000;j++){
			int v=i*prime[j];vst[v]=1;mnp[v]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,0,1);
	for(int i=1;i<=n;i++){
		int v;cin>>v;o.clear();decom(v);
		for(auto y:o)M[y.first].push_back({y.second,i});
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x,y,v;cin>>x>>y>>v;
		ans[i]=1;
		o.clear();decom(v);
		for(auto z:o){
			Q[z.first].push_back((nd){x,y,z.second,i});
		}
	}
	for(int i=1;i<=cnt;i++){
		sort(M[i].begin(),M[i].end());
		sort(Q[i].begin(),Q[i].end());
		int ptr=0;
		for(auto v:M[i])p2.M(dfn[v.second],1);
		for(auto v:Q[i]){
			while(ptr<M[i].size() and M[i][ptr].first<v.lim){
				p2.M(dfn[M[i][ptr].second],-1);
				p1.M(dfn[M[i][ptr].second],M[i][ptr].first);
				ptr++;
			}
			int res=p1.QQ(v.x,v.y)+v.lim*p2.QQ(v.x,v.y);
			ans[v.id]=ans[v.id]*qpow(prime[i],res)%mod;
		}
		for(int j=0;j<ptr;j++)p1.M(dfn[M[i][j].second],-M[i][j].first);
		for(int j=ptr;j<M[i].size();j++)p2.M(dfn[M[i][j].second],-1);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}