#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define len(v) (int)v.size() 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef Raptor
#include "debug.h"
#else
#define debug(...) 1
#define imie(...) 1;
#endif

void solve(){
	int n; cin>>n;
	int cur = 0;
	vector<vector<int>> a(n,vector<int> (n));
	for(int i=0;i<n;i+=2){
		for(int j=0;j<n;j+=2){
			a[i][j] = cur;
			a[i][j+1] = cur + 1;
			a[i+1][j] = cur + 2;
			a[i+1][j+1] = cur + 3; 
			cur += 4;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	
	return 0;
}
