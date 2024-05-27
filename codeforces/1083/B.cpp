#include<bits/stdc++.h>
using namespace std;
#define li long long
li n,k,res=0,now=1;
string s,t;
int main(){
	cin>>n>>k>>s>>t;
	for(int i=0;i<n;i++){
	now=now*2;
	if(s[i]=='b')now--;if(t[i]=='a')now--;
	now=min(now,k+1);
	res+=min(now,k);
	}
	cout<<res;
	return 0;	
}