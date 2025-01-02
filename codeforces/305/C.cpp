#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	map<ll, ll> pd;
	ll n; cin >> n;
	for(ll i = 0, vl; i < n; pd[vl]++, i++)
		cin >> vl;
	vector<ll> apaga;
	for(auto &[i, j] : pd){
		if(j > 1){
			pd[i + 1] += (j / 2);
			j %= 2;
			if(!j)
				apaga.push_back(i);
		}
	}
	for(ll i : apaga)
		pd.erase(i);
	auto p = *pd.rbegin();
	cout << p.first + 1 - pd.size() << "\n";
}