#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define len(v) (int)v.size() 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef Raptor
#include "debug.h"
#else
#define debug(...) 1
#define imie(...) 1;
#endif
//segtree<int> seg(array, [&](int i, int j){ return min(i,j); });
template <typename T, class F = function<T(const T&, const T&)>>
class segtree{
	public:
	int n;
	vector<T> tree;
	F func;

	segtree(vector<T> a,const F& f) : func(f) {
		n = static_cast<int>(a.size());
		tree.resize(2*n);
		for(int i=0;i<n;i++){
			tree[n+i] = a[i];
		}
		for(int i=n-1;i>0;i--){
			tree[i] = func(tree[2*i],tree[2*i+1]);
		}
	}
	void add(int pos, T value){
		tree[pos+n] += value;
		pos += n;
		for(int i=pos;i>1;i/=2){
			tree[i/2] = func(tree[i],tree[i^1]);
		}
	}
	void update(int pos, T value){
		tree[pos+n] = value;
		pos += n;
		for(int i=pos;i>1;i/=2){
			tree[i/2] = func(tree[i],tree[i^1]);
		}
	}
	// Function on interval [l,r)
	T get(int l, int r){
		T res = 0;
		for (l += n, r += n; l < r; l/=2 , r/=2){
			if(l&1){
				res = func(res,tree[l++]);
			}
			if(r&1){
				res = func(res,tree[--r]);
			}
		}
		return res;
	}
};
void solve(){
	ll n; cin>>n;
	vector<ll> s(n);
	for(int i=0;i<n;i++) cin>>s[i];
	vector<ll> p(n + 1);
	iota(all(p),0);
	segtree<ll> sg(p,[&](ll i, ll j){return i+j;});
	vector<ll> a(n);
	for(int i=n-1;i>=0;i--){
		int low = 1, high = n;
		while(low <= high){
			int mid = (low + high)/2;
			if(sg.get(0,mid) <= s[i]) low = mid + 1;
			else high = mid - 1;
		}
		a[i] = high;
		sg.update(a[i],0);
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	
	return 0;
}
