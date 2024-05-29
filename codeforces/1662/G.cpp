#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define i64 long long
#define ull unsigned long long
#define ldb long double
#define db double
#define i128 __int128
#define up(a,b,c) for(int a=(b);a<=(c);a++)
#define dn(a,b,c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define pivi pair<int,vector<i16> >
#define lc k<<1
#define rc k<<1|1
#define fi first
#define se second
#define endl '\n'
#define i16 short
#define eps 1e-8
 
const int N=1e6+100,M=2e6+100;
const int mod=998244353;
const int inf=1e9+7;
const ull uinf=1e18+14;
 
namespace IO{
    inline int read(){
        char c=getchar();int x=0,fh=0;
        while(c<'0'||c>'9'){fh|=c=='-';c=getchar();}
        while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
        return fh?-x:x;
    }
    inline void wt(int x){
        if(x<0){x=-x;putchar('-');}
        if(x>9)wt(x/10);
        putchar((x%10)^48);
    }
    inline void write(int x,bool op){
        wt(x);
        putchar(op?'\n':' ');
    }
}using namespace IO;
int n;
vector<int>g[N];
int sz[N],fs[N];
inline void dfs1(int u,int from){
    sz[u]=1;
    for(auto v:g[u]){
        //if(v==from)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        fs[u]+=fs[v]+sz[v];
    }
}
int gs[N];
inline void dfs2(int u,int from){
    for(auto v:g[u]){
        gs[v]=gs[u]+n-sz[u]+fs[u]-fs[v]-sz[v];
        dfs2(v,u);
    }
}
int tot;
int a[N];
inline int work(){
    sort(a+1,a+tot+1);
	if(a[tot]>=(n-1)/2)return a[tot];
	bitset<N>b;
    b[0]=1;
    int cur=0;
	up(i,1,tot){
        cur++;
		if(i==tot||a[i]!=a[i+1]){
			for(int x=1;cur>0;cur-=x,x=min(x<<1,cur))b=b|b<<(x*a[i]);
		}
	}
	for(int i=(n-1)/2;i>=0;i--)if(b[i])return i;
    return 0;
}
signed main(){
    n=read();
    int x;
    up(i,2,n){
        x=read();
        g[x].push_back(i);
    }
    dfs1(1,0);
    dfs2(1,0);
    int res=0;
    up(i,1,n){
        int sum=0;
        tot=0;
		for(auto v:g[i])sum+=fs[v]+sz[v],a[++tot]=sz[v];
		if(i>1)sum+=gs[i]+n-sz[i],a[++tot]=n-sz[i];
		int t=work();
		sum+=t*(n-1-t);
		res=max(res,sum);
    }
    cout<<res+n;
    return 0;
}