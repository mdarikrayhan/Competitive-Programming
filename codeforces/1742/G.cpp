#include<bits/stdc++.h>
using namespace std;
int n,t,k,a[200005];
bool cmp(int x,int y){
	return (x|k)>(y|k);
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		k=0;
		for(int i=0;i<min(n,32);i++){
			sort(a+i,a+n,cmp);
			k|=a[i];
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}