#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#define task ""
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6 + 2;
int u[N], v[N];
vector<int> edge[N];
vector<pair<int*, int>> snap;
int n, m, par[N];
int ans[N];

void Read(){
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		cin >> u[i] >> v[i];
		int w;
		cin >> w;
		edge[w].push_back(i);
	}
	memset(par, -1, sizeof par);
}

int findpar(int v){
	return par[v] < 0 ? v : findpar(par[v]);
}

void update(int &x, int y){
	snap.push_back({&x, x});
	x = y;
}

void rollback(int tmp){
	while(snap.size() > tmp){
		auto &u = snap.back();
		*u.first = u.second;
		snap.pop_back();
	}
}

void Merge(int u, int v){
	int x = findpar(u), y = findpar(v);
	if(x == y)
		return;
	if(par[x] < par[y])
		swap(x, y);
	update(par[y], par[x] + par[y]);
	update(par[x], y);
}

void Resolve(int l, int r, vector<int> &edge){
	if(l > r)
		return;
	if(l == r){
		int x = findpar(u[edge[l]]), y = findpar(v[edge[l]]);
		if(x != y)
			ans[edge[l]] = 2;
		return;
	}
	int tmp = snap.size();
	int mid = (l + r) / 2;
	for(int i = l; i <= mid; ++i)
		Merge(u[edge[i]], v[edge[i]]);
	Resolve(mid + 1, r, edge);
	rollback(tmp);
	for(int i = mid + 1; i <= r; ++i)
		Merge(u[edge[i]], v[edge[i]]);
	Resolve(l, mid, edge);
	rollback(tmp);
}

void Solve(){
	for(int i = 1; i < N; ++i){
		for(auto &j : edge[i]){
			int x = findpar(u[j]), y = findpar(v[j]);
			if(x != y)
				ans[j] = 1;
		}
		/// De qui sieu mup cua thu khoa Tran Quang Thanh (Khong co cai nay t do ai rollback duoc =)))
		Resolve(0, (int)edge[i].size() - 1, edge[i]);
		///
		for(auto &j : edge[i])
			Merge(u[j], v[j]);
	}
	for(int i = 1; i <= m; ++i)
		cout << (ans[i] == 1 ? "at least one" : (ans[i] == 2 ? "any" : "none")) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); if(fopen(task".INP", "r"))
	freopen(task".INP", "r", stdin),
	freopen(task".OUT", "w", stdout);
	Read();
	Solve();
}
	  	  	 			  	 	   		 	 		   	