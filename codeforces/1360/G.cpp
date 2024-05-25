// LUOGU_RID: 159875362
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,b,T;
signed main(){
	cin>>T;
		while(T--){
			cin>>n>>m>>a>>b;
			if(n*a!=m*b){
				cout<<"NO"<<endl;
				continue;
			}
			cout<<"YES"<<endl;
			int p=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int t=j-p;
					if(t>0&&t<=a||t+m<=a) cout<<1;
					else cout<<0;
				}
				cout<<endl;
				p=(p+a)%m;
			}
	}
	return 0;
}
