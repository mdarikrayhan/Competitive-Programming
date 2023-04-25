#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s[1]=='a') cout<<s[0]<<' '<<s[1]<<' '<<s.substr(2,s.size()-2)<<endl;
		else cout<<s[0]<<' '<<s.substr(1,s.size()-2)<<' '<<s[s.size()-1]<<endl;
	}
}