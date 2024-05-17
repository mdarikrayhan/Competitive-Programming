// Problem: B. Binary String Constructing
// Contest: Codeforces - Codeforces Round 494 (Div. 3)
// URL: https://codeforces.com/contest/1003/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 +10;
using LL = long long;
typedef pair<int,int> PII;
void solve(){
	int a,b,x;
	cin>>a>>b>>x;
	if(x%2==0){
		if(a>b){
			for(int i=0; i<x/2; i++){
				cout<<"01";
			}
			for(int i=0; i<b-x/2; i++) cout<<'1';
			for(int i=0; i<a-x/2; i++) cout<<'0';
			cout<<'\n';
		}
		else{
			for(int i=0; i<x/2; i++){
				cout<<"10";
			}
			for(int i=0; i<a-x/2; i++) cout<<'0';
			for(int i=0; i<b-x/2; i++) cout<<'1';
			cout<<'\n';
		}
	}
	else{
		for(int i=0; i<x/2; i++){
			cout<<"01";
		}
		for(int i=0; i<a-x/2; i++) cout<<'0';
		for(int i=0; i<b-x/2; i++) cout<<'1';
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	//cin>>t;
	t=1;
	while(t--)
		solve();
	return 0;
}