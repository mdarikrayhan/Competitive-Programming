// LUOGU_RID: 158962963
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
vector<vector<pair<int,int>>> solve()
{
	vector<int> where(n+1);
	for(int i=1;i<=n;i++)
	{
		where[num[i]]=i;
	}
	
	vector<bool> v(n+1);
	vector<vector<int>> huan;
	vector<queue<int>> q(5);
	for(int w=1;w<=n;w++)
	{
		if(v[w])
		{
			continue;
		}
		huan.push_back(vector<int>());
		for(int now=w;;now=where[now])
		{
			if(v[now])
			{
				break;
			}
			v[now]=1;
			huan[huan.size()-1].push_back(now);
		}
		int mo=huan[huan.size()-1].size()%4;
		q[mo].push(huan.size()-1);
	}
/*	for(int i=0;i<huan.size();i++)
	{
		for(int j=0;j<huan[i].size();j++)
		{
			cout<<huan[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	
	vector<int> ids(huan.size());
	vector<vector<pair<int,int>>> ans;
	for(int w=0;w<huan.size();)
	{
		vector<int> s;
		if(huan[w].size()%4<2)
		{
			if(huan[w].size()-ids[w]<4)
			{
				w++;
				continue;
			}
			for(int i=1;ids[w]<huan[w].size()&&i<=5;ids[w]++,i++)
			{
				s.push_back(huan[w][ids[w]]);
			}
			ids[w]-=(ids[w]<huan[w].size());
			w+=(ids[w]==huan[w].size());
		}else
		{
			if(huan[w].size()-ids[w]<4)
			{
				w++;
				continue;
			}
			for(int i=1;ids[w]<huan[w].size()/4*4+1&&i<=5;ids[w]++,i++)
			{
				s.push_back(huan[w][ids[w]]);
			}
			ids[w]--;
		}
		
		vector<int> now=s;
		for(int i=0;i<s.size();i++)
		{
			int swapw=-1;
			for(int j=0;j<s.size();j++)
			{
				if(s[i]==num[s[j]])
				{
					swapw=j;
				}
			}
			if(swapw>=0)
			{
				swap(where[num[s[swapw]]],where[num[s[i]]]);
				swap(num[s[swapw]],num[s[i]]);
				swap(now[i],now[swapw]);
			}
		/*	for(int i=1;i<=n;i++)
			{
				cout<<num[i]<<" ";
			}cout<<endl;*/
		}
		ans.push_back(vector<pair<int,int>>());
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<now.size();j++)
			{
				if(s[i]==now[j])
				{
					ans[ans.size()-1].push_back({s[i],s[j]});
					break;
				}
			}
		}
	/*	for(int i=1;i<=n;i++)
		{
			cout<<num[i]<<" ";
		}cout<<endl<<endl;*/
	}
	for(;;)
	{
		vector<int> s;
		if(q[2].size()&&q[3].size())
		{
			for(;ids[q[2].front()]<huan[q[2].front()].size();ids[q[2].front()]++)
			{
				s.push_back(huan[q[2].front()][ids[q[2].front()]]);
			}
			q[2].pop();
			for(;ids[q[3].front()]<huan[q[3].front()].size();ids[q[3].front()]++)
			{
				s.push_back(huan[q[3].front()][ids[q[3].front()]]);
			}
			q[3].pop();
		}else if(q[3].size())
		{
			for(;ids[q[3].front()]<huan[q[3].front()].size();ids[q[3].front()]++)
			{
				s.push_back(huan[q[3].front()][ids[q[3].front()]]);
			}
			q[3].pop();
			if(q[3].size())
			{
				for(;ids[q[3].front()]<huan[q[3].front()].size()-1;ids[q[3].front()]++)
				{
					s.push_back(huan[q[3].front()][ids[q[3].front()]]);
				}
				ids[q[3].front()]--;
				q[2].push(q[3].front());
				q[3].pop();
			}
		}else if(q[2].size())
		{
			for(;ids[q[2].front()]<huan[q[2].front()].size();ids[q[2].front()]++)
			{
				s.push_back(huan[q[2].front()][ids[q[2].front()]]);
			}
			q[2].pop();
			if(q[2].size())
			{
				for(;ids[q[2].front()]<huan[q[2].front()].size();ids[q[2].front()]++)
				{
					s.push_back(huan[q[2].front()][ids[q[2].front()]]);
				}
				q[2].pop();
			}
		}else
		{
			break;
		}
		
		vector<int> now=s;
		for(int i=0;i<s.size();i++)
		{
			int swapw=-1;
			for(int j=0;j<s.size();j++)
			{
				if(s[i]==num[s[j]])
				{
					swapw=j;
				}
			}
			if(swapw>=0)
			{
				swap(where[num[s[swapw]]],where[num[s[i]]]);
				swap(num[s[swapw]],num[s[i]]);
				swap(now[i],now[swapw]);
			}
		}
		ans.push_back(vector<pair<int,int>>());
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<now.size();j++)
			{
				if(s[i]==now[j])
				{
					ans[ans.size()-1].push_back({s[i],s[j]});
					break;
				}
			}
		}
	/*	for(int i=1;i<=n;i++)
		{
			cout<<num[i]<<" ";
		}cout<<endl;*/
	}
/*	for(int i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}cout<<endl;*/
	return ans;
}
signed main()
{
	read();
	vector<vector<pair<int,int>>> ans=solve();
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].size()<<endl;
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j].first<<" ";
		}
		cout<<endl;
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j].second<<" ";
		}
		cout<<endl;
	}
}
/*
10
3 7 2 6 8 10 4 1 5 9
*/