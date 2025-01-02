// LUOGU_RID: 157464937
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
int n;
string in;
int solve(int l,int r)//0,1,01
{
	if(l==r)
	{
		if(in[l]=='0')
		{
			return 4;
		}else if(in[l]=='1')
		{
			return 2;
		}else
		{
			return 1;
		}
	}
	int mid;
	if(in[l+1]=='?'||in[l+1]=='0'||in[l+1]=='1')
	{
		mid=l+2;
	}else
	{
		mid=l+2;
		for(int s=2;s>1;mid++)
		{
			if(in[mid]=='(')
			{
				s++;
			}else if(in[mid]==')')
			{
				s--;
			}
		}
	}
	int canl=solve(l+1,mid-1),canr=solve(mid+1,r-1);
	bool l0=(canl&4),l1=(canl&2),l01=(canl&1);
	bool r0=(canr&4),r1=(canr&2),r01=(canr&1);
	int ans=0;
	if(in[mid]=='|')
	{
		if(l0&&r0)
		{
			ans|=4;
		}
		if(l1||r1||(l01&&r01))
		{
			ans|=2;
		}
		if((l01&&(r0||r01))||(r01&&(l0||l01)))
		{
			ans|=1;
		}
	}else if(in[mid]=='&')
	{
		if(l0||r0||(l01&&r01))
		{
			ans|=4;
		}
		if(l1&&r1)
		{
			ans|=2;
		}
		if((l01&&(r1||r01))||(r01&&(l1||l01)))
		{
			ans|=1;
		}
	}else
	{
		if((l0&&r0)||(l1&&r1)||(l01&&r01))
		{
			ans|=4;
		}
		if((l0&&r1)||(l1&&r0)||(l01&&r01))
		{
			ans|=2;
		}
		if((l01&&(r0||r1))||(r01&&(l0||l1)))
		{
			ans|=1;
		}
	}
	return ans;
}
signed main()
{
	cin>>n>>in;
	cout<<((solve(0,in.length()-1)&1)?"YES":"NO");
}