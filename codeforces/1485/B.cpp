#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q,k;
	cin>>n>>q>>k;
	int arr[n+5];
	for(int i=1;i<=n;i++)cin>>arr[i];
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<arr[r]+k+1-arr[l]-(r-l+1)*2<<endl;}}