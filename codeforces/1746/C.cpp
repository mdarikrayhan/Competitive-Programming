#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],b[200001];
int main()
{
	cin>>t;
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];b[a[i]]=i+1;}
	for(int i=1;i<=n;i++)cout<<min(b[i],n)<<" ";
	cout<<"\n";
}
}