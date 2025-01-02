// LUOGU_RID: 159807198
#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I ll
#define her1 20081214
#define IV void
// #define cht 998244353
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(register ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
using i64 = long long;
#include "unordered_map"
#include "unordered_set"
#define My_assert(expr,tips) ((expr)?(void(0)):(puts(tips),exit(0)))
i64 n,phi,mo,b,p;vector<i64>ans;
IV push(i64 x){
	ans.push_back(x);
	if(ans.size()==n){
		for(i64 x:ans)printf("%lld ",x);puts("");
		exit(0);
	}
}
i64 mul(i64 a,i64 b,const i64&mo){return __int128(a)*b%mo;}
i64 qpow(i64 a,i64 b,const i64&mo){
	i64 ans=1;
	while(b){
		if(b&1)ans=mul(ans,a,mo);
		a=mul(a,a,mo);b>>=1;
	}
	return ans;
}
namespace NT{
	bool MR(i64 x){
		static i64 pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
		for(i64 u:pr){if(x==u)return 1;if(x%u==0)return 0;}
		F(i,0,9){i64 v=rnd()%x;if(v&&qpow(v,x-1,x)!=1)return 0;}return 1;
	}
	i64 findd(i64 n){
		if(n<10){F(i,2,n-1)if(n%i==0)return i;return -114514;}
		i64 a=rnd()%n,x=rnd()%n,y=x;auto G=[&](const i64&x){return(mul(x,x,n)+a)%n;};
		while(1){
			x=G(x);y=G(G(y));if(x==y)break;
			i64 g=__gcd(n,abs(x-y));if(1<g&&g<n)return g;
		}
		return findd(n);
	}
	vector<i64>fac;
	IV init_factor(i64 x){
		unordered_map<i64,i64>mp;queue<i64>q;
		for(q.push(x);!q.empty();){
			i64 x=q.front();q.pop();if(MR(x)){++mp[x];continue;}
			i64 t=findd(x);q.push(t);q.push(x/t);
		}
		vector<pair<i64,i64>>tmp;for(auto u:mp)tmp.push_back(u);fac.clear();
		function<void(i64,i64)>dfs=[&](i64 d,i64 pi){
			if(d==tmp.size())return fac.push_back(pi);
			for(int i=0;;){dfs(d+1,pi);if(++i>tmp[d].second)break;pi*=tmp[d].first;}
		};
		dfs(0,1);sort(fac.begin(),fac.end());
	}
	i64 getord(i64 u){
		for(i64 v:fac)if(qpow(u,v,mo)==1)return v;
		return -114514;
	}
	i64 getrt(){
		i64 x=1;
		for(;getord(x)!=fac.back();++x);
		return x;
	}
}
namespace BF{
	unordered_set<i64>S={1};
	IV main(){
		if(b%p==0)for(i64 t=1;S.insert(t),t;t=mul(t,b,mo));
		else for(i64 t=1;t=mul(t,b,mo),t!=1;S.insert(t));
		FL(i,1,mo-1)if(!S.count(i)&&__gcd(i,mo)==1)S.insert(i),push(i);
	}
}
namespace ODD{
	IV main(){
		i64 g=NT::getrt(),k=phi/NT::getord(b),mi=1;if(k==1)return;
		for(i64 i=0;!i||mi!=1;mi=mul(mi,g,mo),++i)if(i%k)push(mi);
	}
}
namespace TWO{
	IV main(){
		i64 k=phi/2/NT::getord(b%4==1?b:mo-b),mi=1;
		for(i64 i=0;!i||mi!=1;mi=mul(mi,5,mo),++i)
			if(b%4==1){if(i%k)push(mi);push(mo-mi);}
			else{
				if(i%k||(i/k)%2==1)push(mi);
				if(i%k||(i/k)%2==0)push(mo-mi);
			}
	}
}

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();mo=read();b=read();
	NT::init_factor(mo);p=NT::fac[1];phi=mo/p*(p-1);
	if(b%p==0||mo<10||b==1)BF::main();
	else if(NT::init_factor(mo/p*(p-1)),p&1)ODD::main();
	else TWO::main();return puts("-1"),0;
}