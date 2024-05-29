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
#define ll int
#define N 2000010
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
struct Node{
	ll x,y;
	Node(){x=y=0;}
	Node(ll _x,ll _y){x=_x,y=_y;}
	bool operator < (const Node &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	bool operator == (const Node &a)const{
		return x==a.x&&y==a.y;
	}
	bool operator != (const Node &a)const{
		return x!=a.x||y!=a.y;
	}
};
class HashPair {
    static inline size_t hash_combine(size_t h_first, size_t h_second) {
        return h_first ^ (h_second + 0x9e3779b9 + (h_first << 6) + (h_second >> 2));
    }

    static inline size_t hash_int(unsigned int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }

public:
    size_t operator() (const Node & p) const {
        size_t h_first  = hash_int(p.x);
        size_t h_second = hash_int(p.y);

        return hash_combine(h_first, h_second);
    }
};
ll n,dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1},cnt;
Node p[N];
bool vis[N],isans[N];
priority_queue<ll> pq;
unordered_map<Node,ll,HashPair> idx,mp;
void dfs0(Node x)
{
	ll i;
	mp[x]=0;
	for(i=0;i<8;i++)
	{
		Node y(x.x+dx[i],x.y+dy[i]);
		if(idx.find(y)!=idx.end()&&mp[y]==-1)
		{
			dfs0(y);
		}
	}
	return;
}
void dfs(Node x)
{
	ll i;
	mp[x]=cnt;
	for(i=1;i<8;i+=2)
	{
		Node y(x.x+dx[i],x.y+dy[i]);
		if(idx.find(y)!=idx.end()&&mp[y]==0)
		{
			if(cnt==1&&(!vis[idx[y]]))
			{
				vis[idx[y]]=true;
				pq.push(idx[y]);
			}
			continue;
		}
		if(mp.find(y)!=mp.end()&&mp[y]!=cnt&&mp[y]!=0)
		{
			dfs(y);
		}
	}
	return;
}
bool check(Node x)
{
	ll i,j;
	for(i=0;i<8;i++)
	{
		Node y(x.x+dx[i],x.y+dy[i]);
		if(idx.find(y)!=idx.end()&&mp[y]==0)
		{
			break;
		}
	}
	i%=8;
	ll cur=0,st=i;
	set<ll> hvs;
	while(true)
	{
		Node y(x.x+dx[i],x.y+dy[i]);
		if(idx.find(y)!=idx.end()&&mp[y]==0)
		{
			cur=1;
		}
		else if(cur)
		{
			Node z(x.x+dx[(i+1)&7],x.y+dy[(i+1)&7]);
			if((idx.find(z)==idx.end())||mp[z]!=0||(i&1))
			{
				if(hvs.find(mp[y])!=hvs.end())
				{
					return false;
				}
				hvs.insert(mp[y]);
				cur=0;
			}
		}
		i=(i+1)&7;
		if(i==st)
		{
			break;
		}
	}
	mp[x]=-1;
	dfs(x);
	for(i=0;i<8;i+=2)
	{
		Node y(x.x+dx[i],x.y+dy[i]);
		if(idx.find(y)!=idx.end()&&mp[y]==0&&(!vis[idx[y]]))
		{
			for(j=1;j<8;j+=2)
			{
				Node z(y.x+dx[j],y.y+dy[j]);
				if(mp[z]==1)
				{
					vis[idx[y]]=true;
					pq.push(idx[y]);
					break;
				}
			}
		}
	}
	return true;
}
int main(){
	ll i,j;
	n=rint(),i=rint();
	for(i=0;i<n;i++)
	{
		p[i].x=rint(),p[i].y=rint();
		idx[p[i]]=i;
		mp[p[i]]=-1;
		for(j=0;j<8;j++)
		{
			mp[Node(p[i].x+dx[j],p[i].y+dy[j])]=-1;
		}
	}
	dfs0(p[0]);
	for(i=0;i<n;i++)
	{
		if(mp[p[i]]==-1)
		{
			puts("NO");
			return 0;
		}
	}
	cnt=0;
	vector<Node> seq;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		seq.push_back(it->F);
	}
	sort(seq.begin(),seq.end());
	for(i=0;i<seq.size();i++)
	{
		if(mp[seq[i]]==-1)
		{
			cnt++;
			dfs(seq[i]);
		}
	}
	cnt=1;
	vector<ll> ans;
	while(ans.size()<n)
	{
		ll x=pq.top();
		pq.pop();
		if(isans[x])
		{
			continue;
		}
		vis[x]=false;
		if(check(p[x]))
		{
			ans.push_back(x);
			isans[x]=true;
			vis[x]=true;
		}
	}
	puts("YES");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",ans[i]+1);
	}
	return 0;
}