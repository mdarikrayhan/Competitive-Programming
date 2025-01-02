// LUOGU_RID: 160064079
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,ss;
bool p=0;
void dfs(int x,int c0,int c1){
	if(ss<s) return;
	if(x==s.size()&&c0==c1&&ss>=s){
		cout<<ss;
		exit(0);
	}
	if(c0<s.size()/2){
		ss[x]='4';
		dfs(x+1,c0+1,c1);
		ss[x]='9';
	}
	if(c1<s.size()/2){
		ss[x]='7';
		dfs(x+1,c0,c1+1);
		ss[x]='9';
	}
}
signed main(){
	cin>>s;
	if(s.size()%2==1){
		for(int i=1;i<=s.size()/2+1;i++) cout<<4;
		for(int i=1;i<=s.size()/2+1;i++) cout<<7;
	}else{
		for(int i=1;i<=s.size();i++) ss+="9";
		dfs(0,0,0);
		for(int i=1;i<=s.size()/2+1;i++) cout<<4;
		for(int i=1;i<=s.size()/2+1;i++) cout<<7;
	}
	return 0;
} 