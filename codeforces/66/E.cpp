// Problem: E. Petya and Post
// Contest: Codeforces - Codeforces Beta Round 61 (Div. 2)
// Created: 2024-05-24 23:45:17
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class SegTree{
	public:
	typedef ll Val;
	struct node{
		ll sum; Val mn, mx;
		int mncnt, mxcnt;
		void apply(Val a, int len=1){ sum=1ll*a*len; mn=mx=a; mncnt=mxcnt=len; }
	};
	int n;
	vector<node> tree;
	vector<pair<bool,Val>> upd;
	vector<Val> add;
	vector<bool> neg;
	bool isUpd, isAdd, isNeg;
	// Empty constructor
	SegTree(int n) : n(n), tree(2*n-1){
		isUpd=isAdd=isNeg=false;
		vector<Val> v(n);
		build(0, 0, n-1, v);
	}
	void init_lazy_assign();
	void init_lazy_add();
	void init_lazy_negate();
	// Build a segtree from a vector
	SegTree(const vector<Val> &v) : n(v.size()){
		isUpd=isAdd=isNeg=false;
		tree.resize(2*n-1);
		build(0, 0, n-1, v);
	}
	// Update nums[i] = a
	void update(int i, Val a){
		assert(0 <= i && i < n);
		update(0, 0, n-1, i, a);
	}
	void update(int x, int tl, int tr, int i, Val a){
		push(x,tl,tr);
		if(tl == tr){
			tree[x].apply(a);
			return;
		}
		int tm = (tl+tr)/2;
		int z = x + ((tm - tl + 1) << 1);
		if(i <= tm) update(x+1, tl, tm, i, a), push(z,tm+1,tr);
		else update(z, tm+1, tr, i, a), push(x+1,tl,tm);
		pull(x,z);
	}
	// Get {sum, min, max, counts} on interval [l,r]
	node query(int l, int r){
		assert(0 <= l && l <= r && r < n);
		return get(0, 0, n-1, l, r);
	}
	// Get value at index p
	Val get(int p){
		assert(0 <= p && p < n);
		return get(0, 0, n-1, p, p).mn;
	}
	node get(int x, int tl, int tr, int l, int r){
		push(x,tl,tr);
		if(l <= tl && tr <= r){
			return tree[x];
		}
		int tm = (tl+tr)/2;
		int z = x + ((tm - tl + 1) << 1);
		node res{};
		if(r <= tm) res = get(x+1, tl, tm, l, r), push(z,tm+1,tr);
		else if(l > tm) res = get(z, tm+1, tr, l, r), push(x+1,tl,tm);
		else res = unite(get(x+1, tl, tm, l, r), get(z, tm+1, tr, l, r));
		pull(x,z);
		return res;
	}
	void update_range(int l, int r, Val a);
	void update_range(int x, int tl, int tr, int l, int r, Val a);
	void add_range(int l, int r, Val a);
	void add_range(int x, int tl, int tr, int l, int r, Val a);
	void negate(int l, int r);
	void negate(int x, int tl, int tr, int l, int r);
	int find_first(int l, int r, Val a);
	int find_first(int x, int tl, int tr, int l, int r, Val a);
	int find_last(int l, int r, Val a);
	int find_last(int x, int tl, int tr, int l, int r, Val a);
	int find_prefix(Val a);
	int find_prefix(Val a, int x, int tl, int tr);
	// -----------------
	private:
	node unite(const node &a, const node &b) const {
		node res;
		res.sum = a.sum + b.sum;
		if(a.mn < b.mn) res.mn = a.mn, res.mncnt = a.mncnt;
		else if(b.mn < a.mn) res.mn = b.mn, res.mncnt = b.mncnt;
		else res.mn = a.mn, res.mncnt = a.mncnt + b.mncnt;
		if(a.mx > b.mx) res.mx = a.mx, res.mxcnt = a.mxcnt;
		else if(b.mx > a.mx) res.mx = b.mx, res.mxcnt = b.mxcnt;
		else res.mx = a.mx, res.mxcnt = a.mxcnt + b.mxcnt;
		return res;
	}
	void build(int x, int tl, int tr, const vector<Val> &v){
		if(tl==tr){
			tree[x].apply(v[tl]);
			return;
		}
		int tm = (tl+tr)/2;
		int z = x + ((tm - tl + 1) << 1);
		build(x+1, tl, tm, v);
		build(z, tm+1, tr, v);
		pull(x,z);
	}
	inline void pull(int x, int z){
		tree[x] = unite(tree[x+1], tree[z]);
	}
	void push(int x, int tl, int tr){
		if(isUpd) pushUpd(x,tl,tr);
		if(isAdd) pushAdd(x,tl,tr);
		if(isNeg) pushNeg(x,tl,tr);
	}
	void pushUpd(int x, int tl, int tr){}
	void pushAdd(int v, int tl, int tr);
	void pushNeg(int v, int tl, int tr){}
};
void SegTree::init_lazy_add(){
	isAdd = true;
	add.resize(2*n-1);
}
// Add a to nums[l..r]
void SegTree::add_range(int l, int r, Val a){
	assert(isAdd);
	assert(0 <= l && l <= r && r < n);
	if(a) add_range(0, 0, n-1, l, r, a);
}
void SegTree::add_range(int x, int tl, int tr, int l, int r, Val a){
	push(x,tl,tr);
	if(l <= tl && tr <= r){
		add[x]=a;
		pushAdd(x,tl,tr);
		return;
	}
	int tm = (tl+tr)/2;
	int z = x + ((tm - tl + 1) << 1);
	if(l <= tm) add_range(x+1, tl, tm, l, r, a);
	else push(x+1,tl,tm);
	if(r > tm) add_range(z, tm+1, tr, l, r, a);
	else push(z,tm+1,tr);
	pull(x,z);
}
void SegTree::pushAdd(int x, int tl, int tr){
	if(add[x]){
		Val K = add[x];
		tree[x].mn += K;
		tree[x].mx += K;
		tree[x].sum += 1ll*(tr-tl+1)*K;
		if(tl != tr){
			int tm = (tl+tr)/2;
			int z = x + ((tm - tl + 1) << 1);
			if(isNeg) pushNeg(x+1,tl,tm), pushNeg(z,tm+1,tr);
			add[x+1] += K;
			add[z] += K;
		}
		add[x] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(auto &d : a) cin >> d;
	for(auto &d : b) cin >> d;
	SegTree st1(2*n), st2(2*n);
	st1.init_lazy_add();
	st2.init_lazy_add();
	vector<int> ans(n);
	for(int i=2*n-1; i>=0; i--){
	    st1.add_range(i, min(i+n-1, 2*n-1), a[i%n]-b[i%n]);
	    if(i<n && st1.query(i, i+n-1).mn >= 0) ans[i] = 1;
	}
	int ja=n-1, jb=max(0, n-2);
	for(int i=2*n-1; i>=0; i--){
	    st2.add_range(i, min(i+n-1, 2*n-1), a[ja]-b[jb]);
	    // for(int j=0; j<2*n; j++){
	        // cout << st2.get(j) << " \n"[j+1==2*n];
	    // }
	    if(i<n && st2.query(i, i+n-1).mn >= 0){
	        ans[ja] = 1;
	        // cout << ja << " is ok\n";
	    }
	    ja=(ja+1)%n;
	    jb=(jb+1)%n;
	}
	vector<int> res;
	for(int i=0; i<n; i++){
	    if(ans[i]) res.push_back(i+1);
	}
	cout << res.size() << endl;
	for(auto d : res) cout << d << ' ';
	
}