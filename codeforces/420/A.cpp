# include <bits/stdc++.h>
using namespace std;

int main () {
	int len, t=0;
        string s;
	cin >> s;
	len = s.length();
        char sRev[len];
	for (int i=len-1; i>=0; i--) {
		sRev[(len-1)-i] = s[i];
	}
	for (int i=0; i<len; i++) {
		if (sRev[i] != s[i]) {
			t++;
			break;
		}
	}
	for (int i=0; i<len; i++) {
		t++;
		if (s[i] == 'A' || s[i] == 'H' || s[i] == 'I' || s[i] == 'M' || s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'X' || s[i] == 'Y') {
			t--;
		}
	}
	if (t == 0) cout << "YES";
	else cout << "NO";
}
 			 	 	 			 	 	 					   	 	 	