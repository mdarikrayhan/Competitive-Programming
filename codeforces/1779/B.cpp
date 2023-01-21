#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;cin>>T;while(T--){
		int n;cin>>n;
		if(n==2)puts("YES\n1 -1");
		else if(n==3)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)
				cout<<(i&1?-1:1)*(n-1-(i&1))/2<<' ';
			cout<<'\n';
		}
	}
}