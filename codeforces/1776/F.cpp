#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,u[1<<11],v[1<<11],d[1<<6];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) d[i]=0;
	for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        d[u[i]]++;
        d[v[i]]++;
	}
	if(m==n*(n-1)/2){
		cout<<3<<'\n';
		for(int i=1;i<=m;i++) printf("%d%c",((u[i]==1||v[i]==1)|((u[i]==2||v[i]==2)<<1))%3+1," \n"[i==m]);
	}
	else{
		cout<<2<<'\n';
		int p=1;
		while(d[p]==n-1) p++;
		for(int i=1;i<=m;i++) printf("%d%c",(u[i]==p||v[i]==p)+1," \n"[i==m]);
	}
}
int main(){
	int t;cin>>t;
    while(t--) solve();
	return 0;
}
