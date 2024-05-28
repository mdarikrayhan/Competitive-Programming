#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=2e5+5;
int n,m,x,y,w[N],f[N],nx[N],pos;
bool fl[N];
vector<int> ve[N],a;
inline int read(){
	int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline int dfs(int u){
	if(!w[u]||f[u])return f[u];
	if(u)for(int i=0;i<m;i+=u)if(i!=u&&dfs(i)>f[u])f[u]=f[i],nx[u]=i;
	return f[u]+=w[u];
}
int exgcd(int a,int b,int &x,int &y){if(b==0){x=1,y=0;return a;}int g=exgcd(b,a%b,x,y),t=x;x=y;y=t-(a/b)*y;return g;}
signed main(){
	n=read(),m=read();memset(nx,-1,sizeof(nx));
	for(int i=1;i<=n;i++)fl[read()]=true;
	for(int i=0;i<m;i++)if(!fl[i])w[x=i?__gcd(i,m):0]++,ve[x].pb(i);
	dfs(0);for(int i=1;i<m;i++)if(w[i]&&dfs(i)>f[pos])pos=i;
	for(;~pos;pos=nx[pos])for(int v:ve[pos])a.pb(v);
	for(int i=a.size()-1;i;i--)if(a[i]){
		int g=exgcd(a[i-1],m,x,y);y=m/g,a[i]=(x%y+y)%y*(a[i]/g)%m;
	}printf("%lld\n",(int)a.size());for(int v:a)printf("%lld ",v);
	puts("");
	return 0;
}