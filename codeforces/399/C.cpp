#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a,b;
	cin>>a>>b;
	if(a==0) {
		cout<<-(b*b)<<endl;
		for(int i=1;i<=b;i++) cout<<'x';
		cout<<endl;
	}
	else if(b==0) {
		cout<<a*a<<endl;
		for(int i=1;i<=a;i++) cout<<'o';
		cout<<endl;
	}
	else {
		int ans=-1e18,maxi;
		for(int i=1;i<=min(a,b);i++) {
			int tmp=i-1+(a-i+1)*(a-i+1);
			tmp-=(b/(i+1))*(b/(i+1))*(i+1)+(2*(b/(i+1))+1)*(b%(i+1));
			if(tmp>ans) ans=tmp,maxi=i;
		}
		cout<<ans<<endl;
		for(int i=1;i<=maxi;i++) {
			for(int j=1;j<=b/(maxi+1)+(i<=b%(maxi+1));j++)
				cout<<'x';
			if(i==1) {
				for(int j=1;j<=a-maxi+1;j++)
					cout<<'o';
			}
			else cout<<'o';
		}
		for(int j=1;j<=b/(maxi+1);j++)
			cout<<'x';
		cout<<endl;
	}
	return 0;
}