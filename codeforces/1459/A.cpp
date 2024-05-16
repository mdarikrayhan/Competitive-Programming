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
	string r,b;
	cin>>r>>b;
	int rc = 0;
	int bc = 0;
	for(int i=0;i<n;i++){
		if(r[i] > b[i]) rc++;
		if(r[i] < b[i]) bc++;
	}
	debug() << imie(rc) imie(bc);
	if(rc > bc) cout<<"RED"<<"\n";
	else if(rc < bc) cout<<"BLUE"<<"\n";
	else cout<<"EQUAL"<<"\n";
	
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
