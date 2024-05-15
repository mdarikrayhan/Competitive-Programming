#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll s=0;
	int n,c=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	n++;
	for(int i=1;i<=5;i++){
		if((s+i)%n!=1){
			c++;
		}
	}
	cout<<c<<"\n";
}