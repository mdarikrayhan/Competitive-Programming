//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
void rout(__int128 x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
struct SAM{
	ll trs[N][26],par[N],mx[N],sz[N],lst,cnt;
	vector<ll> vt[N];
	void init()
	{
		lst=cnt=0;
		memset(trs,-1,sizeof(trs));
		memset(par,-1,sizeof(par));
		memset(mx,0,sizeof(mx));
		return;
	}
	void ins(char c)
	{
		ll j;
		mx[++cnt]=mx[lst]+1;
		sz[cnt]=1;
		ll p=lst,q,nq;
		while(p!=-1)
		{
			if(trs[p][c-'a']!=-1)
			{
				break;
			}
			trs[p][c-'a']=cnt;
			p=par[p];
		}
		lst=cnt;
		if(p==-1)
		{
			par[cnt]=0;
			return;
		}
		q=trs[p][c-'a'];
		if(mx[q]==mx[p]+1)
		{
			par[cnt]=q;
		}
		else
		{
			nq=cnt+1;
			for(j=0;j<26;j++)
			{
				trs[nq][j]=trs[q][j];
			}
			mx[nq]=mx[p]+1,par[nq]=par[q];
			par[q]=par[cnt]=nq;
			while(p!=-1)
			{
				if(trs[p][c-'a']!=q)
				{
					break;
				}
				trs[p][c-'a']=nq;
				p=par[p];
			}
			++cnt;
		}
		return;
	}
	void dfs(ll x)
	{
		ll i;
		for(i=0;i<vt[x].size();i++)
		{
			dfs(vt[x][i]);
			sz[x]+=sz[vt[x][i]];
		}
		return;
	}
	void build()
	{
		ll i;
		for(i=0;i<=cnt;i++)
		{
			if(par[i]!=-1)
			{
				vt[par[i]].push_back(i);
			}
		}
		dfs(0);
		return;
	}
}sam;
__int128 ans=0;
ll nxt[N],sum[N];
string s;
bool vis[N];
void solve(vector<ll> seq,ll len)
{
	ll i,j;
	for(i=0;i<seq.size();i++)
	{
		sum[i+1]=sum[i]+seq[i];
	}
	for(i=len-seq.size()+1,j=0;i<=len;i++)
	{
		while(j<seq.size()&&seq[j]<i)
		{
			j++;
		}
		if(j==seq.size())
		{
			break;
		}
		ans+=sum[i-(len-seq.size()+1)]*((ll)seq.size()-j);
	}
	return;
}
int main(){
	ll i,j;
	cin>>s;
	sam.init();
	for(i=0;i<s.size();i++)
	{
		sam.ins(s[i]);
	}
	sam.build();
	for(i=0;i<=sam.cnt;i++)
	{
		nxt[i]=-1;
		for(j=0;j<26;j++)
		{
			if(sam.trs[i][j]>=0&&sam.sz[sam.trs[i][j]]==sam.sz[i])
			{
				vis[sam.trs[i][j]]=true;
				nxt[i]=sam.trs[i][j];
			}
		}
	}
	for(i=0;i<=sam.cnt;i++)
	{
		if(vis[i])
		{
			continue;
		}
		ll lst=i;
		vector<ll> seq;
		for(j=i;j>=0;j=nxt[j])
		{
			lst=j;
			seq.push_back(sam.mx[j]-(sam.par[j]>=0?sam.mx[sam.par[j]]:sam.mx[j]));
		}
		solve(seq,sam.mx[lst]);
	}
	rout(ans),putchar('\n');
	return 0;
}