// Hydro submission #6651dd83f56b336a8b641618@1716641155192
#include <cstring>
#include<iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	if(s[0] == '@'||s[(int)s.size()-1] == '@'||s.find('@')==string::npos){//the power of Melania Ramirez
            cout<<"No solution";return 0;
    }
	int pos = 0;
	for(int i = 0;i < s.size();i ++){
		if(s[i] == '@'){
			if(pos == 0){ pos = i; }
			else if(i-pos < 3){ cout<<"No solution";return 0; }
			else {pos = i;}
		}
	}
	for(int i = 0;i < s.size();i ++){
		cout << s[i];
		if(s[i] == '@'){
			cout << s[i+1];
			if(pos != i)cout << ',';
			i++;
		}
	}
	return 0;
}
