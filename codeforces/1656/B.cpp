#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		map<int,int> m;
		int n,k,ans=0;
		cin>>n>>k;
		while(n--){
			int x;
			cin>>x;
			if(m[x+k]||m[x-k]) ans=1; 
			m[x]=1;
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}