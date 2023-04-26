#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int& x:a){
			cin>>x;
		}
		int g=0;
		for(int i=1;i<n;i++) g = __gcd(abs(a[i]-a[i-1]), g);
		cout<<(g==0?-1:g)<<endl; 
	}
}