#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cout<<min(m,n/k)-(m-min(m,n/k)+k-2)/(k-1)<<endl;
	}
}