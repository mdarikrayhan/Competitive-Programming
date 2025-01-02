

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<lli , lli>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;
typedef priority_queue<lli> pq;
typedef priority_queue<pair<lli,lli>> pqp;

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

void solve()
{
	
	int n , m;
	cin >> n >> m;

	int zz = 0, zo = 0, oo= 0;

	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			char x , y;
			cin >> x >> y;

			int o = 0 , z = 0;
			if(x == '0') z++;
			if(y == '0') z++;
			if(x == '1') o++;
			if(y == '1') o++;

			if(o == 0 && z == 2)
			{
				zz++;
			}
			if(o == 1 && z == 1)
			{
				zo++;
			}
			if(o == 2 && z == 0)
			{
				oo++;
			}
		}
	}


	int visit[n][m];
	int ty[n][m];


	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			visit[i][j] = -1;
			ty[i][j] = -1;
		}
	}


	/*
	 
	 1 oo
	 2 oz
	 3 zo
	 4 zz
	
	*/


	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			if(visit[i][j] == -1)
			{
				if(oo)
				{
					visit[i][j] = 1;
					ty[i][j] = 1; 
					oo--;
					continue;
				}

				if(zo)
				{
					visit[i][j] = 1;
					ty[i][j] = 2; 
					zo--;

					if(zo>=1 && i+1<n && visit[i+1][j] == -1)
					{
						visit[i+1][j] = 1;
						ty[i+1][j] = 3;
						zo--;
					}

					continue;
				}

				if(zz)
				{
					visit[i][j] = 1;
					ty[i][j] = 4;
					zz--;
					continue;
				}
			}
		}
	}


	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			if(ty[i][j] == 1){
				cout << "11 ";
			}
			if(ty[i][j] == 2){
				cout << "01 ";
			}
			if(ty[i][j] == 3){
				cout << "10 ";
			}
			if(ty[i][j] == 4){
				cout << "00 ";
			}

		}
		cout << endl;
	}


	
}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	int t=1;

	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}



