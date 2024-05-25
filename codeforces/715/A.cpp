// LUOGU_RID: 155924834
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;m=2;cout<<2<<'\n';
	for(int i=2;i<=n;i++){
		cout<<i*(i+1)*(i+1)-i+1<<'\n';
	}
	return 0;
}