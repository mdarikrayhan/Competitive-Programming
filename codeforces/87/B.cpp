#include <bits/stdc++.h>
using namespace std;
int n;
string op, a, b;
map<string, pair<int, bool> > mp;
int main(){
	mp["void"] = make_pair(0, 1);
	scanf("%d", &n);
	while(n--){
		cin >> op >> a;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < a.size(); i++){
			cnt1 += a[i] == '&';
			cnt2 += a[i] == '*';
		}
		a = a.substr(cnt1, a.size() - cnt1 - cnt2);
		if(op == "typedef"){
			cin >> b;
			mp[b].first = mp[a].first + cnt2 - cnt1;
			if(mp[b].first < 0 || !mp[a].second)	mp[b].first = -2e9;
			mp[b].second = true;
		}else{
			if(mp[a].first < 0 || !mp[a].second || mp[a].first + cnt2 - cnt1 < 0)	printf("errtype\n");
			else{
				printf("void");
				for(int i = 1; i <= mp[a].first + cnt2 - cnt1; i++)	printf("*");
				printf("\n");
			}
		}
	}
	return 0;
}