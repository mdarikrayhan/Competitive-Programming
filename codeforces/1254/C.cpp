

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


ll query2(ll x , ll y , ll z)
{
	cout << 2 << " " << x << " " << y << " " << z << endl;
	cout.flush();
	ll v;
	cin >> v;
	return v;
}


ll query1(ll x , ll y , ll z)
{
	cout << 1 << " " << x << " " << y << " " << z << endl;
	cout.flush();
	ll v;
	cin >> v;
	return v;
}


void solve()
{
	ll n;
	cin >> n;

	ll second = 2;

	for(ll guy = 3 ; guy <= n ; guy++)
	{
		if(query2(1 , second , guy) == -1)
		{
			second = guy;
		}
	}



	vl p = {1 , second};

	vl leftout;

	for(ll i = 1 ; i <= n ; i ++)
	{
		if(i == 1 || i == second) continue;
		leftout.pb(i);
	}

	map<ll , ll> h;
	h[1] = 0;
	h[second] = 0;
	ll maxi = 0;

	for(ll k : leftout)
	{
		ll area = query1(1 , second , k);
		h[k] = area;

		ll i1 = -1 , i2 = -1;

		for(ll i = 0 ; i < p.size() ; i ++)
		{
			ll low = h[p[i]];
			ll high = h[p[(i+1)%p.size()]];

			if(low <= area && area <= high)
			{
				i1 = i;
			}
			else if(high <= area && area <= low)
			{
				i2 = i;
			}
		}

		if((i1 == -1) && (i2 == -1))
		{
			for(ll i = 0 ; i < p.size() ; i ++)
			{
				if( h[p[i]] == maxi)
				{
					i1 = i;
					i2 = i-1;

					i1 %= p.size();
					i2 %= p.size();
					i1 += p.size();
					i2 += p.size();
					i1 %= p.size();
					i2 %= p.size();	
				
					break;
				}
			}
		}


		if((i2 != -1) && query2(p[i2] , k , p[(i2+1)%p.size()]) == 1)
		{
			i1 = i2;
		}

		p.pb(k);


		if(i1 != -1 && p.size() > 3)
		{
			for(ll j = p.size()-1 ; j >= i1 + 2; j --)
			{
				swap(p[j] , p[j-1]);
			}
		}

		maxi = max(maxi , h[k]);
	}


	cout << 0 << " ";
	print(p);
	cout.flush();

}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r" , stdin);
	// 	freopen("output.txt", "w" , stdout);
	// #endif

	int t=1;
	//cin>>t;

	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}



