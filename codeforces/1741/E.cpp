// LUOGU_RID: 102711523
#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		map<int,bool> f;
		f[0]=1;
		for(int i=1;i<=n;i++){
			cin>>x;
			f[i+x]|=f[i-1];
			f[i]|=f[i-x-1];
		}
		cout<<(f[n]?"YES\n":"NO\n");
	}
}