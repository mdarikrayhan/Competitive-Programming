#include<bits/stdc++.h>
#define pd push_back
#define all(A) A.begin(),A.end()
#define lb lower_bound
#define ve std::vector
typedef long long ll;
typedef long long ll;
typedef __int128 Int;
typedef unsigned long long ul;
typedef long double LD;
bool FileIfstream(std::string name){
	std::ifstream f(name.c_str());
	return f.good();
}
namespace Math{
	ll QP(ll x,ll y,ll mod){ll ans=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ans=ans*x%mod;return ans;}
	ll inv(ll x,ll mod){return QP(x,mod-2,mod);}
}
const int N=2e5+10;
const int mod=998244353;
const int inf=1e9;
struct node{
	int me,mo;
	ve<int>c1,c2;
	node(){me=mo=inf;}
};
void solve(){
	//don't forget to open long long
	int n,m;std::cin>>n>>m;
	ve<int>v1(n),v2(m);
	for(auto &p:v1)std::cin>>p;
	for(auto &p:v2)std::cin>>p;
	auto get=[&](ve<int>v,ve<int>opt)->ve<int>{
		ve<int>ans;v.erase(v.begin());
	//	for(auto &p:opt)std::cerr<<p<<' ';std::cerr<<'\n';
		for(auto &p:opt){
			int cid=0;
			while(v[cid]!=p)++cid;
			ans.pd(cid+1);ve<int>C;
			for(int i=cid+1;i<v.size();i++)C.pd(v[i]);C.pd(v[cid]);
			for(int i=0;i<cid;i++)C.pd(v[i]);
			v=C;
		}
		return ans;
	};
	auto getval=[&](ve<int>v)->node{
		node ans;int L=v.size();
		v.insert(v.begin(),0);
		for(int F=0;F<=L;F++){
			ve<int>res;
			ve<int>nxt(L+1);
			for(int i=0;i<=L;i++)
				nxt[i]=(i+F)%(L+1);
	//		std::cerr<<"! ";
	//		for(int i=0;i<=L;i++)
	//			std::cerr<<nxt[i]<<' ';std::cerr<<'\n';
			ve<bool>vis(L+1);
			for(int i=0;i<=L;i++)
				if(!vis[i]){
					ve<int>T;
					int pos=i;
					while(!vis[pos])T.pd(pos),vis[pos]=true,pos=nxt[v[pos]];
					if(!i){
						for(int j=int(T.size())-1;j>=1;j--)
							res.pd(v[T[j]]);
					}else{
						if(T.size()==1)continue;
						for(int j=int(T.size())-1;j>=0;j--)res.pd(v[T[j]]);
						res.pd(v[T.back()]);
					}
				}
			if((res.size()&1^1)&&res.size()<ans.me)
				ans.me=res.size(),ans.c1=res;
			if((res.size()&1)&&res.size()<ans.mo)
				ans.mo=res.size(),ans.c2=res;
		}
		if(ans.me<inf)ans.c1=get(v,ans.c1);
		if(ans.mo<inf)ans.c2=get(v,ans.c2);
		return ans;
	};
	node P1=getval(v1),P2=getval(v2);int ans=inf;
	ve<int>ansA,ansB;
	if(std::max(P1.me,P2.me)<ans)
		ans=std::max(P1.me,P2.me),ansA=P1.c1,ansB=P2.c1;
	if(std::max(P1.mo,P2.mo)<ans)
		ans=std::max(P1.mo,P2.mo),ansA=P1.c2,ansB=P2.c2;
	if(ans==inf)return std::cout<<"-1\n",void();
	while(ansA.size()^ansB.size()){
		if(ansA.size()<ansB.size())ansA.pd(1),ansA.pd(n);
		else ansB.pd(1),ansB.pd(m);
	}
	std::cout<<ans<<'\n';
	for(int i=0;i<ans;i++)
		std::cout<<ansA[i]<<' '<<ansB[i]<<'\n';
}
int main(){
#ifndef ONLINE_JUDGE
	if(!FileIfstream("IO.in")){
		freopen("IO.in","w",stdout);
		return 0;
	}
	freopen("IO.in","r",stdin);
	freopen("IO.out","w",stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T=1;
	//std::cin>>T;
	while(T--)solve();

#ifndef ONLINE_JUDGE
	std::cerr<<std::fixed<<std::setprecision(10)<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
#endif

	return 0;
}






