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
using namespace std;

/*
change in inversion count = (n-d)(d+1)+1
for even n, the delta is always odd.
for odd n, we can change the permutation parity by performing n moves on the last element successively
*/

bool debg=false;

void solve()
{
	int n, m;
	cin>>n>>m;
	vector<int> p(n), q(m);
	for (int i=0; i<n; i++) cin>>p[i];
	for (int j=0; j<m; j++) cin>>q[j];
	auto P=p, Q=q;
	auto perform=[](vector<int>& p, int i)
	{
		vector<int> r;
		for (int z=i+1; z<p.size(); z++) r.push_back(p[z]);
		r.push_back(p[i]);
		for (int z=0; z<i; z++) r.push_back(p[z]);
		swap(r, p);
	};
	
	auto ascend=[perform](int n, vector<int>& p)
	{
		vector<int> moves;
		//invariant: curr+1 is always gonna be at the first pos, and curr+1, curr+2 ... n are gonna be consec
		//first make invariant true for n
		if (p[0]!=n)
		{
			for (int z=0; z<n-1; z++) if (p[z+1]==n)
			{
				moves.push_back(z);
				perform(p, z);
				break;
			}
		}
		
		int curr=n-1;
		while (curr)
		{
			//curr+1 is at the beginning
			assert(p[0]==curr+1);
			for (int z=1; z<n; z++)
			{
				if (p[z]==curr)
				{
					moves.push_back(z);
					perform(p, z);
					if (p[0]!=curr)
					{
						for (int z=0; z+1<n; z++) if (p[z+1]==curr)
						{
							moves.push_back(z);
							perform(p, z);					
						}
					}
					curr--; 
					break;
				}
			}
		}
		for (int z=0; z<n; z++) assert(p[z]==z+1);
		return moves;
	};
	
	vector<int> moves[2]={ascend(n, p), ascend(m, q)};
	
	if (((int)moves[0].size()%2)!=((int)moves[1].size()%2))
	{
		if (n%2==0 && m%2==0)
		{
			cout<<-1<<'\n';
			return;
		}
		if (n%2)
		{
			for (int j=1; j<=n; j++)
			{
				moves[0].push_back(n-1);
				perform(p, n-1);
			}
		}
		else
		{
			for (int j=1; j<=m; j++)
			{
				moves[1].push_back(m-1);
				perform(q, m-1);
			}
		}
	}
	
	//now necessacirily, moves[0]%2==moves[1]%2
	assert(((int)moves[0].size()%2)==(int)moves[1].size()%2);
	
	if ((int)moves[0].size()<(int)moves[1].size())
	{
		int diff=(int)moves[1].size()-(int)moves[0].size();
		for (int j=0; j<diff/2; j++)
		{
			moves[0].push_back(0);
			moves[0].push_back(n-1);
		}
	}
	else
	{
		int diff=(int)moves[0].size()-(int)moves[1].size();
		for (int j=0; j<diff/2; j++)
		{
			moves[1].push_back(0);
			moves[1].push_back(m-1);
		}
	}
	cout<<moves[0].size()<<'\n';
	for (int i=0; i<moves[0].size(); i++) 
	{
		cout<<moves[0][i]+1<<' '<<moves[1][i]+1<<'\n';
		perform(P, moves[0][i]);
		perform(Q, moves[1][i]);
	}
	for (int i=0; i<P.size(); i++) assert(P[i]==i+1);
	for (int i=0; i<Q.size(); i++) assert(Q[i]==i+1);
	cout<<'\n';
	return;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	//cin >> t;
	t=1;
	//cout<<'\n';
	while (t--)
	{
		solve();
	}
	return 0;
}