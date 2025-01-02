// LUOGU_RID: 160259116
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld double
#define uint unsigned long long
#define endl '\n'
#define ll __int128
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
const int mod=1e9+7;
int _(int x)
{
	return (x%mod+mod)%mod;
}
int n;
vector<int> num;
void read()
{
	cin>>n;
	num=vector<int>(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
}
vector<int> jie;
int C(int a,int b)
{
	return _(jie[a]*ni(_(jie[b]*jie[a-b]),mod));
}
int solve()
{
	jie=vector<int>(n+1,1);
	for(int i=1;i<=n;i++)
	{
		jie[i]=_(jie[i-1]*i);
	}
	
	int s1=0,s2=0;
	vector<bool> use(n+1);
	for(int i=1;i<=n;i++)
	{
		if(num[i]==i)
		{
			return 0;
		}
		if(num[i]>0)
		{
			use[num[i]]=1;
			s1++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]>0)
		{
			s2+=(!use[i]);
		}
	}
	int ans=0;
	for(int i=0;i<=n-s1-s2;i++)
	{
		ans=_(ans+_(((i&1)?-1:1)*_(C(n-s1-s2,i)*jie[n-s1-i])));
	}
	return ans;
}
signed main()
{
	read();
	cout<<solve();
}