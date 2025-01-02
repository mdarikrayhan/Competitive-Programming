#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define ll long long
#define ar array

//#define endl '\n'

const ll N = 5e5 + 20;
const ll MOD = 998244353;
const ll INF = 1e9;
const ll LOG = 20;

int P(int a,int b){
	int ans = 1;
	while(b){
		if(b % 2)ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return ans;
}
int n, m, L[N], R[N], A[N],fact[N], ifact[N];

vector<int>order;

void dfs(int x){
	if(L[x] != -1)dfs(L[x]);
	order.push_back(x);
	if(R[x] != -1)dfs(R[x]);
}

int BC(int n,int k){
	if(k > n)return 0;
	if(k == n)return 1;
	int ans = 1;
	for(int i = 0;i<k;i++, n--){
		ans = (n * ans) % MOD;
	}
	return (ans * ifact[k] ) % MOD;
}

void VladiDadi(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int l, r, v;
		cin>>l>>r>>v;
		if(l != -1)l--;
		if(r != -1)r--;
		L[i] = l;
		R[i] = r;
		A[i] = v;
	}
	order.clear();
	dfs(0);
	int prev = -1;
	int ans = 1;
	
	for(int i = 0;i<n;i++){
		int u = order[i];
		if(A[u] == -1)continue;
		if(prev == -1){
			int l = 1;
			int r = A[u];
			int len = i;
			ans = (ans * BC(r - l + len, len)) % MOD;
		}else{
			int l = A[order[prev]];
			int r = A[u];
			int len = i - prev - 1;
			ans = (ans * BC(r - l + len, len)) % MOD;
		}
		prev = i;
	}
	if(prev != -1){
		int l = A[order[prev]];
		int r = m;
		int len = n - prev - 1;
		ans = (ans * BC(r - l + len, len)) % MOD;
	}else ans = (ans * BC(m - 1 + n, n)) % MOD;
	cout<<ans<<endl;
}



signed main(){
	fact[0] = ifact[0] = 1;
	for(int i = 1;i<N;i++){
		fact[i] = (fact[i-1] * i) % MOD;
		ifact[i] = P(fact[i], MOD - 2);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--)
	VladiDadi();
}