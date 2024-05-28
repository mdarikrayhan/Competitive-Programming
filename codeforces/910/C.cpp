#include <bits/stdc++.h>
using namespace std;

#define ll long long int




void solve(){
	int n;cin>>n;
	map<char, ll>m;
	vector<string>ar;
	for(int i=0;i<n; i++){
		string s;cin>>s;
		int cur = 1;
		for(int j=0; j<s.size(); j++){
			m[s[s.size()-j-1]]+=cur;
			cur*=10;
		}
		ar.push_back(s);
	}

	vector<pair<int,char>>arr;

	for(auto e: m){
		arr.push_back({e.second, e.first});
	}

	sort(arr.begin(), arr.end());
	ll ans=0;

	bool g=1;
	int it=1;
	for(int i=0;i<arr.size(); i++){
		bool q =0;
		for(auto e: ar){
			if(arr[arr.size()-1-i].second==e[0])q=1;
		}
		if(!q and g){
			g=0;
			continue;
		}
		ans += arr[arr.size()-1-i].first * (it);
		it++;
	}
	cout << ans;


}
 
int main() {
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
 	    	  			 				   	 	   	