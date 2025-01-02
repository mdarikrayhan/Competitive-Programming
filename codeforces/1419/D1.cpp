#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
cout<<(n-1)/2<<endl;int j=n/2,k=0;
for(int i=0;i<n;i++)
	if(i%2==0)
		cout<<a[j++]<<" ";
	else
		cout<<a[k++]<<" ";
return 0;}