#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN=1e6+5;
int n,m,a[MAXN],lst[MAXN]; 
ll ans[MAXN];
struct node{int l,r,id,op;}; 
vector<node> vec[MAXN];
inline int read(){
	int re=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') re=10*re+ch-'0',ch=getchar();
	return re;
}
struct sugt{
ll laz[MAXN<<2],sum[MAXN<<2],sumh[MAXN<<2],tag[MAXN<<2],lst[MAXN<<2]; 
// laz：add懒标记，sum: 和，sumh：直到 lst-1 的历史和，tag：懒标记*时间，lst：上次更新时间
void add(int L,int R,ll d,int t,int id=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		sumh[id]+=(t-lst[id])*sum[id];
		sum[id]+=(r-l+1)*d;
		laz[id]+=d;
		tag[id]+=d*t;
		lst[id]=t;
		return;
	}
	int mid=l+r>>1;
	if(L<=mid) add(L,R,d,t,id<<1,l,mid);
	if(mid<R) add(L,R,d,t,id<<1|1,mid+1,r);
	sumh[id]+=(t-lst[id])*sum[id];
	sum[id]=(sum[id<<1]+sum[id<<1|1]+laz[id]*(r-l+1));
	lst[id]=t;
}
ll ask_now(int L,int R,int id=1,int l=1,int r=n,ll lz=0){
	if(L<=l&&r<=R) return (sum[id]+lz*(r-l+1));
	lz+=laz[id];
	int mid=l+r>>1;ll ans=0;
	if(L<=mid) ans+=ask_now(L,R,id<<1,l,mid,lz);
	if(mid<R) ans+=ask_now(L,R,id<<1|1,mid+1,r,lz);
	return ans;
}
ll ask_his(int L,int R,int t,int id=1,int l=1,int r=n,ll lz=0,ll tg=0){
	if(L<=l&&r<=R) return (sumh[id]+(t-lst[id]+1)*sum[id]+((t+1)*lz-tg)*(r-l+1));
	int mid=l+r>>1;ll ans=0;
	lz+=laz[id];tg+=tag[id];
	if(L<=mid) ans+=ask_his(L,R,t,id<<1,l,mid,lz,tg);
	if(mid<R) ans+=ask_his(L,R,t,id<<1|1,mid+1,r,lz,tg);
	return ans;
}
}T;
int main(){
	set<int> s;s.insert(0);
	auto add=[&](int x,int t){
		int y=*s.rbegin();
		T.add(y+1,x,x,t);
		s.insert(x);
	};
	auto del=[&](int x,int t){
		int y=*s.upper_bound(x),z=*(--s.lower_bound(x));
		T.add(z+1,x,y-x,t);
		s.erase(x);
	};
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),x=read(),y=read();
		vec[x-1].push_back((node){l,r,i,-1});
		vec[y].push_back((node){l,r,i,1});
	}
	for(int i=1;i<=n;i++){
		add(i,i);
		if(lst[a[i]]) del(lst[a[i]],i);
		lst[a[i]]=i;
		for(auto j:vec[i]) ans[j.id]+=j.op*T.ask_his(j.l,j.r,i);
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
	   								  	   		  	  	 			