#include<iostream>
using namespace std;
const int N = 2e6 + 10;
int n , p[N] , nxt[N][30];
string s, t;
char gc(int pos) {
	if (pos < n) return t[pos];
	else return s[pos - n];
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out"."w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	n = t.size();
	int q;
	cin >> q;
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && t[i] != t[j])
			j = p[j - 1];
		if (t[i] == t[j]) j++;
		p[i] = j;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (t[i] == (j + 'a'))
				nxt[i][j] = i;
			else if (i)
				nxt[i][j] = nxt[p[i - 1]][j];
		}
	}
	while(q --){
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			int x = i + n;
			int j = p[x - 1];
			while (j > 0 && s[i] != gc(j)) {
				if (j < n) {
					j = nxt[p[j - 1]][s[i] - 'a'];
				} else j = p[j - 1];
			}
			if (s[i] == gc(j)) j++;
			p[x] = j;
			cout << p[x] << " ";
		}
		for (int i = 0; i < len; i++) {
			p[i + n] = 0;
		}
		cout << "\n";
	}
}