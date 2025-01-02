// LUOGU_RID: 154497121
#include<bits/stdc++.h>
using namespace std;
long long t,n,l,r;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		if(n<l){
			cout<<"No"<<endl;
			continue;
		}
		if(n>=((n-1)/r+1)*l&&n<=(n/l)*r){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}