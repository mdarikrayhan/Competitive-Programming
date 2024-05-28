#include<bits/stdc++.h>
using namespace std;
int main() {
	int flag = 0, id;
	string s;
	while (getline(cin, s)) {
		for (id = 0; id < s.length(); id++)
			if (s[id] != ' ')
				break;
		if (id == s.length() || s[id] != '#') {
			if (flag == 2)cout << endl;
			for (id = 0; id < s.length(); id++)
				if (s[id] != ' ')
					cout << s[id];
			flag = 1;
		} else {
			if (flag)cout << endl;
			cout << s;
			flag = 2;
		}
	}
	cout << endl;
	return 0;
}
   	  		    			 		 					 	 			