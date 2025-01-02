#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0; i<n; i++) cin>>s[i];
	string res = s[0];
	if(n == 1){
		for(int i=0; i<s[0].size(); i++){
			if(res[i] == '?') res[i] = 'c';
		}
	}
	for(int i=0; i<s[0].size(); i++){
		for(int j=1; j<n; j++){
			char k = res[i];
			if(k == '?' && s[j][i] != '?') res[i] = s[j][i];
			else if(k == '?' && s[j][i] == '?' && j==(n-1)) res[i] = 'x';
			else if(k == '?' && s[j][i] == '?' && j<(n-1)) res[i] = k;
			else if(k != '?' && s[j][i] != '?' && res[i] == s[j][i]) res[i] = res[i];
			else if(k != '?' && s[j][i] != '?'&& res[i] != s[j][i]) {
				res[i] = '?';
				break;
			}
			else if(k != '?' && s[j][i] == '?') res[i] = res[i];
		}
	}
	cout<<res;
}