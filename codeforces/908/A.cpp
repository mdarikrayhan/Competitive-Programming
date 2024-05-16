#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int answer = 0;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if((s[i] < 'a' && s[i] % 2 == 1) || (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
			answer++;
		}
	}
	cout << answer;
	return 0;
}
