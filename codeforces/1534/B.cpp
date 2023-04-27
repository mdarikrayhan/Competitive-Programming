#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
	int t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		vector<lli>a(n+2);
		for(int i=1; i<=n; i++) cin>>a[i];
		lli mx=0;
		for(int i=1; i<=n+1; i++){
			mx+=abs(a[i]-a[i-1]);
			mx-=max(a[i]-max(a[i-1], a[i+1]), 0LL);
		}
		cout<<mx<<endl;
	}
}