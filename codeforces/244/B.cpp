#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
ll n;
void dfs(ll x,ll y,ll ans){
	s.insert(ans);
	ll fx=ans*10+x;
	ll fy=ans*10+y;
	if(fx&&fx<=n)	dfs(x,y,fx);
	if(fy&&fy<=n)	dfs(x,y,fy);
}
int main(){
	ll x,y,k;
	cin>>n;
	s.clear();
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			dfs(i,j,0);
	cout<<s.size()-1<<endl;
}
