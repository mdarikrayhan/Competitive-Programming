#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vin(x) for(auto&__unnamed__var__:x)cin>>__unnamed__var__;
#define vrin(x,n) x.resize(n);for(auto&__unnamed__var__:x)cin>>__unnamed__var__;
#define vout(x) for(auto&__unnamed__var__:x)cout<<__unnamed__var__<<" ";cout<<"\n";

void cyn(bool state, string y="YES", string n="NO"){
	cout<<(state?y:n)<<"\n";
}

LL divceil(LL numerator, LL denominator){
	return numerator>=0?(numerator-1)/denominator + 1:numerator/denominator;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		bool vis[101]={};
		int ans=0,x[n];
		for(int i=0;i<n;++i){
			cin>>x[i];
			for(int j=0;j<i;++j){
				if(!vis[abs(x[i]-x[j])]++){
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
