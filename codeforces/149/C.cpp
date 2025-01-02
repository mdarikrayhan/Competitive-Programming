#include <bits/stdc++.h>
using namespace std;
int i,n;
pair<int,int>a[100005];
main(){
	cin>>n;
	for(i=1;i<=n;i++){cin>>a[i].first;a[i].second=i;}cout<<n/2+n%2<<endl;sort(a,a+n);
	for(i=1;i<=n;i+=2){cout<<a[i].second<<" ";}cout<<endl<<n/2<<endl;
	for(i=2;i<=n;i+=2){cout<<a[i].second<<" ";}}