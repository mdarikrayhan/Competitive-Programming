

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<ll , ll>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef priority_queue<ll> pq;
typedef priority_queue<pair<ll,ll>> pqp;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define printarr(a , n) for(int i = 0 ; i < n  ;i ++) cout << a[i] << " "; cout << endl;
#define endl '\n'
#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18

int rand(int l, int r){
 	static mt19937 
 	rng(chrono::steady_clock::now().time_since_epoch().count());
 	uniform_int_distribution<int> ludo(l, r); 
 	return ludo(rng);
}


/*
	order_of_key(x) -> number of elements strictly smaller than x
	find_by_order(k) -> kth element 

	---------------------------------------------
	Think reverse -> graph problems
	Try converting into new operation
	check what happens to prefix sums
	graph trav , scc , topo , floyd ,  .... 
	copy code check
	index bounds
	maxsz
	set low , up bound be carefull

    ----------------------------------------------------------------------
	-------------- GO THROUGH CODE ONCE BEFORE SUBMITTING ----------------
    ----------------------------------------------------------------------

    ----------------------------------------------------------------------
	-------------- TLE : INFINITE LOOP , TIGHT CONSTRAINTS ---------------
	-------------- MLE : WIERD CONSTRAINT ARRAY SIZE       ---------------
	-------------- RE : POP EMPTY STACK QUEUE, INDEX BOUNDS --------------
    ----------------------------------------------------------------------

    Things get better by time, hope for the best ......
    
*/


set<int> adjlst[300005];
int level[300005];
int visited[300005];
int sz = 0;

void dfs(int u , int lev)
{
	assert(visited[u] == 0);

	visited[u] = 1;
	level[u] = lev;
	sz++;

	for(int v: adjlst[u])
	{
		if(!visited[v])
		{
			dfs(v , lev^1);
		}
	}
}


void solve()
{
	ll n;
	cin >> n;


	for(int i = 0 ; i <= n ; i ++)
	{
		adjlst[i].clear();
		visited[i] = 0;
		level[i] = 0;
	}
	sz = 0;


	int m;
	cin >> m;


	for(int i = 0 ;i <  m ; i ++)
	{
		int u , v;
		cin >> u >> v;
		adjlst[u].insert(v);
		adjlst[v].insert(u);
	}

	dfs(1 , 0);

	if(sz == n)
	{
		for(int i = 0 ; i <= n ; i ++)
		{
			visited[i] = 0;
		}

		yes;
		vi ans;

		set<int>white;
		set<int>black;
		black.insert(1);

		while(black.size())
		{
			int god = *black.begin();
			ans.pb(god);
			visited[god] = 1;
			black.erase(god);

			for(int u : adjlst[god])
			{
				if(!visited[u])
				{
					for(int w : adjlst[u])
					{
						if(!visited[w])
						{
							black.insert(w);
						}
					}
				}
				visited[u] = 2;
				white.insert(u);
			}

			for(int u : adjlst[god])
			{
				if(black.find(u) != black.end())
				{
					black.erase(u);
				}
			}
		}


		cout << ans.size() << endl;
		print(ans);

	}	
	else
	{
		no;
	}
	
}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	int t=1;
	cin>>t;

	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}



