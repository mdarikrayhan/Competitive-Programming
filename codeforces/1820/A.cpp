#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t,a=0,b;
	string s;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>s;
		a=0;
		if(s[0]=='_') a=1;
		if(s.size()==1&&s[0]=='^') a=1;
		for(int j=0;j<s.size();j++){
			if(s[j]=='_'&&s[j+1]!='^') a++;
		}
		cout<<a<<endl;
	}
	
}
