// LUOGU_RID: 159249839
#include<bits/stdc++.h>
#define ls u*2
#define rs u*2+1
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,M=32;
int n,m,qm;
stack<int> stk1;
struct C
{
	int u,w,v,d;
};
stack<C> stk2;
struct E
{
	int a,b,c;
};
struct Base
{
	int B[M];
	bool insert(int x)
	{
		for(int i=M-1;i>=0;i--)
		{
			int v=(x>>i)&1;
			if(!v) continue;
			if(!B[i]) 
			{
				B[i]=x;
				stk1.push(i);
				return true;
			}
			x^=B[i];
		}
		return false;
	}
	int query(int x)
	{
		int res=x;
		for(int i=M-1;i>=0;i--) res=min(res,res^B[i]);
		return res;
	}
	void back(int i)
	{
		B[i]=0;
	}
}B;
struct Dsu
{
	int p[N],val[N],dep[N];
	void init()
	{
		for(int i=1;i<=n;i++) p[i]=i,dep[i]=1,val[i]=0;
	}
	int find(int x)
	{
		if(p[x]!=x) return find(p[x]);
		return p[x];
	}
	int get(int x)
	{
		if(p[x]!=x) return val[x]^get(p[x]);
		return 0;	
	} 
	bool merge(int x,int y,int c)
	{
		int px=find(x),py=find(y);
		c^=get(x)^get(y);
		if(px==py)
		{
			B.insert(c);
			return false;
		}
		if(dep[px]>dep[py]) swap(px,py),swap(x,y); 
		stk2.push({px,val[px],py,dep[py]});
		val[px]^=c,p[px]=py;
		if(dep[px]==dep[py]) dep[py]++;
		return true;
	}
	void back(C T)
	{
		int u=T.u,w=T.w,v=T.v,d=T.d;
		p[u]=u,val[u]=w,dep[v]=d;
	}
}Dsu;
map<PII,int> w;
map<PII,int> pre;
PII qry[N];
int ans[N];
struct Tree
{
	int l,r;
	vector<E> vc;
}tr[N*4];

void build(int u,int l,int r)
{
	tr[u].l=l,tr[u].r=r;
	if(l==r) return;
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);
}

void insert(int u,int l,int r,E x)
{
	if(l>r) return;
	if(tr[u].l>=l&&tr[u].r<=r) tr[u].vc.push_back(x);
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) insert(ls,l,r,x);
		if(r>mid) insert(rs,l,r,x);
	}
}

void dfs(int u)
{
	int sz1=stk1.size(),sz2=stk2.size();
	for(auto e:tr[u].vc)
	{
		int a=e.a,b=e.b,c=e.c;
		Dsu.merge(a,b,c);
	}
	if(tr[u].l==tr[u].r) 
	{
		int i=tr[u].l,a=qry[i].first,b=qry[i].second;
		if(a&&b) ans[i]=B.query(Dsu.get(a)^Dsu.get(b));
	}
	else dfs(ls),dfs(rs);
	while(stk1.size()>sz1)
	{
		auto x=stk1.top();stk1.pop();
		B.back(x);
	}
	while(stk2.size()>sz2)
	{
		auto T=stk2.top();stk2.pop();
		Dsu.back(T);
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1,a,b,c;i<=m;i++)
	{
		cin>>a>>b>>c;
		w[{a,b}]=c;
		pre[{a,b}]=1;
	}
	
	cin>>qm;
	Dsu.init();
	build(1,1,qm);
	
	for(int i=1,op,x,y,d;i<=qm;i++)
	{
		cin>>op>>x>>y;
		if(op==1)
		{
			cin>>d;
			pre[{x,y}]=i,w[{x,y}]=d;
		}
		if(op==2)
		{
			insert(1,pre[{x,y}],i-1,(E){x,y,w[{x,y}]});
			pre[{x,y}]=0;
		}
		if(op==3)
		{
			qry[i]={x,y};
		}
	}
	
	for(auto It:pre)
	{
		PII	P=It.first;
		int x=It.second;
		if(!x) continue;
		insert(1,x,qm,(E){P.first,P.second,w[P]});
	} 
	
	dfs(1); 
	
	for(int i=1;i<=qm;i++) if(qry[i].first) cout<<ans[i]<<"\n";
	
	return 0;
}