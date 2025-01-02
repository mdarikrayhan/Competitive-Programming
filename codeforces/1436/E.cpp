

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



struct node
{
	ll val;
};

struct segtree
{
	int size;
	vector<struct node> values;
	// initial here
	struct node empty_node = {(ll)inf};

	void init(int n)
	{
		size = 1;
		while(size < n) size*=2;
		values.assign(2*size , empty_node);
	}

	struct node merge(struct node p1 , struct node p2)
	{
		struct node merge_node;
		// operation here
		merge_node.val = min(p1.val , p2.val);
		return merge_node;
	}

	void set(int i , ll v , int x , int  lx , int rx)
	{
		if(rx  - lx == 1)
		{
			values[x].val = v;
			return;
		}

		int m = (lx + rx)/2;
		if( i < m)
		{
			set(i , v , 2*x + 1 , lx , m);
		}
		else
		{
			set(i , v , 2*x + 2 , m , rx);
		}

		values[x] = merge(values[2*x+1] , values[2*x+2]);
	}

	void set(int i , ll v)
	{
		set(i , v, 0 , 0 , size);
	}

	struct node range_calc(int l , int r , int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return empty_node;
		if(l <= lx && r >= rx) return values[x];
		int m = (lx + rx)/2;

		struct node s1 = range_calc(l , r , 2*x+1 , lx , m);
		struct node s2 = range_calc(l , r , 2*x+2 , m , rx);
		
		return merge(s1 , s2);
	}
	ll range_calc(int l , int r)
	{
		return range_calc(l , r , 0 , 0 , size).val;
	}


};



void solve()
{
	ll n;
	cin >> n;
	vl a(n);
	for(int i =  0 ; i < n ; i ++)
	{
		cin >> a[i];
	}

	segtree ss;
	ss.init(n+5);

	for(int i = 0 ; i <= n+4 ; i ++) ss.set(i,-1);
	set<ll> ms;

	for(int i = 0 ; i < n ; i ++)
	{
		if(a[i] > 1)
		{
			ll v = ss.range_calc(1 , a[i]);
			ll past = ss.range_calc(a[i] , a[i]+1);

			if(past < v)
			{
				ms.insert(a[i]);
			}
			ms.insert(1);
		}

		ss.set(a[i] , i);
	}

	for(int x = 2 ; x <= n+1 ; x ++)
	{
		ll v = ss.range_calc(1 , x);
		ll past = ss.range_calc(x , x+1);

		if(past < v)
		{
			ms.insert(x);
		}
	}

	//print(ms);

	ll ans = 1;
	for(ll x : ms)
	{
		if(x==ans)ans++;
		else break;
	}

	cout << ans << endl;

	
}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	int t=1;
	//cin>>t;

	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}



