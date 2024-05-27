#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	string str;
	cin >> str;
	int len = str.length();
	vector<int> vis(26,0);	
	vector<int> pos;
	for (int i = 0; i < len; i++) {
		if (str[i] == '*') pos.push_back(i);
		else {
			if (!vis[str[i] - 'a']) vis[str[i] - 'a']++;
		}
	}
	cin >> m;	
	vector<bool> mark(m + 1,false);
	vector<string> ss(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> ss[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < len; j++)
			if (str[j] != '*' && str[j] != ss[i][j]) {
				mark[i] = true;

				break;
			}
	}
	int se = pos.size();
	vector<bool> mark2(m + 1,false);
	for (int i = 0; i < m; i++) {
		if (mark[i]) continue;
		else {
			int t = 0;
			for (int j = 0; j < se; j++) {
				if (vis[ss[i][pos[j]] - 'a']) t++;
			}
			if (t) mark2[i] = true;
		}
	}
	int ans = 0;
		for (int i = 0; i < 26; i++) {
			if (vis[i]) continue;
			else {
				bool ok = true;
				for (int j = 0; j < m; j++) {
					if (mark[j] || mark2[j]) continue;
					bool flag = false;
					for (int k = 0; k < se; k++) {
						int p = pos[k];
						if (ss[j][p] - 'a' == i) {
							flag = true;
							break;
						}
					}
					if (!flag) ok = false;
				}
				if (ok) ans++;
			}
		}
		cout << ans << endl;
	
}
  	 	   			 	 	 				  			  	  	