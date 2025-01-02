// LUOGU_RID: 159699614
#include<bits/stdc++.h>
using namespace std;
int main(){	
	string s;
	cin>>s;
	int l=s.size(),cnt=0;
	for(int i=l-1;i>=0;i--){
		if(s[i]=='0') cnt++;
		else if(cnt<=0) s[i]='0';
		else cnt--;
	}
	cout<<s;
	return 0;
}
