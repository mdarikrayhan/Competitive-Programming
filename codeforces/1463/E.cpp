

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

	Good Life Good Wife

*/

int visited[400005];
vi adjlst[400005];
vi order;

void dfs(int u)
{
	visited[u] = 1;
	for(int v: adjlst[u]) 
		if(!visited[v]) 
			dfs(v);
	order.pb(u);
}

void solve()
{
	ll n , m;
	cin >> n >> m;


	for(int i = 0 ; i <= n ;  i ++)
	{
		visited[i] = 0;
	}


	vl a(n+1);
	for(int i =  1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}


	map<int , int> grp;
	map<int , int> pre;
	vpll info;

	for(int i = 0 ;  i < m ; i ++)
	{
		ll x , y;
		cin >> x >> y;
		grp[x] = y;
		pre[y] = x;
		info.pb({x , y});
	}

	vl grps[n+5];
	int grpno[n+1];
	int gno = 1;

	for(int i = 1 ; i <= n ; i ++)
	{
		if(!visited[i])
		{
			int cnt = 0;
			int st = i;

			while(pre[st] != 0)
			{
				st = pre[st];
				cnt++;

				if(cnt > n)
				{
					cout << 0 << endl;
					return;
				}
			} 

			cnt = 0;
			vl cur;

			while(st != 0)
			{
				if(visited[st]) {
					cout << 0 << endl;
					return;
				}
				cur.pb(st);

				st = grp[st];
				cnt++;
				if(cnt > n)
				{
					cout << 0 << endl;
					return;
				}
			}

			for(int x : cur) visited[x] = 1;
			for(int x : cur) grpno[x] = gno;
			grps[gno] = cur;
			gno++;
			
		}
	}

	for(int i = 0 ; i <= gno ; i ++)
	{
		visited[i] = 0;
	}

	for(int i = 1 ; i <= n ; i ++)
	{
		if(a[i])
		{
			adjlst[grpno[a[i]]].pb(grpno[i]);
		}
	}

	gno--;

	for(int i = 1 ; i <= gno ; i ++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}

	reverse(order.begin() , order.end());
	
	vi arr;

	for(int x : order)
	{
		for(int y : grps[x])
			arr.pb(y);
	}

	int ocr[n+1];

	for(int i = 0 ; i < n ; i ++) ocr[arr[i]] = i;

	bool ok = true;

	for(int i = 1 ;  i <= n ; i ++)
	{
		if(a[i])
		{
			if(ocr[a[i]] >= ocr[i]) ok = false;
		}
	}


	for(pll kk : info)
	{
		int x = kk.first;
		int y = kk.second;
		if(ocr[x]+1 != ocr[y]) ok = false;
	}

	if(ok && arr.size() == n)
	{
		print(arr);
	}
	else
	{
		cout << 0  << endl;
	}

}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	int t=1;
//	cin>>t;

	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}



