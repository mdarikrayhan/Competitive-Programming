// LUOGU_RID: 159877370
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
class Long
{
	public:
		static const int P=1e8,L=8,M=20;
		int x[M+1];
		bool fu;
		Long(int in=0)
		{
			memset(x,0,sizeof(x));
			fu=0;
			if(in<0)
			{
				fu=1;
				in=-in;
			}
			for(int i=0;in;in/=P,i++)
			{
				x[i]=in%P;
			}
		}
		void operator = (int in)
		{
			memset(x,0,sizeof(x));
			fu=0;
			if(in<0)
			{
				fu=1;
				in=-in;
			}
			for(int i=0;in;in/=P,i++)
			{
				x[i]=in%P;
			}
		}
		bool operator == (Long a)
		{
			for(int i=M;i>=0;i--)
			{
				if(a.x[i]!=x[i])
				{
					return 0;
				}
			}
			return 1;
		}
		bool operator != (Long a)
		{
			return !((*this)==a);
		}
		bool compare_min_modulus(Long a)
		{
			for(int i=M;i>=0;i--)
			{
				if(a.x[i]>x[i])
				{
					return 1;
				}
				if(a.x[i]<x[i])
				{
					return 0;
				}
			}
			return 0;
		}
		bool operator < (Long a)
		{
			if(fu&&!a.fu)
			{
				return 1;
			}
			if(!fu&&a.fu)
			{
				return 0;
			}
			if(fu&&a.fu)
			{
				return !compare_min_modulus(a);
			}
			return compare_min_modulus(a);
		}
		bool operator > (Long a)
		{
			return a<(*this);
		}
		bool operator <= (Long a)
		{
			return !(a<(*this));
		}
		bool operator >= (Long a)
		{
			return !(a>(*this));
		}
		Long operator * (Long a)
		{
			Long t;
			t.fu=fu^a.fu;
			for(int i=0;i<=M;i++)
			{
				for(int j=0;i+j<=M;j++)
				{
					t.x[i+j]+=a.x[i]*x[j];
				}
			}
			for(int i=0;i<M;i++)
			{
				t.x[i+1]+=t.x[i]/P;
				t.x[i]%=P;
			}
			return t;
		}
		Long modulus_add(Long a)
		{
			Long t;
			for(int i=0;i<=M;i++)
			{
				t.x[i]=x[i]+a.x[i];
			}
			for(int i=0;i<M;i++)
			{
				if(t.x[i]>=P)
				{
					t.x[i+1]++;
					t.x[i]-=P;
				}
			}
			return t;
		}
		Long modulus_reduce(Long a)
		{
			Long t;
			int d=1;
			if(compare_min_modulus(a))
			{
				d=-1;
				t.fu=1;
			}
			for(int i=0;i<=M;i++)
			{
				t.x[i]=d*(x[i]-a.x[i]);
			}
			for(int i=0;i<M;i++)
			{
				if(t.x[i]<0)
				{
					t.x[i+1]--;
					t.x[i]+=P;
				}
			}
			return t;
		}
		Long operator + (Long a)
		{
			Long t;
			if(fu==a.fu)
			{
				t=modulus_add(a);
				t.fu=fu;
				return t;
			}
			t=modulus_reduce(a);
			t.fu^=fu;
			return t;
		}
		Long operator - (Long a)
		{
			a.fu^=1;
			return (*this)+a;
		}
		void modulus_division(Long a,Long &discuss,Long &model)
		{
			discuss=Long();model=(*this);
			model.fu=0;a.fu=0;
			if(a==Long(0))
			{
				return;
			}
			Long f=a;
			int yi=0;
			for(;!model.compare_min_modulus(f);yi++)
			{
				for(int j=0;j<=yi;j++)
				{
					f.x[j]=0;
				}
				for(int j=yi+1;j<=M;j++)
				{
					f.x[j]=a.x[j-(yi+1)];
				}
			}
			int top=M;
			for(;;top--)
			{
				if(f.x[top])
				{
					break;
				}
			}
			for(;yi;yi--)
			{
				for(int i=0;i<M;i++)
				{
					f.x[i]=f.x[i+1];
					f.x[i+1]=0;
				}
				if(top<M)
				{
					model.x[top]+=model.x[top+1]*P;
					model.x[top+1]=0;
				}
				int l=0,r=P*P;
				for(;l<r;)
				{
					int mid=(l+r+1)/2;
					if(model.compare_min_modulus(f*Long(mid)))
					{
						r=mid-1;
					}else
					{
						l=mid;
					}
				}
				model-=f*Long(l);
				discuss.x[yi-1]+=l;
			}
		}
		Long operator / (Long a)
		{
			Long discuss,model;
			modulus_division(a,discuss,model);
			discuss.fu=fu^a.fu;model.fu=fu^a.fu;
			if(model<Long(0))
			{
				discuss-=Long(1);
			}
			return discuss;
		}
		Long operator % (Long a)
		{
			Long discuss,model;
			modulus_division(a,discuss,model);
			discuss.fu=fu^a.fu;model.fu=fu^a.fu;
			if(model<Long(0))
			{
				model+=a;
			}
			return model;
		}
		void operator += (Long a)
		{
			(*this)=(*this)+a;
		}
		void operator -= (Long a)
		{
			(*this)=(*this)-a;
		}
		void operator *= (Long a)
		{
			(*this)=(*this)*a;
		}
		void operator /= (Long a)
		{
			(*this)=(*this)/a;
		}
		void operator %= (Long a)
		{
			(*this)=(*this)%a;
		}
		friend istream &operator >> (istream &input,Long &a)
		{
			a=Long();
	        char c=getchar();
	        for(;c<'0'||c>'9';c=getchar())
	        {
	        	if(c=='-')
	        	{
	        		a.fu=1;
				}
	        }
	        int i=M,q=P;
	        bool can=1;
	        for(;i>=0;i--)
	        {
	        	for(q=P;q>1;q/=10,c=getchar())
	        	{
	        		if(c<'0'||c>'9')
	        		{
	        			can=0;
	        			break;
					}
	        		a.x[i]=a.x[i]*10+c-'0';
				}
				if(!can)
				{
					break;
				}
	        }
	        int l=0;
	        for(;i<=M;l++,i++)
	        {
				a.x[l]=a.x[i];
	        	a.x[i]=0;
	        	if(i<M)
	        	{
	        		a.x[l]+=a.x[i+1]%q*(P/q);
					a.x[i+1]/=q;
				}
			}
	        return input;
		}
		friend ostream &operator << (ostream &output,Long a)
		{
			bool can=0;
			if(a.fu)
			{
				putchar('-');
			}
	        for(int i=M;i>=0;i--)
	        {
	        	int q=P/10;
	        	if(!can&&a.x[i])
	        	{
	        		can=1;
	        		for(;!(a.x[i]/q)&&q;q/=10)
	        		{
					}
				}
	        	if(a.x[i])
	        	{
	        		can=1;
				}
				if(can)
				{
					for(;q;q/=10)
        			{
        				putchar((a.x[i]/q-a.x[i]/(q*10)*10)+'0');
					}
				}
	        }
	        if(!can)
	        {
	        	putchar('0');
			}
	        return output;
		}
};
Long _max(Long a,Long b)
{
	return a<b?b:a;
}
class node
{
	public:
		vector<Long> dp;
		int size;
};
int n;
vector<node> th;
Road road;
void read()
{
	cin>>n;
	th=vector<node>(n+1);
	road.init(n);
	for(int i=1,a,b;i<n;i++)
	{
		cin>>a>>b;
		road.twoadd_yes(a,b);
	}
}
void dfs(int w,int fa)
{
	th[w].dp=vector<Long>(2,0);
	th[w].size=1;
	th[w].dp[1]=1;
	for(int i=road.tope[w];i;i=road.edge[i].nxt)
	{
		int to=road.edge[i].to;
		if(to==fa)
		{
			continue;
		}
		dfs(to,w);
		th[w].size+=th[to].size;
		vector<Long> dp(th[w].size+1,0);
		for(int s=1;s<=th[w].size;s++)
		{
			for(int ls=max(s-th[to].size,1ll);ls<=min(s,th[w].size-th[to].size);ls++)
			{
				dp[s]=_max(dp[s],th[w].dp[ls]*th[to].dp[s-ls]);
			}
		}
		th[w].dp=dp;
	}
	for(int s=1;s<=th[w].size;s++)
	{
		th[w].dp[0]=_max(th[w].dp[0],th[w].dp[s]*s);
	}
}
Long solve()
{
	dfs(1,0);
/*	for(int w=1;w<=n;w++)
	{
		for(int i=0;i<=th[w].size;i++)
		{
			cout<<th[w].dp[i]<<" ";
		}
		cout<<endl;
	}*/
	return th[1].dp[0];
}
signed main()
{
	read();
	cout<<solve();
}