#include<cstdio>
#include<iostream>
using namespace std;
const int o=1010;
int T,n,p[o],d,u,q[o];
int main(){
	for(cin>>T;T--;cout<<endl,cin>>n){
		cin>>n;
		cout<<"+ "<<n+1<<endl<<"+ "<<n+2<<endl;
		cin>>d>>u;d=0;u=1;
		for(int i=2,t;i<=n;++i){
			cout<<"? 1 "<<i<<endl;
			cin>>t;
			if(t>d) d=t,u=i;
		}
		p[u]=1;
		for(int i=1;i<=n;++i) if(u^i) cout<<"? "<<u<<" "<<i<<endl,cin>>p[i],++p[i];
		for(int l=1,r=n,cnt=0;l<=r;++l,--r) q[++cnt]=l,q[++cnt]=r;
		cout<<"! ";
		for(int i=1;i<=n;++i) cout<<q[p[i]]<<" ";
		for(int i=1;i<=n;++i) cout<<q[n-p[i]+1]<<" ";
	}
	return 0;
}
