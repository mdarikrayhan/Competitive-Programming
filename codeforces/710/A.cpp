#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	if (s == "a8" || s == "h8" || s == "a1" || s == "h1") {
		cout << 3;
		return 0;
	}
	if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8') {
		cout << 5;
		return 0;
	}
	cout << 8;
	return 0;
}
