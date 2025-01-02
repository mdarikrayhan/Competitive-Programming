// LUOGU_RID: 159131455
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	string s[n];
	string str1 = "vika";
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int d = 0;
	char c;
	for(int j = 0; j < m; j++){
		c = str1[d];
		for(int i = 0; i < n; i++){
			if(s[i][j] == c){
				d++;
				break;
			}
		}
		if(d == 4){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
	return;
	
} 

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}