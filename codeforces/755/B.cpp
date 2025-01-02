#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
void authou(){
	int n,m,bol=0,enm=0,tp=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		mp[s]++;
		if(mp[s]==1)bol++;
	}
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		mp[s]++;
		if(mp[s]==2){
			tp++;
			bol--;
		}
		else if(mp[s]==1)enm++;
	}
	if(tp&1){
		if(bol>=enm)cout<<"YES\n";
		else cout<<"NO\n";
	}else{
		if(bol>enm)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main(){
	int t=1;
//	cin>>t;
	while(t--)authou();
	return 0;
}