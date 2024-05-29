#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;
int T,n,Max[N],sum[N],dp[N];
vector <int> nex[N];
stack <char> st;
int read()
{
	char ch=getchar();
	int ret=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar();
	return ret;
}
void write(int Ans)
{
	if(!Ans)
		putchar('0');
	while(Ans)
		st.push(Ans%10^48),Ans/=10;
	while(!st.empty())
		putchar(st.top()),st.pop();
	putchar('\n');
}
void dfs(int x,int fa)
{
	Max[x]=x;
	for(int y:nex[x])
		if(y!=fa)
			dfs(y,x),Max[x]=max(Max[x],Max[y]);
	sort(nex[x].begin(),nex[x].end(),[&](int x,int y){return Max[x]<Max[y];});
}
void add(int id,int val)
{
	for(int i=id;i<=n;i+=i&(-i))
		(sum[i]+=val*dp[id])%=mod;
}
int query(int id)
{
	int ret=0;
	for(int i=id;i;i-=i&(-i))
		(ret+=sum[i])%=mod;
	return ret;
}
void Dfs(int x,int fa,int MAX)
{
	if(MAX<x)
		(dp[x]+=(query(x)-query(MAX-1))%mod)%=mod;
	add(x,1);
	MAX=max(MAX,x);
	for(int y:nex[x])
		if(y!=fa)
			Dfs(y,x,MAX),add(Max[y],1);
	add(x,-1);
	for(int y:nex[x])
		if(y!=fa)
			add(Max[y],-1);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			nex[i].clear(),dp[i]=0;
		for(int i=1,x,y;i<=n-1;i++)
			x=read(),y=read(),nex[x].push_back(y),nex[y].push_back(x);
		dp[1]=1;
		dfs(1,0),Dfs(1,0,1);
		write((dp[n]+mod)%mod);	
	}
}