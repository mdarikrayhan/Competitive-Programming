// LUOGU_RID: 160014192
#include<bits/stdc++.h>
namespace IO{
const int L=(1<<20)+30;
char buf[L],*s,*t;
#define gf() (s==t&&(s=buf)==(t=buf+fread(buf,1,L,stdin))?-1:*s++)
void rd(int&x){
	x=0;char c=gf();
	while(c<48) c=gf();
	while(c>=48) x=x*10+(c^48),c=gf();
}
}
using IO::rd;
using namespace std;
template<typename Key,typename T,unsigned n,unsigned p>struct UNORDERED_MAP{
	unsigned hsh(unsigned long long x)const{
		static const unsigned long long t=
		std::chrono::steady_clock::now().time_since_epoch().count();
		x+=t+0x9e3779b97f4a7c15;
		x=(x^(x>>30))*0xbf58476d1ce4e5b9;
		x=(x^(x>>27))*0x94d049bb133111eb;
		return(x^(x>>31))%p;
	}
	struct Q{Key x;T y;unsigned z;}e[n+1];
	unsigned h[p],idx,sz;
	void clear(){
		for(unsigned i=1;i<=idx;++i) h[hsh(e[i].x)]=0,e[i]=e[i-1];
		idx=sz=0;
	}
	Q*find(const Key&x){
		auto z=hsh(x);
		for(auto i=h[z];i;i=e[i].z)
			if(e[i].x==x)
				return&e[i];
		return 0;
	}
	T&operator[](const Key&x){
		auto z=hsh(x);
		for(auto i=h[z];i;i=e[i].z)
			if(e[i].x==x)
				return e[i].y;
		++idx,++sz,e[idx].x=x,e[idx].z=h[z],h[z]=idx;
		return e[idx].y;
	}
};
#define eb emplace_back
const int N=100005;
int n,p,K,X,pw[N],ipw[N],v[N],s[2][N],sz[N],son[N],l[N],a[N],b[N],st[N],tp,L[N],R[N];// a out b in
vector<int>E[N];
bitset<N>vis;
long long ans;
UNORDERED_MAP<int,int,N,1000003>mp;
int fpw(int x,int k){
	int r=1;
	for(;k;k>>=1,x=x*1ll*x%p) if(k&1) r=r*1ll*x%p;
	return r;
}
void getrt(int x,int pr,int&rt,int n){
	sz[x]=1,son[x]=0;
	for(int y:E[x])
		if(!vis[y]&&y^pr)
			getrt(y,x,rt,n),sz[x]+=sz[y],son[x]=max(son[x],sz[y]);
	if((son[x]=max(son[x],n-sz[x]))<son[rt]) rt=x;
}
void calc(int x,int pr){
	a[x]=(a[pr]*1ll*K+v[x])%p,l[x]=l[pr]+1;
	st[++tp]=x,b[x]=(b[pr]+v[x]*1ll*pw[l[x]])%p;
	for(int y:E[x])
		if(!vis[y]&&y^pr)
			calc(y,x);
}
void solve(int x,int n){
	int y=0;getrt(x,x,y,n),vis[x=y]=1,l[x]=a[x]=0,b[x]=v[x],st[tp=1]=x;
	for(int y:E[x])
		if(!vis[y])
			L[y]=tp+1,calc(y,x),R[y]=tp;
	for(int i=1,x;i<=tp;++i) x=st[i],++mp[b[x]];
	UNORDERED_MAP<int,int,N,1000003>::Q*it;
	for(int i=1,x;i<=tp;++i)
		if(x=st[i],it=mp.find((X+p-a[x])*1ll*ipw[l[x]]%p),it)
			s[1][x]+=it->y;
	mp.clear();
	for(int y:E[x])
		if(!vis[y]){
			for(int i=L[y],x;i<=R[y];++i) x=st[i],++mp[b[x]];
			for(int i=L[y],x;i<=R[y];++i)
				if(x=st[i],it=mp.find((X+p-a[x])*1ll*ipw[l[x]]%p),it)
					s[1][x]-=it->y;
			mp.clear();
		}
	for(int i=1,x;i<=tp;++i) x=st[i],++mp[(X+p-a[x])*1ll*ipw[l[x]]%p];
	for(int i=1,x;i<=tp;++i)
		if(x=st[i],it=mp.find(b[x]),it)
			s[0][x]+=it->y;
	mp.clear();
	for(int y:E[x])
		if(!vis[y]){
			for(int i=L[y],x;i<=R[y];++i) x=st[i],++mp[(X+p-a[x])*1ll*ipw[l[x]]%p];
			for(int i=L[y],x;i<=R[y];++i)
				if(x=st[i],it=mp.find(b[x]),it)
					s[0][x]-=it->y;
			mp.clear();
		}
	for(int y:E[x])
		if(!vis[y])
			solve(y,sz[y]>sz[x]?n-sz[x]:sz[y]);
}
int main(){
	rd(n),rd(p),rd(K),rd(X),pw[0]=ipw[0]=1;
	for(int i=1;i<=n;++i) rd(v[i]);
	for(int i=1,_=fpw(K,p-2);i<=n;++i)
		pw[i]=pw[i-1]*1ll*K%p,ipw[i]=ipw[i-1]*1ll*_%p;
	for(int i=1,u,v;i<n;++i)
		rd(u),rd(v),E[u].eb(v),E[v].eb(u);
	son[0]=N,solve(1,n);
	for(int i=1;i<=n;++i)
		ans+=s[0][i]*1ll*s[0][i]+s[0][i]*1ll*s[1][i]+s[1][i]*1ll*s[1][i]-s[0][i]*3ll*n;
	return printf("%lld",n*1ll*n*n+ans),0;
}