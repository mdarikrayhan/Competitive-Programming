//author: towrist

#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <assert.h>
#include <stack>
#include <climits>
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#define int long long int
using namespace std;

/*
easy to guess but the proof was quite hard.
if can descend: descend
otherwise, exchange.

proof works because when you are forced to ascend, there will be atleast an equal amount of ascents in the competing algorithm.
*/

const int INF=1e16;

void solve()
{
	int n, k;
	cin>>n>>k;
	
	vector<int> a(n);
	for (int z=0; z<n; z++) 
	{
		cin>>a[z];
		a[z]%=k;
	}
	
	multiset<int> potential;
	
	int res=a[0];
	for (int z=1; z<n; z++)
	{
		//descend if possible, and store potential
		if (a[z]<=a[z-1]) potential.insert((a[z]+k-a[z-1]));
		else
		{
			int cost1=INF;
			if (!potential.empty()) cost1=*potential.begin();
			int cost2=a[z]-a[z-1];
			if (cost1<cost2)
			{
				potential.erase(potential.begin());
				potential.insert(a[z]-a[z-1]);				
			}
			res+=min(cost1, cost2);
		}
	}
	
	cout<<res<<'\n';
	
	return;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	//t=1;
	//cout<<'\n';
	while (t--)
	{
		solve();
	}
	return 0;
}