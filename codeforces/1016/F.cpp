// LUOGU_RID: 160545135
#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	template<typename T>
	void read(T &_x){_x=0;int _f=1;char ch=getchar();while(!isdigit(ch)) _f=(ch=='-'?-1:_f),ch=getchar();while(isdigit(ch)) _x=_x*10+(ch^48),ch=getchar();_x*=_f;}
	template<typename T,typename... Args>
	void read(T &_x,Args&...others){Read(_x);Read(others...);}
	const int BUF=20000000;char buf[BUF],top,stk[32];int plen;
	#define pc(x) buf[plen++]=x
	#define flush(); fwrite(buf,1,plen,stdout),plen=0;
	template<typename T>inline void print(T x){if(!x){pc(48);return;}if(x<0) x=-x,pc('-');for(;x;x/=10) stk[++top]=48+x%10;while(top) pc(stk[top--]);}
}
using namespace IO;
int n,m,cnt,x,y,z,head[300010],f[300010],dis[300010],v[300010],ma;
priority_queue<int>p,p1; 
struct w
{
	int to,nxt,z;
}a[600010];
inline void add(int x,int y,int z)
{
	a[++cnt].to = y;
	a[cnt].nxt = head[x];
	a[cnt].z = z;
	head[x] = cnt;
}
void dfs(int x,int fa)
{
	if(x == 1) v[x] = 1;
	for(int i = head[x];i;i = a[i].nxt)
		if(a[i].to != fa) dis[a[i].to] = dis[x]+a[i].z,dfs(a[i].to,x);
	for(int i = head[x];i;i = a[i].nxt)
		if(a[i].to != fa && v[a[i].to]) v[x] = 1;
}
void dfs1(int x,int fa,int z,int id)
{
	if(id == 0) p1.push(dis[x]);
	while(!p.empty() && !p1.empty() && p.top() == p1.top()) p.pop(),p1.pop();
	for(int j = 0;j <= 1;j++)
		if((id <= 1 && id == j) || id == 2)
			for(int i = head[x];i;i = a[i].nxt)
				if(a[i].to != fa && !v[a[i].to])
					dfs1(a[i].to,x,z+a[i].z,j);
	if(id == 2) p1.push(dis[x]);
	if(!v[x] && !p.empty()) 
	{
		if(v[fa])//边不能重复 
		{
			p1.push(dis[fa]);
			while(!p.empty() && !p1.empty() && p.top() == p1.top()) p.pop(),p1.pop();
			if(!p.empty()) f[x] = z + p.top();
			p.push(dis[fa]);
			while(!p.empty() && !p1.empty() && p.top() == p1.top()) p.pop(),p1.pop();//先删掉在加回去 
		}
		else f[x] = z + p.top();
	}
	if(v[x])
	{
		for(int i = head[x];i;i = a[i].nxt)
			if(a[i].to != fa && v[a[i].to])
			{
				p1.push(dis[a[i].to]);
				while(!p.empty() && !p1.empty() && p.top() == p1.top()) p.pop(),p1.pop();//不能和下一个点连边。 
				if(!p.empty()) f[x] = z + p.top();
				p.push(dis[a[i].to]);
				while(!p.empty() && !p1.empty() && p.top() == p1.top()) p.pop(),p1.pop();
				dfs1(a[i].to,x,z+a[i].z,2);
			}
	}
}
signed main()
{
	read(n),read(m);
	for(int i = 1;i < n;i++) read(x),read(y),read(z),add(x,y,z),add(y,x,z);
	dfs(n,0);
	for(int i = 1;i <= n;i++) p.push(dis[i]);
	dfs1(1,0,0,2);
	for(int i = 1;i <= n;i++) ma = max(ma,f[i]);
	sort(f + 1,f + 1 + n);
	for(int i = 1;i <= m;i++)
	{
		read(x);
		print(min(ma+x,dis[1])),pc('\n');
	}
	flush();
	return 0;
}