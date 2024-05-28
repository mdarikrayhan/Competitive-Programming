// LUOGU_RID: 158545542
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=1010,ini=31622;
constexpr long long lim=1e18;

bool np[ini+1];
long long a[maxn];
map<int,int>mp;
vector<long long>pw[60],gr[maxn];

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int n,k,i,tot=0;
	for(i=2;i<=ini;i++)
	{
		if(!np[i]) pw[0].push_back(i);
		for(int pr:pw[0])
		{
			int u=pr*i;
			if(u>ini) break;
			np[u]=true;
			if(i%pr==0) break;
		}
	}
	for(int it:pw[0])
	{
		long long x=it,mx=lim/it;
		for(i=2;x<=mx;i++)
		{
			x*=it;
			pw[i].push_back(x);
		}
	}
	auto prime=[](int x)
	{
		for(int pr:pw[0])
		{
			if(pr*pr>x) break;
			if(x%pr==0) return false;
		}
		return true;
	};
	auto dc=[&prime](long long x)
	{
		int y=sqrtl(x);
		if(1LL*y*y==x&&prime(y)) return y;
		y=cbrtl(x);
		if(1LL*y*y*y==x&&prime(y)) return y;
		for(int i=4;i<60;i++)
		{
			y=lower_bound(pw[i].begin(),pw[i].end(),x)-pw[i].begin();
			if(y!=(int)pw[i].size()&&pw[i][y]==x) return (int)pw[0][y];
		}
		if(x<=1e9&&prime(x)) return (int)x;
		return 0;
	};
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=dc(a[i]);
		if(!x) gr[0].push_back(a[i]);
		else
		{
			if(!mp.count(x)) mp[x]=++tot;
			gr[mp[x]].push_back(a[i]);
		}
	}
	int bs=0,three=-1;
	for(auto it=mp.begin();it!=mp.end();)
	{
		int tmp=gr[it->second].size();
		if(tmp==1) it=mp.erase(it);
		else
		{
			if(tmp>=3) three=it->second;
			bs+=tmp,it++;
		}
	}
	long long val=0;
	vector<int>req;
	for(auto it=gr[0].begin();it!=gr[0].end();)
	{
		long long x=*it;
		vector<int>now;
		for(const auto&jt:mp)
		{
			if(x%jt.first==0)
			{
				now.push_back(jt.second);
				do x/=jt.first;while(x%jt.first==0);
			}
		}
		if(x!=1) it=gr[0].erase(it);
		else
		{
			if(req.empty()||req.size()>now.size())
			{
				req=now;
				val=*it;
			}
			it++;
		}
	}
	if(k<=1||k>bs+(int)gr[0].size())
	{
		cout<<"0\n";
		return 0;
	}
	if(k>=bs)
	{
		for(const auto&it:mp)
		{
			for(auto jt:gr[it.second]) cout<<jt<<' ';
		}
		for(i=0;i<k-bs;i++) cout<<gr[0][i]<<' ';
		cout<<'\n';
		return 0;
	}
	if(k>=2*(int)mp.size())
	{
		for(const auto&it:mp)
		{
			auto&now=gr[it.second];
			cout<<now.back()<<' ';
			now.pop_back();
			cout<<now.back()<<' ';
			now.pop_back();
		}
		k-=2*mp.size();
		for(const auto&it:mp)
		{
			if(!k) break;
			for(auto jt:gr[it.second])
			{
				if(!k) break;
				k--;
				cout<<jt<<' ';
			}
		}
		cout<<'\n';
		return 0;
	}
	if(k%2==0)
	{
		for(const auto&it:mp)
		{
			cout<<gr[it.second][0]<<' '<<gr[it.second][1]<<' ';
			k-=2;
			if(!k) break;
		}
		cout<<'\n';
		return 0;
	}
	if(three!=-1)
	{
		for(i=0;i<3;i++) cout<<gr[three][i]<<' ';
		k-=3;
		for(const auto&it:mp)
		{
			if(!k) break;
			if(it.second==three) continue;
			cout<<gr[it.second][0]<<' '<<gr[it.second][1]<<' ';
			k-=2;
		}
		cout<<'\n';
		return 0;
	}
	if(!val||k<2*(int)req.size()+1)
	{
		cout<<"0\n";
		return 0;
	}
	cout<<val;
	for(int it:req)
	{
		cout<<' '<<gr[it][0]<<' '<<gr[it][1];
		gr[it].clear();
	}
	k-=2*req.size()+1;
	for(const auto&it:mp)
	{
		if(!k) break;
		auto&now=gr[it.second];
		if(now.empty()) continue;
		cout<<' '<<now[0]<<' '<<now[1];
		k-=2;
	}
	cout<<'\n';
	return 0;
}
