#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;cin>>T;
	while(T--) {
		set<char> S;
		string s;cin>>s;
		for(auto c:s) {
			S.insert(c);
		}
		int flg=1;
		for(int i=0;i<(int)s.size();i++) {
			if(s[i]!=s[i%S.size()]) flg=0;
		}
		if(flg) puts("YES");else puts("NO");
	}
}