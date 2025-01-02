#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<array<ll, 4>> suap;

void remo(vector<vector<ll>> &at){
	if(at.back().size() == 1)
		at.pop_back();
	else
		at.back().pop_back();
}

void fz(vector<vector<ll>> at, ll vl){
	if(!vl) return;
	if(at.back().back() == vl){
		remo(at);
		fz(at, vl - 1);
		return;
	}
	array<ll, 2> esse, fim;
	for(ll i = 0; i < at.size(); i++)
		for(ll j = 0; j < at[i].size(); j++){
			fim = {i, j};
			if(at[i][j] == vl)
				esse = {i, j};
		}
	suap.push_back({esse[0], esse[1], fim[0], fim[1]});
	swap(at[esse[0]][esse[1]], at[fim[0]][fim[1]]);
	remo(at);
	fz(at, vl - 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	vector<ll> c(n);
	for(ll &i : c)
		cin >> i;
	vector<vector<ll>> at(n);
	for(ll i = 0; i < n; i++){
		at[i].resize(c[i]);
		for(ll &j : at[i])
			cin >> j;
	}
	fz(at, accumulate(c.begin(), c.end(), 0ll));
	cout << suap.size() << "\n";
	for(auto [x, y, z, w] : suap)
		cout << x + 1 << " " << y + 1 << " " << z + 1 << " " << w + 1 << "\n";
}