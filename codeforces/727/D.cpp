#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	vector<int>shirtCnt(6);
	for(int i = 0; i < 6; i++) {
		cin >> shirtCnt[i];
	}
	int n;
	cin >> n;
	vector<vector<int>>uniqeCoder(6);
	vector<pair<int, int>>confusedCoder;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(s.size() == 1 || ((s.size() <= 4) && (s[0] == 'X'))) {
			if(s == "S") {
				uniqeCoder[0].push_back(i);
			}
			else if(s == "M") {
				uniqeCoder[1].push_back(i);
			}
			else if(s == "L") {
				uniqeCoder[2].push_back(i);
			}
			else if(s == "XL") {
				uniqeCoder[3].push_back(i);
			}
			else if(s == "XXL") {
				uniqeCoder[4].push_back(i);
			}
			else if(s == "XXXL") {
				uniqeCoder[5].push_back(i);
			}
		}
		else {
			if(s[0] == 'S') {
				confusedCoder.push_back({0, i});
			}
			else if(s[0] == 'M') {
				confusedCoder.push_back({1, i});
			}
			else if(s[0] == 'L') {
				confusedCoder.push_back({2, i});
			}
			else if(s.size() == 6) {
				confusedCoder.push_back({3, i});
			}
			else if(s.size() == 8) {
				confusedCoder.push_back({4, i});
			}
		}
	}
	vector<int>ans(n, -1);
	for(int i = 0; i < 6; i++) {
		if(uniqeCoder[i].size() > shirtCnt[i]) {
			cout << "NO\n";
			return 0;
		}
		for(auto it : uniqeCoder[i]) {
			ans[it] = i;
		}
		shirtCnt[i] -= uniqeCoder[i].size();
	}
	sort(confusedCoder.begin(), confusedCoder.end());
	int k = 0;
	for(auto it : confusedCoder) {
		k = max(k, it.first);
		while(shirtCnt[k] <= 0) {
			k++;
			if(k == 6) {
				cout << "NO\n";
				return 0;
			}
		}
		if((ans[it.second] == -1)) {
			if(k > (it.first+1)) {
				cout << "NO\n";
				return 0;
			}
			ans[it.second] = k;
			shirtCnt[k]--;
		}
	}
	for(int i = 0; i < n; i++) {
		if(ans[i] == -1) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(auto it : ans) {
		if(it == 0) {
			cout << "S\n";
		}
		else if(it == 1) {
			cout << "M\n";
		}
		else if(it == 2) {
			cout << "L\n";
		}
		else if(it == 3) {
			cout << "XL\n";
		}
		else if(it == 4) {
			cout << "XXL\n";
		}
		else if(it == 5) {
			cout << "XXXL\n";
		}
	}
	return 0;
}