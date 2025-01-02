// LUOGU_RID: 154788544
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n=0;
string s; 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A') n++;
		else if(s[i]=='1') n+=10;
		else n+=s[i]-'0'; 
	}
	cout<<n<<'\n';
}
