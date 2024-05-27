#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define el "\n"
#define pb push_back
#define all(x) x.begin(),x.end()
ll mod=1e9+7;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
 
 
 
 
void fast(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 




int main(){
	#ifndef ONLINE_JUDGE
	freopen("INPUT.inp","r",stdin);
	freopen("OUTPUT.out","w",stdout);
	#endif 
	fast();
	ll a,b,r; cin>>a>>b>>r;
	if(a==0){
		cout<<2; return 0;
	}
	ll x=1000000000;
	x=x%r;
	for(int i=1;i<r&&i<=a;++i){
		ll res=(i*x)%r;
		ll j=r-res;
		if(res!=0&&j>b){
			cout<<1<<" ";
			string s=to_string(i);
			for(int k=0;k<9-s.size();++k) cout<<0;
			cout<<i;
			return 0;
		}

	}
	cout<<2;
}


