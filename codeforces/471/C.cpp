#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,cnt=0;
	cin>>n;
	for(int i=1;i*(3*i+1)/2<=n;i++)
		if((n+i)%3==0) cnt++;
	cout<<cnt;
	return 0;
}
