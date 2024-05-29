#include<bits/stdc++.h>
using namespace std;
typedef int ll;
vector<ll> pre(1000, -1);
vector<vector<ll>> g;
vector<string> nome;

ll dfs(ll at, ll pre, map<string, ll> &mp){
	ll re = 0;
	for(ll i : g[at]) if(i != pre){
		map<string, ll> ax;
		re += dfs(i, at, ax);
		for(auto [x, y] : ax){
			mp[x] += y;
		}
	}
	re += mp[nome[at]];
	mp[nome[at]]++;
	return re;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string e, f; cin >> e;
	stack<ll> pai;
	for(char c : e){
		if(isupper(c)){
			f += c;
		}else{
			if(f.size()) pai.push(nome.size());
			if(f.size()) nome.push_back(f);
			if(c == ':'){
				f = "";
			}else if(c == '.'){
				ll a = pai.top(); pai.pop();
				if(pai.size())
					pre[a] = pai.top();
				f = "";
			}else{
				continue;
			}
		}
	}	
	ll n = nome.size();
	pre.resize(n), g.resize(n);
	for(ll i = 1; i < n; i++)
		g[pre[i]].push_back(i);
	map<string, ll> ax;
	ll re = dfs(0, -1, ax);
	cout << re;
}