#include <iostream>
#include <vector>
#include <string>

using namespace std; typedef long long ll;

int main()
{
	int n; cin >> n; string s, s1 = "lala.", s2 = "miao."; bool c1, c2;

	for (int hehe = 0; hehe < n + 1; hehe++) {

		getline(cin, s);
		if (s == "") { continue; }
		//cout << "s: " << s << endl; cout << "pu" << endl;
		if (s.size() < 5) { cout << "OMG>.< I don't know!" << endl; continue; }

		c1 = true; c2 = true;
		for (int i = 0; i < 5; i++) {
			if (s[i] != s2[i]) { c2 = false; }
		}
		int ind = 0;
		for (int i = s.size() - 5; i < s.size(); i++) {
			if (s[i] != s1[ind]) { c1 = false; } ind++;
		}
		if ((c1 && c2) || !(c1 || c2)) { cout << "OMG>.< I don't know!"; }
		else if (c1) { cout << "Freda's"; }
		else if (c2) {cout << "Rainbow's"; }

		cout << endl;
	}
}