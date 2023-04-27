#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for (int T=0;T<t;T++){
		int n,u,v,prev,N,ans=-1;
		cin>>n>>u>>v>>prev;
		for (int i=0;i<n-1;i++){
			cin>>N;
			if (abs(prev-N)>1) ans=0;
			if (abs(prev-N)==1 and ans==-1) ans=min(u,v);
			prev=N;
		}
		if (ans==-1) ans=v+min(u,v);
		cout<<ans<<'\n';
	}
}