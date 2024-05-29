// LUOGU_RID: 150928723
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k)for(int i=j;i<=k;++i)
#define g(i,j,k)for(int i=j;i>=k;--i)
int n,m,s,l;
const int N=3e5,inf=1e18;
struct Kazemaru{
	int c[N];
	inline void add(int x,int y){for(;x<N;x+=-x&x)c[x]+=y;}
	inline int sum(int x,int y=0){for(;x;x-=-x&x)y+=c[x];return y;}
}T;
struct op{int t,a,b,i;}a[N];
vector<op>q[N];int b[N];set<int>c;
inline void add(int x,int y,int i){T.add(x,1);c.insert(x);q[x].push_back((op){0,y,0,i});}
inline int fd(int x,int y){return y?y<0?x-*prev(c.lower_bound(x)):*c.lower_bound(x)-x:inf;}
signed main(){
	cin>>n>>m;
	f(i,1,n)scanf("%lld %lld %lld",&a[i].t,&a[i].a,&a[i].b),a[i].i=i;
	sort(a+1,a+n+1,[&](op a,op b){return a.t>b.t;});a[0].t=inf;
	int t=0,p,x=1,y;
	for(s=n;s||T.sum(m);){
		for(;s&&a[s].t==t;--s)add(a[s].a,a[s].b,a[s].i);
		for(op e:q[x]){
			T.add(x,-1);c.erase(x);
			if(e.a)add(e.a,0,e.i);
			else b[e.i]=t;
		}q[x].clear();
		y=T.sum(m)?2*T.sum(x)>T.sum(m)?-1:1:0;
		p=min(a[s].t,t+fd(x,y));x+=(p-t)*y;t=p;
	}
	f(i,1,n)printf("%lld\n",b[i]);
	return 0;
}