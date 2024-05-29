// LUOGU_RID: 158287532
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll a,b,c,l,id[N],lst[3]={0,0,0};
vector<pair<ll,pair<ll,ll> > > ans;
int main(){
	ll i;
	cin>>a>>b>>c>>l;
	id[0]=id[1]=-1;
	for(i=2;i<=l;i++)
	{
		vector<pair<ll,ll> > cur={{lst[0],0},{lst[1],1},{lst[2],2}};
		sort(cur.begin(),cur.end());
		if(c&&cur[0].F<=i-4)
		{
			c--;
			if(cur[2].F<=i-4)
			{
				ans.push_back(make_pair(cur[2].S,make_pair(i-4,i)));
				lst[cur[2].S]=i;
			}
			else if(cur[1].F<=i-4)
			{
				ans.push_back(make_pair(cur[1].S,make_pair(i-4,i)));
				lst[cur[1].S]=i;
			}
			else
			{
				ans.push_back(make_pair(cur[0].S,make_pair(i-4,i)));
				lst[cur[0].S]=i;
			}
		}
		else if(b&&cur[0].F<=i-3)
		{
			b--;
			if(cur[2].F<=i-3)
			{
				ans.push_back(make_pair(cur[2].S,make_pair(i-3,i)));
				lst[cur[2].S]=i;
			}
			else if(cur[1].F<=i-3)
			{
				ans.push_back(make_pair(cur[1].S,make_pair(i-3,i)));
				lst[cur[1].S]=i;
			}
			else
			{
				ans.push_back(make_pair(cur[0].S,make_pair(i-3,i)));
				lst[cur[0].S]=i;
			}
		}
		else if(a&&cur[0].F<=i-2)
		{
			a--;
			if(cur[2].F<=i-2)
			{
				ans.push_back(make_pair(cur[2].S,make_pair(i-2,i)));
				lst[cur[2].S]=i;
			}
			else if(cur[1].F<=i-2)
			{
				ans.push_back(make_pair(cur[1].S,make_pair(i-2,i)));
				lst[cur[1].S]=i;
			}
			else
			{
				ans.push_back(make_pair(cur[0].S,make_pair(i-2,i)));
				lst[cur[0].S]=i;
			}
		}
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld %lld\n",ans[i].F+1,ans[i].S.F,ans[i].S.S);
	}
	return 0;
}