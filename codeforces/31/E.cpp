// LUOGU_RID: 159055644
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
	void fast_io()
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
    int ni(int a,int mod)
	{
		return fast_pow(a,mod-2,mod);
	}
	int sgn(ld x)
	{
		static const ld eps=1e-10;
		if(abs(x)<eps)
		{
			return 0;
		}
		return x>0?1:-1;
	}
}using namespace OOO;
int n;
vector<int> in;
void read()
{
	cin>>n;
	in=vector<int>(2*n);
	char c;
	for(int i=0;i<2*n;i++)
	{
		cin>>c;
		in[i]=c-'0';
	}
}
int count(int x)
{
	int ans=0;
	for(;x;x>>=1)
	{
		ans+=(x&1);
	}
	return ans;
}
void solve()
{
	vector<pair<int,int>> maxl(n+1,{-1,0}),maxr(n+1,{-1,0});
	for(int sta=0;sta<(1<<n);sta++)
	{
		int sl0=0,sl1=0,sr0=0,sr1=0;
		int c1=count(sta);
		int q0=pow(10,c1),q1=pow(10,n-c1);
		for(int w=0;w<n;w++)
		{
			if(sta&(1<<w))
			{
				sl1=sl1*10+in[w]*q1;
				sr1=sr1*10+in[w+n];
			}else
			{
				sl0=sl0*10+in[w]*q0;
				sr0=sr0*10+in[w+n];
			}
		}
		int sl=sl0+sl1,sr=sr0+sr1;
		if(maxl[c1].first<sl)
		{
			maxl[c1].first=sl;
			maxl[c1].second=sta;
		}
		if(maxr[c1].first<sr)
		{
			maxr[c1].first=sr;
			maxr[c1].second=sta;
		}
	}
	
	pair<int,int> maxx={-1,0};
	for(int i=0;i<=n;i++)
	{//cout<<maxl[i].first<<" "<<maxr[i].first<<endl;
		int sum=maxl[i].first+maxr[n-i].first;
		if(maxx.first<sum)
		{
			maxx.first=sum;
			maxx.second=i;
		}
	}cout<<endl;
	int lsta=maxl[maxx.second].second,rsta=maxr[n-maxx.second].second;
	for(int i=0;i<n;i++)
	{
		cout<<((lsta&(1<<i))?'H':'M');
	}
	for(int i=0;i<n;i++)
	{
		cout<<((rsta&(1<<i))?'H':'M');
	}
}
signed main()
{
	read();
	solve();
}