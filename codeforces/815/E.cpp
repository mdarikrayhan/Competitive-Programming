// LUOGU_RID: 156972368
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	bool flag=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') flag=flag||(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=flag?-x:x;
}
template<typename T,typename ...Args>inline void read(T &x,Args &...args){
	read(x),read(args...);
}
template<typename T>inline void prt(T x){
	if(x>9) prt(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void put(T x){
	if(x<0) putchar('-'),x=-x;
	prt(x);
}
template<typename T>inline void put(char ch,T x){
	put(x),putchar(ch);
}
template<typename T,typename ...Args>inline void put(char ch,T x,Args ...args){
	put(ch,x),put(ch,args...);
}
#define N 65
#define ll long long
ll k,n;
vector<pair<ll,ll>> mem[N];
inline ll dfs(ll m,ll lim,int dep){
	if((m>>1)-1<lim) return 0;
	for(auto tmp:mem[dep])
		if(tmp.first==m) return tmp.second;
	ll res=1+dfs(m>>1,lim,dep+1)+dfs((m+1)>>1,lim,dep+1);
	mem[dep].emplace_back(m,res);
	return res;
}
inline ll calc(ll m,ll lim){
	for(int i=0;i<N;i++) mem[i].clear();
	return dfs(m,lim,0);
}
inline ll solve(ll l,ll r,ll val,ll num){
	ll mid=(l+r+1)>>1;
	if(!(--num)) return mid;
	ll L=calc(mid-l,val),R=calc(r-mid+1,val+1);
	if(L+R>=num) return solve(l,mid-1,val,num-R);
	else return solve(mid,r,val,num-L);
}
int main(){	
	read(n,k);
	if(k==1) return puts("1"),0;
	if(k==2) return put('\n',n),0;
	k-=2;
	ll l=1,r=n,res=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(calc(n-1,mid)>=k) res=mid,l=mid+1;
		else r=mid-1;
	}
	put('\n',solve(1,n-1,res,k));
	return 0;
}