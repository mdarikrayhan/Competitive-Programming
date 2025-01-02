#include<bits/stdc++.h>
using namespace std;const int N=1e2+7;int T_T,n,m,i,j,x[N],y[N],flag;
int main(){
	for(cin>>T_T;T_T--;){
		for(cin>>n>>m,flag=0,i=1;i<=n;++i)cin>>x[i]>>y[i];
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j)if(j!=i&&abs(x[i]-x[j])+abs(y[i]-y[j])>m)break;
			if(j==n+1)flag=1;
		}
		cout<<(flag?1:-1)<<endl;
	}
} 