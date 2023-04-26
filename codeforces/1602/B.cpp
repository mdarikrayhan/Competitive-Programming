#import<bits/stdc++.h>
using namespace std;
const int N = 2001;
int t,n,q,k,x,a[N][N],s[N];
main(){
    	for(cin >> t;t--;){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[0][i];
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++) s[j]=0;
			for(int j=0;j<n;j++) s[a[i][j]]++;
			for(int j=0;j<n;j++) a[i+1][j]=s[a[i][j]];
		}
		for(cin >> q;q--;){
			cin>>x>>k;
			cout<<a[min(k,n)][x-1]<<endl;
		}
	}
}