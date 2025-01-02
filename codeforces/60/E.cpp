// LUOGU_RID: 156835110
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld double
#define uint unsigned long long
#define endl '\n'
//#define ll __int128
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
	int fast_pow(int a,int b,int mod)
    {
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
int mod;
int _(int x)
{
	return (x%mod+mod)%mod;
}
class Zhen
{
	public:
		vector<vector<int>> num;
		int x,y;
		Zhen(int _x=0,int _y=0)
		:num(vector<vector<int>>(_x,vector<int>(_y,0ll))),x(_x),y(_y)
		{
		}
		Zhen operator * (const Zhen &a)
		{
			Zhen t(x,a.y);
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<a.y;j++)
				{
					for(int k=0;k<y;k++)
					{
						t.num[i][j]=_(t.num[i][j]+_(num[i][k]*a.num[k][j]));
					}
				}
			}
			return t;
		}
		void out()
		{
			for(int i=0;i<x;i++)
			{
				for(int j=0;j<y;j++)
				{
					cout<<num[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		Zhen pow(int kth)
		{
			Zhen ans(x,y),p(*this);
			for(int i=0;i<min(x,y);i++)
			{
				ans.num[i][i]=1;
			}
			for(;kth;kth>>=1)
			{
				if(kth&1)
				{
					ans=ans*p;
				}
				p=p*p;
			}
			return ans;
		}
};
int get_feibo(int a,int b,int kth)
{
	Zhen move(2,2),tar(2,1);
	move.num[0][0]=move.num[0][1]=move.num[1][0]=1;
	tar.num[0][0]=max(a,b);tar.num[1][0]=min(a,b);
	return (move.pow(kth)*tar).num[0][0];
}
int get_sum(int a,int b,int kth)
{
	Zhen move(2,2),tar(2,1);
	move.num[0][0]=3;move.num[0][1]=_(-1);move.num[1][1]=1;
	tar.num[0][0]=a;tar.num[1][0]=b;
	return (move.pow(kth)*tar).num[0][0];
}
int n,t1,t2;
vector<int> in;
void read()
{
	n=get_int();t1=get_int();t2=get_int();mod=get_int();
	in=vector<int>(n+1);
	for(int i=1;i<=n;i++)
	{
		in[i]=_(get_int());
	}
}
int solve()
{
	if(n==1)
	{
		return in[1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=_(ans+in[i]);
	}
	ans=get_sum(ans,_(in[1]+in[n]),t1);
	int minn=in[1],maxx=get_feibo(in[n-1],in[n],t1);
	return get_sum(ans,_(minn+maxx),t2);
}
signed main()
{
	read();
	out_int(solve());
}
/*
10 5057890300 245823386 10008
1 2 3 4 9 235 5467 34123 7665436 48673456
*/