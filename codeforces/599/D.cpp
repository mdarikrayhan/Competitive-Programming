// LUOGU_RID: 155599876
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> >temp;
vector<pair<int,int> >res; 
signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int x,i,s1=0,s2=0;
	cin>>x;
	for(i=1;i*i<=x;i++)
	{
		s1+=i*i;
		s2+=i;
		int t=x-(s1-s2*i);
		if(t<=0)
		{
			break;
		}
		if(t%s2==0)
		{
			if(t/s2>=i)
			{
				temp.push_back({i,t/s2});
			}
		}
	}
	for(i=0;i<(int)temp.size();i++)
	{
		res.push_back({temp[i].first,temp[i].second});
	}
	for(i=(int)temp.size()-1;i>=0;i--)
	{
		if(temp[i].first!=temp[i].second)
		{
			res.push_back({temp[i].second,temp[i].first});
		}
	}
	cout<<res.size()<<endl;
	for(i=0;i<(int)res.size();i++)
	{
		cout<<res[i].first<<' '<<res[i].second<<endl;
	}
	return 0;
}