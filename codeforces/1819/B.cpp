#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;

bool solve(multiset<pair<int,int>> a ,multiset<pair<int,int>> b,int n,int m){
	while(!a.empty()){
		auto [ax,ay]=*a.rbegin();
		auto [by,bx]=*b.rbegin();
		if(ax==n){
			m-=ay;
			a.erase(a.find({ax,ay}));
			b.erase(b.find({ay,ax}));
		}
		else if(by==m){
			n-=bx;
			a.erase(a.find({bx,by}));
			b.erase(b.find({by,bx}));
		}
		else return 0;
	}
	return 1;
}

signed main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		int sz=0;
		multiset<pair<int,int>> a,b;
		set<pair<int,int>> c;
		for(int i=1;i<=n;i++) {
			int aa,bb;
			cin>>aa>>bb;
			a.insert({aa,bb});
			b.insert({bb,aa});
			sz+=aa*bb;
		}
		int N=a.rbegin()->first,M=sz/N;
		if(N*M==sz){
			if(solve(a,b,N,M)) c.insert({N,M});
		}
		M=b.rbegin()->first,N=sz/M;
		if(N*M==sz){
			if(solve(a,b,N,M)) c.insert({N,M});
		}
		cout<<c.size()<<endl;
		for(auto [x,y]:c) cout<<x<<" "<<y<<endl;
	}
	return 0;
} 