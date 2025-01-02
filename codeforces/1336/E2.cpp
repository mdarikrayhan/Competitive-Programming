#include<bits/stdc++.h>
#define rg register
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)

using namespace std;

const long long mod=998244353;
inline long long ksm(long long a,long long b)
{
	long long re=1;
	while(b)
	{
		if(b&1)re=re*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return re;
}
inline void Adder(long long &x,long long y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void Reduce(long long &x,long long y)
{
	if((x-=y)<0)x+=mod;
}

const int maxn=2e5+10;

int n,m;
long long A[maxn];
namespace LB{
	long long W[64];
	inline void Insert(long long V)
	{
		for(rg int i=m-1;i>=0;i-=1)
			if((V>>i)&1)
			{
				if(!W[i])
				{
					W[i]=V;
					return;
				}
				V^=W[i];
			}
	}
	inline void Tran()
	{
		for(rg int i=m-1;i>=0;i-=1)
			for(rg int j=m-1;j>i;j-=1)
				if((W[j]>>i)&1)
					W[j]^=W[i];
		static long long G[64];
		for(rg int i=0;i<m;i+=1)G[i]=0;
		for(rg int i=0;i<m;i+=1)
			if(!W[i])
			{
				G[i]=1ll<<i;
				for(rg int j=i+1;j<m;j+=1)
					if((W[j]>>i)&1)
						G[i]|=1ll<<j;
			}
		for(rg int i=0;i<m;i+=1)W[i]=G[i];
	}
}
int cnt;long long Valid;
long long Count[64];
vector<long long>Can;
inline void dfs(int now,long long Xor)
{
	if(now==Can.size())
	{
		Adder(Count[__builtin_popcountll(Xor)],1);
		return;
	}
	dfs(now+1,Xor);
	dfs(now+1,Xor^Can[now]);
}
inline void process()
{
	for(rg int i=0;i<m;i+=1)if(LB::W[i])Can.emplace_back(LB::W[i]);
	dfs(0,0ll);
}
namespace Subtask1{
	long long Ans[64];
	inline void main()
	{
		process();
		for(rg int i=0;i<=m;i+=1)Ans[i]=Count[i]*Valid%mod;
		for(rg int i=0;i<=m;i+=1)printf("%lld ",Ans[i]);puts("");
	}
}
namespace Subtask2{
	long long Ans[64];
	long long C[64][64];
	vector<long long>Can;
	inline void main()
	{
		LB::Tran();process();
		C[0][0]=1;
		for(rg int i=1;i<=m;i+=1)
		{
			C[i][0]=1;
			for(rg int j=1;j<=i;j+=1)
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
		for(rg int i=0;i<=m;i+=1)
			for(rg int j=0;j<=i;j+=1)
				for(rg int k=0;k<=m-i;k+=1)
					if(j&1)Reduce(Ans[j+k],Count[i]*C[i][j]%mod*C[m-i][k]%mod);
					else Adder(Ans[j+k],Count[i]*C[i][j]%mod*C[m-i][k]%mod);
		Valid=Valid*ksm(ksm(2,mod-2),m-cnt)%mod;
		for(rg int i=0;i<=m;i+=1)Ans[i]=Ans[i]*Valid%mod;
		for(rg int i=0;i<=m;i+=1)printf("%lld ",Ans[i]);puts("");
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(rg int i=1;i<=n;i+=1)scanf("%lld",A+i),LB::Insert(A[i]);
	for(rg int i=0;i<m;i+=1)cnt+=LB::W[i]>0;
	Valid=ksm(2,n-cnt);
	if(cnt<=26)Subtask1::main();
	else Subtask2::main();
	return 0;
}//////////////
     	 					 		  						  			