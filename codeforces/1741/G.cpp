#include<bits/stdc++.h>

using namespace std;

vector<int> H, ord;
vector<vector<int>> gr;
int ans;

bool fil(int x){
	if(H[x]){
		H[x]--;
		return 1;
	}
	for(auto y : gr[x]){
		if(ord[y] <= ord[x])continue;
		if(fil(y))return 1;
	}
	return 0;
}
void fi(vector<int> per){
	int cu = per.size();
	for(auto x : per){
		if(fil(x)){
			H[x]++;
			cu--;
		}
	}
	ans = min(ans,cu);
}


void solve(){
	int n, m; cin >> n >> m;
	ans = 10;
	gr.clear();
	gr.resize(n);
	H.clear();
	H.resize(n,0);
	ord.clear();
	ord.resize(n,-1);
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b; a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	queue<pair<int,int>> Q;
	Q.emplace(0,0);
	while(Q.size()){
		int d = Q.front().second;
		int u = Q.front().first;
		Q.pop();
		if(ord[u] != -1)continue;
		ord[u] = d;
		for(auto y : gr[u])Q.emplace(y,d+1);
	}
	int f; cin >> f;
	vector<int> INI;
	vector<int> person(f);
	for(int i = 0; i < f; ++i){
		int x; cin >> x;
		x--;
		person[i] = x;
		H[x]++;
	}
	INI = H;
	int k; cin >> k;
	vector<int> per(k);
	for(auto &x : per)cin >> x, x = person[x-1], H[x]--;
	INI = H;
	sort(per.begin(),per.end());
	do {
		H = INI;
		fi(per);
	}while(next_permutation(per.begin(),per.end()));
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}