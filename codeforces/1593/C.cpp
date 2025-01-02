#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[500001];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		int m=n,j=k;
		for(int i=1;i<=k;i++) cin>>a[i];
		sort(a+1,a+k+1);
		while(m>0){
			m-=(n-a[j]),j--;
		}
		cout<<k-j-1<<endl;
	}
}