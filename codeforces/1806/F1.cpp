// LUOGU_RID: 160089160
// Problem: GCD Master (hard version)
// URL: https://www.luogu.com.cn/problem/CF1806F2
// Memory Limit: 1000 MB
// Time Limit: 3000 ms
// Author: Nityacke
// Time: 2024-05-23 17:08:07

#include<iostream>
#include<map>
#include<algorithm>
#define int long long
#define Int __int128
using namespace std;
const int N=1e6+5;
int T,n,m,k,a[N],p[N],g[N],cnt,id;
Int ans,sum,s[N],b[N];
map<int,int>mp;
namespace IO{
    static int len=0;
    static char ibuf[(1<<20)+5],*iS,*iT,out[(1<<20)+1];
    #define gc() (iS==iT?iT=(iS=ibuf)+fread(ibuf,1,1<<20,stdin),(iS==iT?EOF:*iS++):*iS++)
    inline int read(){
        int x=0,f=0;char c=gc();
        for(;c<'0'||c>'9';c=gc()) f|=c=='-';
        for(;c>='0'&&c<='9';c=gc()) x=x*10+(c^48);
        return f?-x:x;
    }
    inline void flush(){fwrite(out,1,len,stdout);len=0;}
    inline void pc(char ch){out[len++]=ch;if(len>=1000000) flush();}
    inline void write(Int x){
        static int st[35],top=0;
        if(x<0) pc('-'),x=-x;
        do{st[++top]=x%10,x/=10;}while(x);
        while(top) pc(st[top--]+'0');
        pc('\n');
    }
}using namespace IO;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline void solve(){
	n=read(),m=read(),k=read()+1,ans=cnt=sum=id=0,mp.clear();
	for(int i=1,x;i<=n;++i){
		x=read(),sum+=x;
		if(mp[x]++) b[++cnt]=x;
	}
	n=0;
	for(auto v:mp) a[++n]=v.first;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;++i) b[i]+=b[i-1];
	if(cnt>=k-1) ans=max(ans,sum-b[k-1]);
	for(int i=1;i<=n;++i){
		g[i]=gcd(g[i-1],a[i]),s[i]=s[i-1]+a[i];
		if(g[i]!=g[i-1]) p[++id]=i;
		if(cnt>=k-i&&k>=i) ans=max(ans,sum-s[i]+g[i]-b[k-i]);
	}
	p[++id]=n+1;
	for(int i=1;i<id;++i){
		Int mx=-sum;
		for(int j=p[i+1];j<=n;++j) mx=max(mx,(Int)gcd(g[p[i]],a[j])-a[j]);
		for(int j=p[i];j<min(p[i+1],k);++j)
			if(cnt>=k-j-1) ans=max(ans,sum+mx-s[j]-b[k-j-1]);
	}
	write(ans);
}
signed main(){
	T=read();
	while(T--) solve();
	flush();
}