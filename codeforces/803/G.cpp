

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
	ll assign;
	ll mini;
};
 
 
struct segtree
{
	int size;
	vector<struct node> operations;
 
	struct node defval = {-1ll , (ll)inf};
		
	void init(int n)
	{
		size = 1;
		while(size < n) size*=2;
		operations.assign(2*size , defval);
	}

 	
 	struct node merge(struct node x ,struct node y)
 	{
 		struct node mergenode;
 		mergenode.mini = min(x.mini , y.mini);
 		mergenode.assign = -1;
 		return mergenode;
 	}

	struct node apply_operation(struct node x , struct node y)
	{
		struct node res = x;
		// y is parent , res is child
		if(y.assign != -1) res.assign = y.assign;
		return res;
	}
 
	void propagation(int x , int lx , int rx)
	{
		if(rx - lx == 1) 
		{
			// relax all lazy operations
			if(operations[x].assign != -1)
				operations[x].mini = operations[x].assign;
			operations[x].assign = -1;

			return;
		}
		else
		{
			operations[2*x+1] = apply_operation(operations[2*x+1] , operations[x]);
			operations[2*x+2] = apply_operation(operations[2*x+2] , operations[x]);
			
			// relax all lazy operations

			if(operations[x].assign != -1)
				operations[x].mini = operations[x].assign;
			operations[x].assign = -1;

		}
	}
 
	
 
	void range_update(int l , int r ,ll v, int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return ;
		propagation(x , lx , rx);
 
		if(l <= lx && r >= rx)
		{
			operations[x].assign = v;
			propagation(x , lx , rx);
			return;
		}
 
		int m = (lx + rx)/2;
		range_update(l , r , v , 2*x+1 , lx , m);
		range_update(l , r , v , 2*x+2 , m , rx);
 
		propagation(2*x+1 , lx , m);
		propagation(2*x+2 , m , rx);

		operations[x] = merge(operations[2*x+1] , operations[2*x+2]);
 
	}
	void range_update(int l , int r , ll v)
	{
		range_update(l , r  , v, 0 , 0 , size);
	}
 
	struct node range_calc(int l , int r , int x , int lx , int rx)
	{
		propagation(x , lx , rx);
		if(lx >= r || l >= rx) return defval;
 
		if(l <= lx && r >= rx)
		{
			return operations[x];
		}
 
		int m = (lx + rx)/2;
		// calculate

		propagation(2*x+1 , lx , m);
		propagation(2*x+2 , m , rx);

		operations[x] = merge(operations[2*x+1] , operations[2*x+2]);
		return merge(range_calc(l , r , 2*x+1 , lx , m) , range_calc(l , r , 2*x+2 , m , rx));
	}
 
	struct node range_calc(int l , int r)
	{
		return range_calc(l , r , 0 , 0 , size);
	}
};



void solve()
{
	ll n , k;
	cin >> n >> k;

	vl a(n);
	for(int i =  0 ; i < n ; i ++)
	{
		cin >> a[i];
	}

	segtree ss1;
	ss1.init(n);

	for(int i = 0 ; i < n ; i ++)
	{
		ss1.range_update(i  , i+1 , a[i]);
	}

	int q;
	cin >> q;

	vector<vl> query;
	set<int>cord;

	while(q--)
	{
		int ty;
		cin >> ty;
		if(ty == 1)
		{
			ll l , r , v;
			cin >> l >> r >> v;
			l--;
			cord.insert(l);
			cord.insert(r);
			query.pb({1 , l , r , v});
		}
		else
		{
			ll l , r ;
			cin >> l >> r;
			l--;
			cord.insert(l);
			cord.insert(r);
			query.pb({2 , l , r});
		}
	}

	cord.insert(0);
	cord.insert(n*k);
	vl ptt;
	map<ll , ll> encode;
	ll cnt = 0;		
	for(ll x : cord)
	{
		ptt.pb(x);
		encode[x] = cnt++;
	}

	segtree ss2;
	ss2.init(cnt+3);


	for(int i = 0 ; i < ptt.size()-1 ; i ++)
	{
		ll lx = ptt[i];
		ll rx = ptt[i+1];
		ll ans = inf;

		if(rx - lx >= n)
		{
			ans = ss1.range_calc(0 , n).mini;
		}  
		else
		{
			lx = lx%n;
			rx = rx%n;

			if(lx < rx)
			{
				ans = ss1.range_calc(lx , rx).mini;
			}
			else
			{
				ans = min(ss1.range_calc(lx , n).mini , ss1.range_calc(0, rx).mini);
			}
		}

		ss2.range_update(i , i+1 , ans);
	}

	for(vl qq : query)
	{
		ll lx , rx;
		ll ty = qq[0];
		lx = qq[1];
		rx = qq[2];


		if(ty == 1)
		{
			ll v = qq[3];
			ss2.range_update(encode[lx] , encode[rx] , v);
		}
		else
		{
			cout << ss2.range_calc(encode[lx] , encode[rx]).mini << endl;
		}
	}

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



