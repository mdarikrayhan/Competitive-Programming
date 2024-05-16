#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int pre = n;
	string ans;
	int f = 0;
	for(int i = n-1;i >= 0;i --){
		if(s[i] == '0' and f == 0){
			f = 1;
			pre = i;
		}else{
			if(f > 0){
				f -= 1;
				continue;
			}
			string t = s.substr(i,pre-i);
			ans += stoi(t)+'a'-1;
			pre = i;
		}
	}
 reverse(ans.begin(),ans.end()); 
	cout <<ans<< "\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}
