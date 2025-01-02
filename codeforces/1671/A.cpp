#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		if(s[0]=='a')s='b'+s;
		else s='a'+s;
		if(s[s.size()-1]=='a')s+='b';
		else s+='a';
		if(s.find("aba")!=s.npos||s.find("bab")!=s.npos)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}