#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int t,n,x,y,u,v, o;
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int, int>> e;
		map<pair<int, int>, int> ncfbjdh;
		o=0;
		for(int i=0; i<n; i++){
			cin>>x>>y>>u>>v;
			if(u==x){
				e.push_back({0, (v-y)/abs(v-y)});
			}
			else if(v==y){
				e.push_back({(u-x)/abs(u-x), 0});
			}
			else{
				//cout<<u-x<<" "<<__gcd(u-x, v-y)<<" "<<v-y<<+"\n";
				e.push_back({(u-x)/abs(__gcd(u-x, v-y)), (v-y)/abs(__gcd(u-x, v-y))});
			}
			//cout<<e[i].first<<" "<<e[i].second<<"\n";
			o+=ncfbjdh[{-e[i].first, -e[i].second}];
			ncfbjdh[{e[i].first, e[i].second}]++;
		}
		cout<<o<<"\n";
	}
	return 0;
}