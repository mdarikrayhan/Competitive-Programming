// LUOGU_RID: 159903506
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld double
#define uint unsigned long long
#define endl '\n'
#define ll __int128
#pragma comment(linker,"/STACK:1024000000,1024000000")
namespace OOO
{
	inline void fast_io()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
	int get_int()
	{
	    int x=0;
	    bool y=0;
	    char c=getchar();
	    for(;c<'0'||c>'9';c=getchar())
	    {
	        if(c=='-')
	        {
	            y=1;
	        }
	    }
	    for(;c>='0'&&c<='9';c=getchar())
	    {
	        x=(x<<3)+(x<<1)+c-'0';
	    }
	    return y?-x:x;
	}
	template <typename T> void out_int(T x)
	{
		if(x==0)
		{
			putchar('0');
			return;
		}
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		T s=1;
		for(;s<=x;s=(s<<3)+(s<<1))
		{
		}
		for(s/=10;s;s/=10)
		{
			putchar(x/s-x/(s*10)*10+'0');
		}
	}
	int fast_pow(int a,int b)
    {
    	if(b<0)
    	{
    		return 0;
		}
    	int ans=1;
        for(;b;b>>=1)
        {
            if(b&1)
            {
                ans*=a;
            }
            a*=a;
        }
        return ans;
    }
	int fast_pow(int a,int b,int mod)
    {
    	if(b<0)
    	{
    		return 0;
		}
        int ans=1;
        if(a>mod)
        {
        	a%=mod;
		}
        for(;b;b>>=1)
        {
            if(b&1)
            {
                ans=ans*a;
				if(ans>mod)
            	{
            		ans%=mod;
				}
            }
            a=a*a;
            if(a>mod)
            {
            	a%=mod;
			}
        }
        return ans;
    }
    inline int ni(int a,int mod)
	{
		return fast_pow(a,mod-2,mod);
	}
	int sgn(ld x)
	{
		static const ld eps=1e-8;
		if(fabs(x)-eps<0)
		{
			return 0;
		}
		return x>0?1:-1;
	}
	inline ld _max(ld a,ld b)
	{
		return a-b>0?a:b;
	}
	inline ld _min(ld a,ld b)
	{
		return a-b>0?b:a;
	}
}using namespace OOO;
class Edge
{
	public:
		int st,to;
		int cost;
		int num;
		int nxt;
		Edge(int _st=0,int _to=0,int _cost=0,int _num=0,int _nxt=0)
		:st(_st),to(_to),cost(_cost),num(_num),nxt(_nxt)
		{
		}		
};
class Road
{
	public:
		vector<Edge> edge;
		vector<int> tope;
		int cnt;
		void init(int p_num=0,int edge_num=0)
		{
			edge=vector<Edge>(edge_num+1);
			tope=vector<int>(p_num+1,0);
			cnt=0;
		}
		int newnode()
		{
			if(cnt==edge.size()-1)
			{
				edge.push_back(Edge());
			}
			return ++cnt;
		}
		void addedge(int a,int b,int cost=0,int num=0)
		{
			int s=max(a,b);
			if(s>=tope.size())
			{
				tope.resize(s+1);
			}
			edge[newnode()]=Edge(a,b,cost,num,tope[a]);
			tope[a]=cnt;
		}
		void twoadd_none(int a,int b,int cost=0,int num=0)
		{
			addedge(a,b,cost,num);
			addedge(b,a,-cost,0);
		}
		void twoadd_yes(int a,int b,int cost=0,int num=0)
		{
			addedge(a,b,cost,num);
			addedge(b,a,cost,num);
		}
		int other(int x)
		{
			if(x%2)
			{
				return x+1;
			}
			return x-1;
		}
};
class BCJ
{
	public:
		vector<int> below;
		vector<set<int>> key;
		
		void init(int n)
		{
			below=vector<int>(n+1);
			key=vector<set<int>>(n+1);
			for(int i=1;i<=n;i++)
			{
				below[i]=i;
			}
		}
		int Find(int x)
		{
			if(x!=below[x])
			{
				below[x]=Find(below[x]);
			}
			return below[x];
		}
		bool merge(int a,int b)
		{
			int ba=Find(a),bb=Find(b);
			if(ba==bb)
			{
				return 0;
			}
			if(key[ba].size()>key[bb].size())
			{
				swap(ba,bb);
			}
			below[ba]=bb;
			for(auto i:key[ba])
			{
				key[bb].insert(i);
			}
			key[ba]=set<int>();
			return 1;
		}
};
class node
{
	public:
		set<int> st_have,en_have;
		int st_w,en_w;
};
int n,m,p;
Road road;
vector<node> th;
void read()
{
	cin>>n>>m>>p;
	th=vector<node>(p+1);
	road.init(n);
	for(int i=1,a,b;i<=m;i++)
	{
		cin>>a>>b;
		road.twoadd_yes(a,b,0,i);
	}
	map<string,int> to;
	string name;
	for(int w=1,size;w<=p;w++)
	{
		cin>>name;
		to[name]=w;
		cin>>th[w].st_w>>size;
		for(int i=0,a;i<size;i++)
		{
			cin>>a;th[w].st_have.insert(a);
		}
	}
	for(int _w=1,size;_w<=p;_w++)
	{
		cin>>name;
		int w=to[name];
		cin>>th[w].en_w>>size;
		for(int i=0,a;i<size;i++)
		{
			cin>>a;th[w].en_have.insert(a);
		}
	}
}
bool in_set(const set<int> &a,const set<int> &tar)
{
	for(auto i:a)
	{
		if(!tar.count(i))
		{
			return 0;
		}
	}
	return 1;
}
bool solve()
{
	BCJ st_room,en_room;
	st_room.init(n);en_room.init(n);
	for(int w=1;w<=p;w++)
	{
		for(auto i:th[w].st_have)
		{
			st_room.key[th[w].st_w].insert(i);
		}
		for(auto i:th[w].en_have)
		{
			en_room.key[th[w].en_w].insert(i);
		}
	}
	for(bool can=1;can;)
	{
		can=0;
		for(int w=1;w<=n;w++)
		{
			for(int i=road.tope[w];i;i=road.edge[i].nxt)
			{
				int to=road.edge[i].to,num=road.edge[i].num;
				if(st_room.key[st_room.Find(w)].count(num))
				{
					can|=st_room.merge(w,to);
				}
			}
		}
	}
	for(bool can=1;can;)
	{
		can=0;
		for(int w=1;w<=n;w++)
		{
			for(int i=road.tope[w];i;i=road.edge[i].nxt)
			{
				int to=road.edge[i].to,num=road.edge[i].num;
				if(en_room.key[en_room.Find(w)].count(num))
				{
					can|=en_room.merge(w,to);
				}
			}
		}
	}
	for(int w=1;w<=p;w++)
	{
		if(st_room.Find(th[w].st_w)!=st_room.Find(th[w].en_w)||
		en_room.Find(th[w].st_w)!=en_room.Find(th[w].en_w)||
		!in_set(th[w].en_have,st_room.key[st_room.Find(th[w].en_w)])||
		!in_set(th[w].st_have,en_room.key[en_room.Find(th[w].st_w)]))
		{
			return 0;
		}
	}
	return 1;
}
signed main()
{
	read();
	cout<<(solve()?"YES":"NO");
}