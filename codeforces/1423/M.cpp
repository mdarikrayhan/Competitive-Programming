// LUOGU_RID: 160560704
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=1000010;

int n,ans,pos[maxn];

int nQuery(int i,int j)
{
	static unordered_map<int,int>mp;
	int &x=mp[i+j*(n+1)];
	if(!x)
	{
		cout<<"? "<<i<<' '<<j<<endl;
		cin>>x;
	}
	return x;
}

void dfs(int lv,const vector<int>&col)
{
	int nn=n/lv,i;
	vector<int>red{col[0]};
	auto it=col.begin()+1;
	while(it<col.end())
	{
		i=red.size();
		if(nQuery(i*lv,red.back())>=nQuery(i*lv,*it))
		{
			if(i==1) red.back()=*it,it++;
			else red.pop_back();
		}
		else
		{
			if(i<nn) red.push_back(*it);
			it++;
		}
	}
	if(nn==1)
	{
		pos[lv]=red[0];
		ans=nQuery(lv,red[0]);
		return;
	}
	dfs(lv*2,red);
	it=red.begin();
	for(i=lv;i<=n;i+=2*lv)
	{
		auto lt=it;
		int mn=nQuery(i,*lt);
		pos[i]=*lt;
		if(i+lv<=n)
		{
			for(;*it<pos[i+lv];it++);
		}
		else
		{
			it=red.end()-1;
		}
		for(lt++;lt<=it;lt++)
		{
			int tmp=nQuery(i,*lt);
			if(tmp<mn) mn=tmp,pos[i]=*lt;
		}
		ans=min(ans,mn);
	}
}

int main()
{
	int i,m;
	cin>>n>>m;
	vector<int>all(m);
	for(i=0;i<m;i++) all[i]=i+1;
	dfs(1,all);
	cout<<"! "<<ans<<endl;
	return 0;
}
