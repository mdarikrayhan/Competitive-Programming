#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
	int n; cin>>n;
	string s1,s2; cin>>s1>>s2;
	int x=0,y=0,k=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='1') x++;
		else x--;
		if(s2[i]=='1') y++;
		else y--;
		if(x!=y&&x!=-y){k=1; break;}}
	 if(k||x!=y) cout<<"NO"; else cout<<"YES";
	 cout<<endl;}
}