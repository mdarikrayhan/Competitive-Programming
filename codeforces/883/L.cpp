#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli INF = 1e15;
#define pll pair<lli, pair<lli, lli> >
lli x[200005];
int main()
{
	int n, k, m;
	cin>>n>>k>>m;
	set<pair<lli, pair<lli, lli> > > st;
	for(int i=0;i<k;i++)
	{
		cin>>x[i];
		st.insert({x[i], {0, -i}});
	}
	lli tc=0;
	set<lli> ts;
	map<lli, vector<lli> > mp;
	for(int i=0;i<m;i++)
	{
		lli t,a,b;
		cin>>t>>a>>b;
		while(st.empty() || (!ts.empty() && *ts.begin()<=t))
		{
			auto xd = *ts.begin();
			tc = xd;
			ts.erase(xd);
			for(auto j: mp[xd])
			{
				st.insert({x[j], {-xd, -j}});
			}
		}
		pll ans = {-INF, {0, 0}};
		pll se = {a, {-INF, -INF}};
		auto xd = st.lower_bound(se);
		if(xd!=st.end())
		{
			pll sd = {xd->first+1, {-INF, -INF}};
			auto now = st.lower_bound(sd);
			now--;
			pll ch = {-abs(now->first-a), now->second};
			ans = max(ans, ch);
		}
		if(xd!=st.begin())
		{
			xd--;
			pll ch = {-abs(xd->first-a), xd->second};
			ans = max(ans, ch);
		}
		tc = max(tc, t);
		lli cr = -ans.second.second;
		lli wt = tc-t + abs(x[cr]-a);
		cout<<cr+1<<" "<<wt<<"\n";
		st.erase({x[cr], ans.second});
		lli tr=tc-ans.first+abs(b-a);
		mp[tr].push_back(cr);
		ts.insert(tr);
		x[cr] = b;
	}
}