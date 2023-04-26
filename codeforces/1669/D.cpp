#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	cin>>T;
	while(T--){
		int n;
		string s,ans="YES\n";
		cin>>n>>s;s+='W';
		int sz=0,ok=0;
		for(int i=0;i<=n;i++)
			if(s[i]=='W'){
				if(sz&&!ok)ans="NO\n";
				sz=0;ok=0;
			}else{
				sz++;
				if(i&&s[i-1]-'B'=='R'-s[i])
					ok=1;
			}
		cout<<ans;
	}
}