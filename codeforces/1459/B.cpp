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
	if(n%2==0){
		ll sum = 0;
		while(n > 0){
			sum += 2*n;
			n -= 4;
		}
		if(n == 0) sum++;
		cout<<sum<<"\n";
	}
	else{
		ll sum = 0;
		while(n > 0){
			sum += 4*n;
			n -= 4;
		}
		cout<<sum<<"\n";
	}
	
	
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	
	return 0;
}
